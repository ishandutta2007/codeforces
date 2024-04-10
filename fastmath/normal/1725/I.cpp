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

const int  md=998244353;
inline int sum(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}
inline int dif(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}
inline void add(int &a, const int &b) {
    a = sum(a, b);
}
inline void sub(int &a, const int &b) {
    a = dif(a, b);
}
inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}
int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b%2) return mul(a ,binpow(a, b - 1));
    int m = binpow(a,b/2);
    return mul(m,m);
}
int rev(int a) {
    return binpow(a, md - 2);
}
struct DSU {
    int n;
    vector<int> parent, size, value;

    int get(int i) { return parent[i] == i ? i : parent[i] = get(parent[i]); }

    DSU(int n) : value(n), parent(n, 1), size(n, 1) { iota(parent.begin(), parent.end(), 0); }

    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        parent[y] = x;
        size[x] += size[y];
        return true;
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
    int ans = 1;
    DSU dsu(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        int ur = dsu.get(u), vr = dsu.get(v);
        int cnt = mul(dsu.size[ur], dsu.size[vr]);
        cnt = mul(cnt, cnt);
        ans = mul(ans, mul(cnt, 2 * i - 1));
        dsu.unite(u,v);
    }
    cout << ans << '\n';
}