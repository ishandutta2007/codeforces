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
signed main() {
    #ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    vi b(n);
    int p = 0;
    FOR (i, n) {
        b[i] = a[i] - p;
        p = a[i];
    }
    sort(all(b));
    auto f = [&] (int x, int k) {
        int d = x/k;
        int pl = x - d * k;
        return (d + 1) * (d + 1) * pl + d * d * (k - pl);
    };
    auto GetVal = [&] (int atleast) {
        int sum = 0;
        each (e, b) {
            int l = 1, r = e + 1;
            while (l < r - 1) {
                int m = (l + r) / 2;
                if (f(e, m - 1) - f(e, m) >= atleast) l = m;
                else r = m;
            }
            sum += f(e, l);
        }
        return sum;
    };
    auto GetCnt = [&] (int atleast) {
        int cnt = 0, prv = 1;
        each (e, b) {
            int l = prv, r = e + 1;
            while (l < r - 1) {
                int m = (l + r) / 2;
                if (f(e, m - 1) - f(e, m) >= atleast) l = m;
                else r = m;
            }
            cnt += l - 1;
            prv = l;
        }
        return cnt;
    };

    const int INF = 1e18;

    int mx;
    cin >> mx;

    int start = 0;
    each (e, b) start += e * e;
    if (start <= mx) {
        cout << 0 << endl;
        exit(0);
    }

    int l = 0, r = INF;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (GetVal(m) <= mx) {
            l = m;
        }
        else {
            r = m;
        }
    }
    cout << GetCnt(r) + div_up(GetVal(r) - mx, l) << endl;
}