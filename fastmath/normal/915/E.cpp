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
#define debug2(x, y) std::cerr << #x << ", " << #y << ": " << x << ", " << y << '\n';
#define debug3(x, y, z) std::cerr << #x << ", " << #y << ", " << #z << ": " << x << ", " << y << ", " << z << '\n';
#else
#define debug(x)
#define debug2(x, y) 
#define debug3(x, y, z) 
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

const int N = 15e6;

int ptr = 0;
int s[N], p[N], l[N], r[N];

int newNode(int s_, int p_) {
    s[ptr] = s_;
    p[ptr] = p_;
    ptr++;
    return ptr - 1;
}

void gap(int t, int l, int r, int x) {
    s[t] = (r - l + 1) * x;
    p[t] = x;
}

void push(int t, int l, int r, int m) {
    if (p[t] != -1) {
        gap(::l[t], l, m, p[t]);
        gap(::r[t], m + 1, r, p[t]);
        p[t] = -1;
    }
}
void relax(int t) {
    s[t] = s[l[t]] + s[r[t]];
}
void upd(int t, int l, int r, int ql, int qr, int x) {
    if (r < ql || qr < l) {
        return;
    }
    if (ql <= l && r <= qr) {
        gap(t, l, r, x);
        return;
    }
    int m = (l + r) / 2;
    if (::l[t] == -1) {
        ::l[t] = newNode(0, -1);
    }
    if (::r[t] == -1) {
        ::r[t] = newNode(0, -1);
    }
    push(t, l, r, m);

    upd(::l[t], l, m, ql, qr, x);
    upd(::r[t], m + 1, r, ql, qr, x);
    relax(t);
}
signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    FOR(i, N) {
        l[i] = r[i] = p[i] = -1;
    }
    int n, q;
    cin >> n >> q;

    int root = newNode(n, 1);
    rep (q) {
        int t, l, r;
        cin >> l >> r >> t;
        upd(root, 1, n, l, r, t - 1);
        cout << s[root] << endl;
    }

}