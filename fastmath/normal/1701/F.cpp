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
#include <stack>
#include <memory>
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

int leftMoq(int v, int tl, int tr, int l, int w) {
    if (tr < l || mx[v] < w) {
        return -1;
    }
    if (tl == tr) {
        return tl;
    }
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    int t = leftMoq(v * 2 + 1, tl, tm, l, w);
    if (t != -1) {
        return t;
    }
    else {
        return leftMoq(v * 2 + 2, tm + 1, tr, l, w);                                    
    }
}   
int leftMoq(int l, int w) {
    return leftMoq(0, 0, n - 1, l, w);
}

int rightMoq(int v, int tl, int tr, int r, int w) {
    if (tl > r || mx[v] < w) {
        return -1;
    }
    if (tl == tr) {
        return tl;
    }
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    int t = rightMoq(v * 2 + 2, tm + 1, tr, r, w); 
    if (t != -1) {
        return t;
    }
    else {
        return rightMoq(v * 2 + 1, tl, tm, r, w);                                   
    }
}   
int rightMoq(int r, int w) {
    return rightMoq(0, 0, n - 1, r, w);
}


int leftLeq(int v, int tl, int tr, int l, int w) {
    if (tr < l || mn[v] > w)
        return -1;
    if (tl == tr)
        return tl;
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    int t = leftLeq(v * 2 + 1, tl, tm, l, w);
    if (t != -1) {
        return t;
    }
    else {
        return leftLeq(v * 2 + 2, tm + 1, tr, l, w);                                    
    }
}   
int leftLeq(int l, int w) {
    return leftLeq(0, 0, n - 1, l, w);
}

int rightLeq(int v, int tl, int tr, int r, int w) {
    if (tl > r || mn[v] > w) {
        return -1;
    }
    if (tl == tr) {
        return tl;
    }
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    int t = rightLeq(v * 2 + 2, tm + 1, tr, r, w); 
    if (t != -1) {
        return t;
    }
    else {
        return rightLeq(v * 2 + 1, tl, tm, r, w);                                   
    }
}   
int rightLeq(int r, int w) {
    return rightLeq(0, 0, n - 1, r, w);
}

};  

int comb(int n) {
    return n * (n - 1);
}


const int C = 2e5+7;

int p[C << 2], ri[C << 2], c[C << 2];

void gap(int v, int x) {
    p[v] += x;
    ri[v] += c[v] * x;
}

void push(int v) {
    gap(v * 2 + 1, p[v]);
    gap(v * 2 + 2, p[v]);
    p[v] = 0;
}

void relax(int v) {
    c[v] = c[v * 2 + 1] + c[v * 2 + 2];
    ri[v] = ri[v * 2 + 1] + ri[v * 2 + 2];
}

void addpos(int v, int l, int r, int ql, int qr, int x) {
    if (r < ql || qr < l) {
        return;
    }
    if (ql <= l && r <= qr) {
        gap(v, x);
        return;
    }
    int m = (l + r) / 2;
    push(v);
    addpos(v * 2 + 1, l, m, ql, qr, x);
    addpos(v * 2 + 2, m + 1, r, ql, qr, x);
    relax(v);
}

int getsumr(int v, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) {
        return 0;
    }
    if (ql <= l && r <= qr) {
        return ri[v];
    }
    int m = (l + r) / 2;
    push(v);
    return getsumr(v * 2 + 1, l, m, ql, qr) + getsumr(v * 2 + 2, m + 1, r, ql, qr);
}

int getsumc(int v, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) {
        return 0;
    }
    if (ql <= l && r <= qr) {
        return c[v];
    }
    int m = (l + r) / 2;
    push(v);
    return getsumc(v * 2 + 1, l, m, ql, qr) + getsumc(v * 2 + 2, m + 1, r, ql, qr);
}

void addpos(int l, int r, int x) {
    addpos(0, 0, C, l, r, x);
}
int getsumr(int l, int r) {
    return getsumr(0, 0, C, l, r);
}
int getsumc(int l, int r) {
    return getsumc(0, 0, C, l, r);
}

int q, d;

void setpointc(int v, int l, int r, int i, int x) {
    if (l == r) {
        c[v] = x;

        if (x) {
            ri[v] = getsumc(i + 1, i + d);
        }
        else {
            ri[v] = 0;
        }

        return;
    }
    int m = (l + r) / 2;
    push(v);
    if (i <= m) {
        setpointc(v * 2 + 1, l, m, i, x);
    }
    else {
        setpointc(v * 2 + 2, m + 1, r, i, x);
    }
    relax(v);
}

void setpointc(int i, int x) {
    setpointc(0, 0, C, i, x);
}


signed main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    cin >> q >> d;

    int ans = 0;
    vi u(C);
    rep (q) {
        int x;
        cin >> x;
        int b = x/d;

        if (u[x]) {
            ans -= 2 * (getsumr(x - d, x - 1) - getsumc(x - d, x - 1));
            ans -= comb(getsumc(x + 1, x + d));
            addpos(x - d, x - 1, -1);
            setpointc(x, 0);
        }
        else {
            ans += 2 * getsumr(x - d, x - 1);
            ans += comb(getsumc(x + 1, x + d));
            addpos(x - d, x - 1, 1);
            setpointc(x, 1);
        }
        u[x] ^= 1;
        cout << ans/2 << endl;

    }
}