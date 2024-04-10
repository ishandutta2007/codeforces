#include <string>
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 


template<typename T, typename U> struct seg_tree_lazy {
    int S, H;
 
    T zero;
    std::vector<T> value;
 
    U noop;
    std::vector<bool> dirty;
    std::vector<U> prop;
 
    seg_tree_lazy<T, U>(int _S, T _zero = T(), U _noop = U());
    
    void apply(int i, U &update);
    void rebuild(int i);
    void propagate(int i);
    void upd(int i, int j, U update);
    T query(int i, int j);
};

using namespace std;


void re(int& x);
void re(long long& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);
template<class T> void re(std::vector<T>& a);


void pr(int x);
void pr(long long x);


void pr(const char *x);

template<class T, class... Ts> void pr(const T& t, const Ts&... ts);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

void pc();
template<class T, class... Ts> void pc(const T& t, const Ts&... ts);

#define dbg(x...) pr("[",#x,"] = ["), pc(x);


#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)


struct node {
    int posneg_left;
    int neg_left;
    int pos_right;
    int posneg_right;
    int max_hill;
    int size;

    node operator+(node ot) {
        node ret;

        ret.neg_left = neg_left;
        if (neg_left == size) ret.neg_left += ot.neg_left;

        ret.pos_right = ot.pos_right;
        if (ot.pos_right == ot.size) ret.pos_right += pos_right;

        ret.posneg_left = posneg_left;
        if (posneg_left == size) ret.posneg_left += ot.neg_left;
        if (pos_right == size) ret.posneg_left = size + ot.posneg_left;

        ret.posneg_right = ot.posneg_right;
        if (ot.posneg_right == ot.size) ret.posneg_right += pos_right;
        if (ot.neg_left == ot.size) ret.posneg_right = ot.size + posneg_right;

        ret.max_hill = max(pos_right + ot.posneg_left, 
                       max(posneg_right + ot.neg_left, 
                       max(max_hill, ot.max_hill)));

        ret.size = size + ot.size;
        return ret;
    }
};

struct update {
    long long val;
    node operator() (node n) {
        if (val == -1000000000000LL) return n;

        n.neg_left = (val < 0);
        n.pos_right = (val > 0);
        n.posneg_left = (val != 0);
        n.posneg_right = (val != 0);
        n.max_hill = (val != 0);
        n.size = 1;
        return n;
    }

    update operator+(update ot) { return ot; }
};

update noop = {-1000000000000LL};

int n, q;
vector<long long> a;
void solve()
{
    re(n);
    a.resize(n); re(a);

    for (int i = 0; i < n-1; i++) a[i] = a[i+1] - a[i];
    seg_tree_lazy<node, update> st(n-1, node(), noop);

    for (int i = 0; i < n-1; i++) st.upd(i,i, {a[i]} );

    re(q);
    REP(i,q) {
        int l, r, d;
        re(l,r,d); l-=2; r--;
        if (l >= 0) {
            a[l] += d; 
            //dbg(l, a[l]); 
            st.upd(l,l, {a[l]});
        }
        if (r < n-1) {
            a[r] -= d; 
            //dbg(r, a[r]); 
            st.upd(r,r, {a[r]});
        }

        node nd = st.query(2,3);
        //dbg(nd.max_hill,nd.neg_left,nd.posneg_left);
        ps(st.query(0,n-2).max_hill + 1); 
    }
}


int main() {


    solve();
}


template<typename T, typename U>
seg_tree_lazy<T, U>::seg_tree_lazy(int _S, T _zero, U _noop) {
        zero = _zero, noop = _noop;
        for (S = 1, H = 1; S < _S; ) S *= 2, H++;
 
        value.resize(2*S, zero);
        dirty.resize(2*S, false);
        prop.resize(2*S, noop);
    }

 
  template<typename T, typename U>
    void seg_tree_lazy<T, U>::apply(int i, U &update) {
        value[i] = update(value[i]);
        if(i < S) {
            prop[i] = prop[i] + update;
            dirty[i] = true;
        }
    }
 
  template<typename T, typename U>
    void seg_tree_lazy<T, U>::rebuild(int i) {
        for (int l = i/2; l; l /= 2) {
            T combined = value[2*l] + value[2*l+1];
            value[l] = prop[l](combined);
        }
    }
 
  template<typename T, typename U>
    void seg_tree_lazy<T, U>::propagate(int i) {
        for (int h = H; h > 0; h--) {
            int l = i >> h;
 
            if (dirty[l]) {
                apply(2*l, prop[l]);
                apply(2*l+1, prop[l]);
 
                prop[l] = noop;
                dirty[l] = false;
            }
        }
    }
 
  template<typename T, typename U>
    void seg_tree_lazy<T, U>::upd(int i, int j, U update) {
        i += S, j += S;
        propagate(i), propagate(j);
 
        for (int l = i, r = j; l <= r; l /= 2, r /= 2) {
            if((l&1) == 1) apply(l++, update);
            if((r&1) == 0) apply(r--, update);
        }
 
        rebuild(i), rebuild(j);
    }
 
  template<typename T, typename U>
    T seg_tree_lazy<T, U>::query(int i, int j){
        i += S, j += S;
        propagate(i), propagate(j);
 
        T res_left = zero, res_right = zero;
        for(; i <= j; i /= 2, j /= 2){
            if((i&1) == 1) res_left = res_left + value[i++];
            if((j&1) == 0) res_right = value[j--] + res_right;
        }
        return res_left + res_right;
    }


void re(int& x) { scanf("%d", &x); }
void re(long long& x) { scanf("%lld", &x); }


template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}
template<class T> void re(std::vector<T>& a) { for (int i = 0; i < a.size(); i++) re(a[i]); }


void pr(int x) { printf("%d", x); }
void pr(long long x) { printf("%lld", x); }


void pr(const char *x) { printf("%s", x); }

template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
    pr(t); pr(ts...); 
}

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}

void pc() { pr("]\n"); }
template<class T, class... Ts> void pc(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); 
}