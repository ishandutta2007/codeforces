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


using namespace std;


#include <tuple>


void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);


void pr(int x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


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


#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)


struct node {
    int len;
    int trans[10][10];
    int L, R;

    node() {
        rep(i,10) rep(j,10) trans[i][j] = 0;
        len = 0;
    }

    node operator+(node ot) {
        rep(i,10) rep(j,10) {
            ot.trans[i][j] += trans[i][j];
        }
        
        if (len != 0 && ot.len != 0) {
            ot.trans[R][ot.L]++;
        }

        if (len != 0) ot.L = L;
        if (ot.len == 0) ot.R = R;
        ot.len += len;

        return ot;
    }
};

struct update {
    int t;

    update() : t(-1) {}
    node operator()(node n) {
        if (t == -1) return n;

        rep(i,10) rep(j,10) n.trans[i][j] = 0;
        n.trans[t][t] = n.len-1;
        n.L = n.R = t;
        return n;
    }
    update operator+(update u) {return u;}
};

int n,m,k;
char s[210000];
char p[110];

void solve()
{
    re(n,m,k);
    seg_tree_lazy<node, update> seg(n);

    scanf("%s", s);
    vector<node> leaves(n);
    for (int i = 0; i < n; i++) {
        int t = s[i]-'a';
        leaves[i].L = leaves[i].R = t;
        leaves[i].len = 1;
    }
    seg.set_leaves(leaves);

    for (; m; m--) {
        int op; re(op);

        if (op == 1) {
            int l,r; char c; int t;
            scanf("%d %d %c", &l, &r, &c); l--; r--; t = c-'a';
            update u; u.t = t;
            seg.upd(l,r,u);
        }

        else {
            scanf("%s", p);

            node nd = seg.query(0, n-1);
            int ans = 0;
            for (int i = 0; i < k; i++) {
                for (int j = i; j < k; j++) {
                    int ti = p[i]-'a', tj = p[j]-'a';
                    ans += nd.trans[tj][ti];
                }
            }
            ps(ans+1);
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


void pr(int x) { printf("%d", x); }


void pr(const char *x) { printf("%s", x); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}