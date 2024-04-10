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
bool sq(int x) {
    int l = 0, r = x + 1;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (m * m <= x) l = m;
        else r = m;
    }
    return l * l == x;
}
int f(int x) {
    x++;
    while (!sq(x)) x++;
    return x;
}
int g(int x) {
    while (!sq(x)) x--;
    return x;
}
int ok(int x) {
    return x - g(x) < f(x) - x;
}
int sum(int n) {
    return n * (n + 1) / 2;
}
int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}
const int C = 2e6+7;
int lb[C];
int brute(vi a) {
    int k = 0;
    while (1) {
        bool o = 1;
        each (e, a) o &= ok(e + k);
        if (o) return k;
        k++;
    }
}
int solve(vi a) {
    int n = a.size();

    {
    int ptr = 0;
    FOR (x, C) {
        while (ptr < n && a[ptr] < x) {
            ptr++;
        }
        lb[x] = ptr;
    }    
    }

    int p = 0, root = 0;
    while (1) {
        while (root * root + 2 * root <= p) {
            root++;
        }
        int nxt = -1;
        for (int m = root; m * m + m + 1 - p <= a.back(); ++m) {
            int l = m * m + m + 1, r = m * m + 2 * m;
            int who = lb[max(0ll, l - p)];
            if (who != n) {
                ckmax(nxt, r - a[who] + 1);
            }
        }
        if (nxt > p) {
            p = nxt;
        }
        else {
            return p;
        }
    }
}
signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    /*
    FORN (x, 100) {
        if (ok(x)) {
            cout << x << ' ';
        }
    }
    */

    /*
    debug(brute({1, 3, 8, 10}));
    debug(brute({2, 3, 8, 9, 11}));
    debug(brute({1, 2, 3, 4, 5, 6, 7, 8}));
    debug(brute({1, 3, 8, 12, 17, 18, 20, 21, 22}));

    debug(solve({1, 3, 8, 10}));
    debug(solve({2, 3, 8, 9, 11}));
    debug(solve({1, 2, 3, 4, 5, 6, 7, 8}));
    debug(solve({1, 3, 8, 12, 17, 18, 20, 21, 22}));

    vi a;
    FORN (i, 100) {
        a.app(i);
    }
    debug(brute(a));
    debug(solve(a));
    */

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    cout << solve(a) << endl;


}