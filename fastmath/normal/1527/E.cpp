#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define x first
#define y second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cerr << #x << ": " << x << '\n';
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define FORN(i, n) for (int i = 1; i <= n; ++i)
#define pb push_back
#define trav(a, x) for (auto& a : x)
using vi = vector<int>;
template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& data)
{
    for (T& x : data)
        input >> x;
    return input;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const pair <T, T> & data)
{
    output << "(" << data.x << "," << data.y << ")";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data)
{
    for (const T& x : data)
        output << x << " ";
    return output;
}
ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
ll math_mod(ll a, ll b) { return a - b * div_down(a, b); }
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
tcT> void re(V<T>& x) { 
    trav(a, x)
        cin >> a;
}
tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
}
ll gcd(ll a, ll b) {
    while (b) {
        tie(a, b) = mp(b, a % b);
    }
    return a;
}

struct ST {

const int INF = 1e9+7; // check INF!

int n; // 0...n - 1
vector <int> mx, prop;

ST (int n_) {
    n = n_;
    mx.assign(n << 2, 0);
    prop.assign(n << 2, 0);
}
void gap(int v, int l, int r, int x) {
    mx[v] += x;
    prop[v] += x;
}   

void push(int v, int l, int r) {
    int m = (l + r) >> 1;
    if (prop[v]) {
        gap(v * 2 + 1, l, m, prop[v]);
        gap(v * 2 + 2, m + 1, r, prop[v]);
        prop[v] = 0;
    }   
}
void relax(int v) {
    mx[v] = max(mx[v * 2 + 1], mx[v * 2 + 2]);
}   
void add(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl)
        return;
    if (l <= tl && tr <= r) {
        gap(v, tl, tr, x);
        return;
    }   
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    add(v * 2 + 1, tl, tm, l, r, x);
    add(v * 2 + 2, tm + 1, tr, l, r, x);
    relax(v);                
}   
int getmax(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl)
        return -INF;
    if (l <= tl && tr <= r)
        return mx[v];
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    return max(getmax(v * 2 + 1, tl, tm, l, r), getmax(v * 2 + 2, tm + 1, tr, l, r));
}     
void build(int v, int tl, int tr, vi &a) {
    if (tl == tr) {
        mx[v] = a[tl];
        return;
    }   
    int tm = (tl + tr) >> 1;
    build(v * 2 + 1, tl, tm, a);
    build(v * 2 + 2, tm + 1, tr, a);
    relax(v);    
}  
void add(int l, int r, int x) {
    add(0, 0, n - 1, l, r, x);
}    
int getmax(int l, int r) {
    return getmax(0, 0, n - 1, l, r);
}     
void build(vi a) {
    assert(a.size() == n);
    build(0, 0, n - 1, a);
}

int get_left_moq(int v, int tl, int tr, int l, int w) {
    if (tr < l || mx[v] < w)
        return -1;
    if (tl == tr)
        return tl;
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    int t = get_left_moq(v * 2 + 1, tl, tm, l, w);
    if (t != -1)
        return t;
    else
        return get_left_moq(v * 2 + 2, tm + 1, tr, l, w);                                    
}   
int get_left_moq(int l, int w) {
    return get_left_moq(0, 0, n - 1, l, w);
}


};  

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, k;
    cin >> n >> k;
    vi a(n);
    cin >> a;
    int S = 0;
    V <vi> pos(n + 1);
    FOR (i, n) {
        pos[a[i]].app(i);
    }
    FORN (x, n) {
        if (pos[x].size()) {
            S += pos[x].back() - pos[x][0];
        }
    }

    V <vi> open(n + 1), close(n + 1);
    FORN (x, n) {
        int sz = pos[x].size();
        FOR (p, sz - 1) {
            int l = pos[x][p], r = pos[x][p + 1];
            open[l].app(r);
            close[r].app(l);
        }
    }    

    vi dp(n + 1);
    FOR (t, k - 1) {
        vi ndp(n + 1);
        ST tree(n + 1);
        tree.build(dp);
        for (int i = 0; i <= n; ++i) {
            if (i) {
                ndp[i] = tree.getmax(0, i - 1);
            }
            trav (r, open[i]) {
                //debug("open"); debug(mp(i, r));
                tree.add(0, i, r - i);
            }
            trav (l, close[i]) {
                //debug("close"); debug(mp(l, i));
                tree.add(0, l, l - i);
            }
        }
        dp = ndp;
    }
    int best = 0;
    trav (e, dp) {
        ckmax(best, e);
    }
    cout << S - best << endl;
}