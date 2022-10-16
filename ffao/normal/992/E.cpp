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


int v[210000];
set<int> ss[33];

int clz(int x) {
    if (x == 0) return 32;
    return __builtin_clz(x);
}

struct node {
    long long s = 0;
    node(long long int _s = 0) : s(_s) {}

    node operator+(node ot) {
        return node(s + ot.s);
    }
};

struct upd {
    int v;
    upd(int _v = 0) : v(_v) {}
    
    node operator()(node a) {
        a.s += v;
        return a;
    }

    upd operator+(upd ot) {
        return upd(v + ot.v);
    } 
};

int n, q;

void solve()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);

    vector<node> leaves(n);
    for (int i = 0; i < n; i++) {
        leaves[i].s = v[i];
        ss[clz(v[i])].insert(i);
    }

    seg_tree_lazy<node, upd> tree(n);
    tree.set_leaves(leaves);

    for (int i = 0; i < q; i++) {
        int p, val;
        scanf("%d %d", &p, &val); p--;

        int diff = val - v[p];
        ss[clz(v[p])].erase(p);
        tree.upd(p, p, diff);
        v[p] = val;
        ss[clz(v[p])].insert(p);

        int f = -1;
        for (int i = 0; i < 33 && f == -1; i++) {
            auto it = ss[i].begin();
            for (int j = 0; j < 2; j++) {
                if (it == ss[i].end()) break;

                //printf("testing %d: %lld\n", *it, tree.query(0, *it).s);
                if (tree.query(0, *it).s == 2*(v[*it])) f = *it + 1;
                it++;
            }
        }

        printf("%d\n", f != -1 ? f : -1);
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