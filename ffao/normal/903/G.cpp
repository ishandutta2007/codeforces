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


typedef pair<int, int> pii;

#define all(v) (v).begin(), (v).end()
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)


int n, m, q;
vector<int> A, B;

vector< pair<pii, int> > edges;
vector< long long > opt;


void pr() {}
void pr(int x) { printf("%d", x); }
void pr(long long x) { printf("%lld", x); }
void pr(double x) { printf("%.15f", x); }
void pr(char x) { printf("%c", x); }
void pr(const char *x) { printf("%s", x); }
void pr(std::string x) { printf("%s", x.c_str()); }
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
#define dbg(x...) pr("[",#x,"] = ["), pc(x);

struct node {
    long long bst;
    long long s;

    node() {bst = 1000000000000000000LL; s = 0;}
    node(long long bst, long long s) : bst(bst), s(s) {}

    node operator+(node ot) {
        ot.bst = min(bst + ot.s, ot.bst);
        ot.s += s;
        return ot;
    }
};

struct update {
    long long diff;

    update() : diff(0) {}
    update(long long diff) : diff(diff) {}

    node operator()(node n) {
        n.bst += diff;
        n.s += diff;
        return n;
    }

    update operator+(update ot) {
        return {diff+ot.diff};
    }
};

void solve()
{
    re(n,m,q);
    A.resize(n); B.resize(n); opt.resize(n);

    REP(i,n-1) re(A[i], B[i+1]);

    vector<node> leaves(n);
    REP(i,n) leaves[i] = {B[i], 0};
    seg_tree_lazy<node, update> st(n);
    st.set_leaves(leaves);

    edges.resize(m);
    REP(i,m) {
        re(edges[i].first.first, edges[i].first.second, edges[i].second); 
        edges[i].first.first--;
        edges[i].first.second--;
    }

    sort(all(edges));
    int cur = 0;
    
    REP(i,n) {
        while (cur < edges.size() && edges[cur].first.first <= i) {
            st.upd(edges[cur].first.second, edges[cur].first.second, {edges[cur].second});
            cur++;
        }

        node ret = st.query(0, n-1);
        opt[i] = ret.bst;
    }

    set< pair<long long, int> > flows;
    REP(i,n) {
        flows.insert({A[i] + opt[i], i});
    }

    ps(flows.begin()->first);
    REP(i,q) {
        int v, w;
        re(v,w); v--;

        flows.erase({A[v] + opt[v], v});
        A[v] = w;
        flows.insert({A[v] + opt[v], v});

        ps(flows.begin()->first);
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