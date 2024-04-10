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
    void set_leaves(std::vector<T> &leaves);
    void apply(int i, U &update);
    void rebuild(int i);
    void propagate(int i);
    void upd(int i, int j, U update);
    T query(int i, int j);
};

using namespace std;


void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)


typedef long long H;
static const H M = INT_MAX;
static H C; // initialized below

struct K {
	H x; K(H x=0) : x(x) {}
	K operator+(K o) { H y = x + o.x; return y - (y >= M) * M; }
	K operator*(K o) { return x*o.x % M; }
	
};

vector<K> pw, pwp;

int n,m,k;
char s[110000];

struct node {
    int size;
    K ha;

    node operator+(node ot) {
        ot.ha = ha * pw[ot.size] + ot.ha;
        ot.size += size;
        return ot;
    }
};

struct update {
    int to;

    node operator()(node n) {
        if (!to) return n;

        n.ha = pwp[n.size-1] * to;
        return n;
    }

    update operator+(update ot) {
        return ot;
    }
};

#include <sys/time.h>
void solve()
{
    timeval tp;
	gettimeofday(&tp, 0);
	C = tp.tv_usec;

    re(n,m,k);
    pw.resize(n+1);
    pwp.resize(n+1);
    pw[0] = 1;
    pwp[0] = 1;

    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i-1] * C;
        pwp[i] = pwp[i-1] * C + 1;
    }
    
    scanf("%s", s);

    seg_tree_lazy<node, update> st(n);
    vector<node> leaves;
    REP(i,n) leaves.push_back({1, s[i]-'0'+1});
    st.set_leaves(leaves);

    REP(q,m+k) {
        int op, l, r, c;
        re(op,l,r,c); l--; r--;

        if (op == 1) {
            c++;
            st.upd(l,r,{c});
        }
        if (op == 2) {
            if (r-c < l) ps("YES");
            else ps(st.query(l, r-c).ha.x == st.query(l+c,r).ha.x ? "YES" : "NO");
        }
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
    void seg_tree_lazy<T, U>::set_leaves(vector<T> &leaves) {
        copy(leaves.begin(), leaves.end(), value.begin() + S);
 
        for (int i = S - 1; i > 0; i--)
            value[i] = value[2 * i] + value[2 * i + 1];
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


template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}


void pr(const char *x) { printf("%s", x); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}