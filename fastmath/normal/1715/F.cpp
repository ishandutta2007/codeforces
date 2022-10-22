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
#define ld long double
const ld eps = 1e-7, step = 0.01, C = 1000;
signed main() {

    #ifdef LOCAL
    ld ansx = 1.5;
    ld ansy = 0.5;
    #endif

    cout.precision(15);

    auto solve = [&] (int n, bool swp) {
    V <pair <ld, ld> > a;
    ld w = 0;
    for (int i = 0; i < n - 1; ++i) {
        w += step;
        a.app({i, 0});
        a.app({i + w, 0});
        a.app({i + w, C});
        a.app({i + 1, C});
    }
    w += step;
    a.app({n - 1, 0});
    a.app({n - 1 + w, 0});
    a.app({n - 1 + w, C + 1});
    a.app({0, C + 1});

    cout << "? " << a.size() << endl;
    each (e, a) {
        if (swp) {
            swap(e.x, e.y);
        }
        cout << fixed << e.x << ' ' << e.y << endl;
    }

    ld ans;
    cin >> ans;

    double r = ceil(ans/step)-1;
    for (int i = 1; i <= n; ++i) {
        if (abs(ans - i * step) < eps) {
            r = i - 1 + i * step;
        }
    }

    V <pair <ld, ld> > b;
    b.app({r, 0});
    b.app({r, C});
    b.app({r + 1, C});
    b.app({r + 1, 0});
    cout << "? " << b.size() << endl;
    each (e, b) {
        if (swp) {
            swap(e.x, e.y);
        }
        cout << fixed << e.x << ' ' << e.y << endl;
    }
    cin >> ans;

    //cout << r << endl;
    ld x = r - 1 + ans;
    //cout << x << endl;
    //exit(0);
    return x;
    };


    int n, m;
    cin >> n >> m;
    ld x = solve(n, 0);
    ld y = solve(m, 1);
    cout << fixed << "! " << x << ' ' << y << endl;
}