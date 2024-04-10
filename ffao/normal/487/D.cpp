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

using namespace std;


#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)


char belts[110000][12];
int n,m,q;

void compute(int* to, int row) {
    for (int i = 0; i < m; i++) {
        if (belts[row][i] == '>') {
            for (int j = i; j < m; j++) {
                if (belts[row][j] == '<') {
                    to[i] = 10;
                    break;
                }
                else if (belts[row][j] == '^') {
                    to[i] = j;
                    break;
                }
                else if (j == m-1) {
                    to[i] = 12;
                    break;
                }
            }
        }

        else if (belts[row][i] == '<') {
            if (i == 0) to[i] = 11;
            else to[i] = to[i-1];
        }

        else to[i] = i;
    }
}

struct node {
    int loc;
    int to[13];

    node() { rep(i,13) to[i]=i; }
    
    node operator+(node ot) {
        node ret;
        for (int i = 0; i < 13; i++) {
            ret.to[i] = ot.to[to[i]];
        }
        return ret;
    }
};

struct update {
    bool d;
    update() : d(false) {}
    node operator()(node ot) {
        if (!d) return ot;

        node ret;
        ret.loc = ot.loc;
        compute(ret.to, ret.loc);
        return ret;
    }

    update operator+(update u) {
        u.d |= d;
        return u;
    }
};


void solve()
{
    re(n,m,q);
    for (int i = 0; i < n; i++) scanf("%s", belts[i]);

    vector<node> leaves(n);
    for (int i = 0; i < n; i++) {
        leaves[i].loc = n-i-1;
        compute(leaves[i].to, n-i-1);
    }  

    seg_tree_lazy<node, update> seg(n);
    seg.set_leaves(leaves);

    rep(qq,q) {
        char op;
        scanf(" %c", &op);

        if (op == 'A') {
            int x, y;
            re(x,y); x--; y--;
            node to = seg.query(n-x-1, n-1);

            //printf("toto %d\n", to.to[y]);
            
            if (to.to[y] == 10) {
                ps(-1,-1);
            }
            else if (to.to[y] < 10) {
                ps(0, to.to[y]+1);
            }
            else {
                int st = 0, ed = x;
                while (st < ed) {
                    int md = (st+ed+1)/2;
                    node to2 = seg.query(n-x-1, n-md-1);
                    if (to2.to[y] > 10) st = md;
                    else ed = md-1;
                }

                if (to.to[y] == 11) ps(st+1, 0);
                else ps(st+1, m+1);
            }
        }

        else {
            int x, y; char c;
            scanf("%d %d %c", &x, &y, &c); x--; y--;
            belts[x][y] = c;
            update u; u.d = 1;
            seg.upd(n-x-1, n-x-1, u);
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