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
V <ii> v = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    V <vi> a(n, vi(m));
    cin >> a;
    auto in = [&] (int i, int j) { return 0 <= i && i < n && 0 <= j && j < m; };
    auto check = [&] (int i, int j) {
            bool loc = 1;
            each (e, v) {
                int x = i + e.x, y = j + e.y;
                if (in(x, y)) {
                    loc &= a[i][j] < a[x][y];
                }
            }
            return loc && a[i][j] != 1;
    };
    int l = 0;
    FOR (i, n) {
        FOR (j, m) {
            if (check(i, j)) {
                l++;
            }
        }
    }
    set <pair <ii, ii> > s;
    auto add = [&] (int x1, int y1, int x2, int y2) {
        ii a = mp(x1, y1);
        ii b = mp(x2, y2);
        if (b < a) swap(a, b);
        s.insert(mp(a, b));
    };
    auto sol = [&] (int x, int y) {
        FOR (i, n) {
            FOR (j, m) {

                set <ii> cand;
                cand.insert(mp(x, y));
                cand.insert(mp(i, j));


                each (e, v) {
                    int u = x + e.x, v = y + e.y;
                    if (in(u, v)) cand.insert(mp(u, v));
                }
                each (e, v) {
                    int u = i + e.x, v = j + e.y;
                    if (in(u, v)) cand.insert(mp(u, v));
                }

                int l1 = l;
                each (e, cand) {
                    l1 -= check(e.x, e.y);
                }
                swap(a[x][y], a[i][j]);
                each (e, cand) {
                    l1 += check(e.x, e.y);
                }
                swap(a[x][y], a[i][j]);

                assert(l1 >= 0);
                if (l1 == 0) {
                    add(x, y, i, j);
                }

            }
        }
    };
    if (l == 0) {
        cout << 0 << endl;
        exit(0);
    }
    FOR (i, n) {
        FOR (j, m) {
            if (check(i, j)) {

                sol(i, j);
                each (e, v) {
                    int x = i + e.x, y = j + e.y;
                    if (in(x, y)) {
                        sol(x, y);
                    }
                }

                if (s.empty()) {
                    cout << 2 << endl;
                    exit(0);
                }

                cout << 1 << ' ' << s.size() << endl;
                each (e, s) {
                    debug(e);
                }
                exit(0);

            }
        }
    }
}