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
#include <array>
#include <functional>
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

#ifdef LOCAL
#define debug(x) std::cerr << #x << ": " << x << '\n';
#else
#define debug(x)
#endif

#define FORI(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR(i,a) FORI(i,0,a)
#define ROFI(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ROF(i,a) ROFI(i,0,a)
#define rep(a) FOR(_,a)
#define each(a,x) for (auto& a: x)
#define FORN(i, n) FORI(i, 1, n + 1)

using vi = vector<int>;
template <typename T>
std::istream& operator >>(std::istream& input, std::pair <T, T> & data)
{
    input >> data.x >> data.y;
    return input;
}
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
std::ostream& operator <<(std::ostream& output, const __int128 &x)
{
    __int128 n = x;
    if (n == 0) {
        output << "0";
        return output;
    }
    if (n < 0) {
        n = -n;
        output << "-";
    }
    string s;
    while (n) {
        s += '0' + (n%10);
        n /= 10;
    }
    reverse(all(s));
    cout << s;
    return output;
}
ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
ll math_mod(ll a, ll b) { return a - b * div_down(a, b); }
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
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
int Bit(int mask, int bit) { return (mask >> bit) & 1; }

struct ST {

const int INF = 1e9+7; // check INF!

int n; // 0...n - 1
vector <int> mn, mx, prop, prop_val, sum;

ST (int n_) {
    n = n_;
    mn.assign(n << 2, 0);
    mx.assign(n << 2, 0);
    sum.assign(n << 2, 0);
    prop.assign(n << 2, 0);
    prop_val.assign(n << 2, INF);
}
void gap(int v, int l, int r, int x) {
    mn[v] += x;
    mx[v] += x;
    sum[v] += (r - l + 1) * x;
    if (prop_val[v] != INF)
        prop_val[v] += x;
    else
        prop[v] += x;
}   
void gap_val(int v, int l, int r, int x) {
    mn[v] = mx[v] = x;
    sum[v] = (r - l + 1) * x;
    prop[v] = 0;
    prop_val[v] = x;
}
void push(int v, int l, int r) {
    int m = (l + r) >> 1;
    if (prop_val[v] != INF) {
        gap_val(v * 2 + 1, l, m, prop_val[v]);
        gap_val(v * 2 + 2, m + 1, r, prop_val[v]);
        prop_val[v] = INF;
    }
    else if (prop[v]) {
        gap(v * 2 + 1, l, m, prop[v]);
        gap(v * 2 + 2, m + 1, r, prop[v]);
        prop[v] = 0;
    }   
}
void relax(int v) {
    mn[v] = min(mn[v * 2 + 1], mn[v * 2 + 2]);
    mx[v] = max(mx[v * 2 + 1], mx[v * 2 + 2]);
    sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
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
void setval(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl) 
        return;
    if (l <= tl && tr <= r) {
        gap_val(v, tl, tr, x);
        return;
    }
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    setval(v * 2 + 1, tl, tm, l, r, x);
    setval(v * 2 + 2, tm + 1, tr, l, r, x);
    relax(v);
}
int getmin(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl)
        return INF;
    if (l <= tl && tr <= r)
        return mn[v];
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    return min(getmin(v * 2 + 1, tl, tm, l, r), getmin(v * 2 + 2, tm + 1, tr, l, r));
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
int getsum(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl)
        return 0;
    if (l <= tl && tr <= r)
        return sum[v];
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    return getsum(v * 2 + 1, tl, tm, l, r) + getsum(v * 2 + 2, tm + 1, tr, l, r);
}   
void setpoint(int v, int tl, int tr, int i, int x) {
    if (tl == tr) {
        mn[v] = mx[v] = sum[v] = x;
        return;
    }   
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    if (i <= tm)
        setpoint(v * 2 + 1, tl, tm, i, x);
    else
        setpoint(v * 2 + 2, tm + 1, tr, i, x);
    relax(v);
}   
void build(int v, int tl, int tr, int *a) {
    if (tl == tr) {
        mn[v] = mx[v] = sum[v] = a[tl];
        return;
    }   
    int tm = (tl + tr) >> 1;
    build(v * 2 + 1, tl, tm, a);
    build(v * 2 + 2, tm + 1, tr, a);
    relax(v);
}   
void build(int v, int tl, int tr, vi &a) {
    if (tl == tr) {
        mn[v] = mx[v] = sum[v] = a[tl];
        return;
    }   
    int tm = (tl + tr) >> 1;
    build(v * 2 + 1, tl, tm, a);
    build(v * 2 + 2, tm + 1, tr, a);
    relax(v);    
}
void clear() {
    mn.assign(n << 2, 0);
    mx.assign(n << 2, 0);
    sum.assign(n << 2, 0);
    prop.assign(n << 2, 0);
    prop_val.assign(n << 2, INF);
}   
void add(int l, int r, int x) {
    add(0, 0, n - 1, l, r, x);
}   
int getmin(int l, int r) {
    return getmin(0, 0, n - 1, l, r);
}   
int getmax(int l, int r) {
    return getmax(0, 0, n - 1, l, r);
}   
int getsum(int l, int r) {
    return getsum(0, 0, n - 1, l, r);
}   
void setpoint(int i, int x) {
    setpoint(0, 0, n - 1, i, x);
}   
void setval(int l, int r, int x) {
    setval(0, 0, n - 1, l, r, x);
}
void build(int *a) {
    build(0, 0, n - 1, a);
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

int get_left_leq(int v, int tl, int tr, int l, int w) {
    if (tr < l || mn[v] > w)
        return -1;
    if (tl == tr)
        return tl;
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    int t = get_left_leq(v * 2 + 1, tl, tm, l, w);
    if (t != -1)
        return t;
    else
        return get_left_leq(v * 2 + 2, tm + 1, tr, l, w);                                    
}   
int get_left_leq(int l, int w) {
    return get_left_leq(0, 0, n - 1, l, w);
}

};  

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    vi a(n + 1), b(n + 1), go(n + 1, -1);
    V <vi> inv(n + 1);

    FORN (i, n) {
        cin >> a[i];
    }

    ST tree(n + 1);
    tree.setpoint(0, n + 1);
    FORN (i, n) {
        tree.setpoint(i, i - a[i]);
    }

    FORN (i, n) {
        cin >> b[i];
        inv[b[i] + i].app(i);
    }

    const int INF = 1e9+7;
    vi dist(n + 1, INF);

    inv[0].app(0);

    queue <int> q;
    q.push(0);
    dist[0] = 0;
    while (q.size()) {
        int u = q.front(); q.pop();

        //debug(mp(u, dist[u]));

        each (slipped_from, inv[u]) {
            while (1) {
                int v = tree.get_left_leq(slipped_from, slipped_from);
                if (v == -1) {
                    break;
                }
                if (ckmin(dist[v], dist[u] + 1)) {
                    go[v] = slipped_from;
                    q.push(v);
                }
                tree.setpoint(v, INF);
            }
        }
    }

    if (dist[n] == INF) {
        cout << -1 << endl;
        exit(0);
    }

    cout << dist[n] << endl;

    int cur = n;
    while (cur) {
        cur = go[cur];
        cout << cur << ' ';
        cur += b[cur];
    }
    cout << endl;
}