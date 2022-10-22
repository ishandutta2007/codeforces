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
const int C = 2e5+2007;
int c[C], dp[C];
vi t[C << 2];
void add(int v, int l, int r, int ql, int qr, int x) {
    if (r < ql || qr < l) {
        return;
    }
    if (ql <= l && r <= qr) {
        t[v].app(x);
        return;
    }
    int m = (l + r) / 2;
    add(v * 2 + 1, l, m, ql, qr, x);
    add(v * 2 + 2, m + 1, r, ql, qr, x);
}
int n, q;
void add(int l, int r, int x) {
    add(0, 0, q - 1, l, r, x);
}   
int prop[C << 2];
int val[C << 2], mn[C << 2], mx[C << 2];
void gap(int v, int x) {

    prop[v] = 1;
    val[v] = mn[v] = mx[v] = x;
}
void push(int v) {
    if (prop[v]) {
        gap(v * 2 + 1, val[v]);
        gap(v * 2 + 2, val[v]);
        prop[v] = 0;
    }
}
void relax(int v) {

    mn[v] = min(mn[v * 2 + 1], mn[v * 2 + 2]);
    mx[v] = max(mx[v * 2 + 1], mx[v * 2 + 2]);

}
void setval(int v, int l, int r, int ql, int qr, int x) {
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
        gap(v, x);
        return;
    }
    int m = (l + r) / 2;
    push(v);
    setval(v * 2 + 1, l, m, ql, qr, x);
    setval(v * 2 + 2, m + 1, r, ql, qr, x);
    relax(v);
}
int findnull(int v, int l, int r, int ql) {
    if (r < ql || mn[v]) {
        return C;
    }
    if (l == r) {
        return l;
    }
    int m = (l + r) / 2;
    push(v);
    int t = findnull(v *2 + 1, l, m, ql);
    if (t != C) {
        return t;
    }
    else {
        return findnull(v * 2 + 2, m + 1, r, ql);   
    }
}
int findone(int v, int l, int r, int ql) {
    if (r < ql || mx[v] == 0) {
        return C;
    }
    if (l==r) {
        return l;
    }
    int m = (l + r) / 2;
    push(v);
    int t = findone(v * 2 + 1, l, m, ql);
    if (t != C) {
        return t;
    }
    else {
        return findone(v * 2 + 2, m + 1, r, ql);
    }
}
int rightone(int v, int l, int r) {
    if (l == r) {
        return l;
    }
    int m = (l + r) / 2;
    push(v);
    if (mx[v * 2 + 2]) {
        return rightone(v * 2 + 2, m + 1, r);
    }
    else {
        return rightone(v * 2 + 1, l, m);
    }
}
signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, q;
    cin >> n >> q;
    vi a(n);
    cin >> a;

    auto addx = [&] (int x) {
        int p = findnull(0, 0, C, x);
        setval(0, 0, C, x, p - 1, 0);
        setval(0, 0, C, p, p, 1);
    };  

    auto rem = [&] (int x) {
        int p = findone(0, 0, C, x);
        setval(0, 0, C, x, p - 1, 1);
        setval(0, 0, C, p, p, 0);
    };

    each (e, a) {
        addx(e);
    }

    rep (q) {
        int i, x;
        cin >> i >> x;
        i--;

        rem(a[i]);

        addx(x); 
        a[i] = x;

        cout << rightone(0, 0, C) << endl;
    }
}