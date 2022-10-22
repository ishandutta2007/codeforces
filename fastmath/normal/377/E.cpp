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

const int INF = 1e18;

struct Point {
    int x, y, v;
};

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, want;
    cin >> n >> want;

    map <int, int> best;
    FOR (i, n) {
        int v, c;
        cin >> v >> c;
        if (best.find(v) == best.end()) {
            best[v] = INF;
        }
        ckmin(best[v], c);
    }

    V <Point> dp;
    each (e, best) {
        int v = e.x, c = e.y;

        //debug(mp(v, c));

        if (dp.empty()) {
            dp.app({0, 0, v});
            continue;
        }
        int l = -1, r = (int)dp.size() - 1;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (dp[m].y + (dp[m + 1].x - 1 - dp[m].x) * dp[m].v >= c) {
                r = m;
            }
            else {
                l = m;
            }
        }

        Point p;

        p.x = dp[r].x + div_up(c - dp[r].y, dp[r].v);
        p.y = dp[r].y + dp[r].v * div_up(c - dp[r].y, dp[r].v) - c;
        p.v = v;

        while (dp.size() && dp.back().x >= p.x && dp.back().y <= p.y + (dp.back().x - p.x) * p.v) {
            dp.pop_back();
        }

        if (dp.empty()) {
            assert(p.x == 0);
            dp.app(p);
            continue;
        }

        int left = p.x - 1, right = INF;
        while (left < right - 1) {
            int m = (left + right) / 2;

            __int128 old = dp.back().y + (__int128)(m - dp.back().x) * dp.back().v;
            __int128 neu = p.y + (__int128)(m - p.x) * p.v;

            if (old <= neu) {
                right = m;
            }
            else {
                left = m;
            }
        }

        p.y += p.v * (right - p.x);
        p.x = right;
        assert(dp.back().x < p.x);
        dp.app(p);

        /*
        each (e, dp) {
            cout << e.x << ' ' << e.y << ' ' << e.v << endl;
        }
        */
    }

    int sz = dp.size();
    FOR (i, sz - 1) {
        if (dp[i].y + dp[i].v * (dp[i + 1].x - 1 - dp[i].x) >= want) {
            cout << dp[i].x + div_up(want - dp[i].y, dp[i].v) << endl;
            exit(0);
        }
    }
    cout << dp.back().x + div_up(want - dp.back().y, dp.back().v) << endl;
}