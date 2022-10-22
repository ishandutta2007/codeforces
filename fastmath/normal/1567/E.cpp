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

const int N = 2e5+7;
array <int, 4> tree[N << 2]; // (l, r, ans, len) or (-1, -1, -1, 0)

array <int, 4> merge(array <int, 4> l, array <int, 4> r) {
    if (l[3] == 0) {
        return r;
    }
    if (r[3] == 0) {
        return l;
    }
    array <int, 4> ans;

    if (l[0] == l[3]) {
        ans[0] = l[3] + r[0];
    }
    else {
        ans[0] = l[0];
    }

    if (r[1] == r[3]) {
        ans[1] = r[3] + l[1];
    }
    else {
        ans[1] = r[1];
    }

    ans[2] = l[2] + r[2] + l[1] * r[0];
    ans[3] = l[3] + r[3];

    return ans;
}

array <int, 4> get(int v, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) {
        return {-1, -1, -1, 0};
    }
    if (ql <= l && r <= qr) {
        return tree[v];
    }
    int m = (l + r) / 2;
    return merge(get(v * 2 + 1, l, m, ql, qr), get(v * 2 + 2, m + 1, r, ql, qr));
}

int n, q;

int get(int l, int r) {
    return get(0, 0, n - 2, l, r)[2];
}

void setpoint(int v, int l, int r, int i, int x) {
    if (l == r) {
        tree[v][0] = tree[v][1] = tree[v][2] = x;
        return;
    }
    int m = (l + r) / 2;
    if (i <= m) {
        setpoint(v * 2 + 1, l, m, i, x);
    }
    else {
        setpoint(v * 2 + 2, m + 1, r, i, x);
    }
    tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void setpoint(int i, int x) {
    setpoint(0, 0, n - 2, i, x);
}

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    FOR (i, N << 2) {
        tree[i][3] = 1;
    }

    cin >> n >> q;

    vi a(n);
    cin >> a;

    FOR (i, n - 1) {
        if (a[i] <= a[i + 1]) {
            setpoint(i, 1);
        }
    }

    rep (q) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, x;
            cin >> i >> x;
            i--;
            a[i] = x;
            if (i) {
                setpoint(i - 1, a[i - 1] <= a[i]);
            }
            if (i + 1 < n) {
                setpoint(i, a[i] <= a[i + 1]);
            }
        }
        else {
            int l, r;
            cin >> l >> r;
            l--; r--;
            int ans = r - l + 1;
            if (l < r) {
                ans += get(l, r - 1);
            }
            cout << ans << endl;
        }
    }
}