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

const int N = 507;

int n, m;
string a[N];

V <ii> g[N][N];
bool used[N][N];
int ans[N][N];

V <ii> v = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void dfs(int x, int y, int c) {
    if (0 <= x && x < n && 0 <= y && y < m && !used[x][y]) {
        used[x][y] = 1;
        ans[x][y] = c;
        each (p, g[x][y]) {
            dfs(p.x, p.y, c ^ 1);
        }
    }
}

void solve() {
    cin >> n >> m;

    FOR (i, n) {
        FOR (j, m) {
            g[i][j].clear();
            used[i][j] = 0;
            ans[i][j] = 0;
        }
    }

    FOR (i, n) {
        cin >> a[i];
    }

    FOR (i, n) {
        FOR (j, m) {
            if (a[i][j] == 'X') {
                int ad = 0;
                V <ii> who;
                each (e, v) {
                    int x = i + e.x, y = j + e.y;
                    if (a[x][y] == '.') {
                        ad++;
                        who.app(mp(x, y));
                    }
                }
                if (ad & 1) {
                    cout << "NO" << endl;
                    exit(0);
                }
                for (int i = 0; i < who.size(); i += 2) {
                    g[who[i].x][who[i].y].app(who[i ^ 1]);
                    g[who[i ^ 1].x][who[i ^ 1].y].app(who[i]);
                }
            }
        }
    }

    FOR (i, n) {
        FOR (j, m) {
            if (a[i][j] == '.' && !used[i][j]) {
                dfs(i, j, 0);
            }
        }
    }

    FOR (i, n) {
        FOR (j, m) {
            if (a[i][j] == '.') {
                each (v, g[i][j]) {
                    if (ans[i][j] == ans[v.x][v.y]) {
                        assert(0);
                    }
                }
            }
        }
    }

    cout << "YES" << endl;
    FOR (i, n) {
        FOR (j, m) {
            if (a[i][j] == 'X') {
                int sum = 0;
                each (e, v) {
                    int x = i + e.x, y = j + e.y;
                    if (a[x][y] == '.') {
                        if (ans[x][y]) {
                            sum += 4;
                        }
                        else {
                            sum += 1;
                        }
                    }
                }
                assert(sum%5==0);
                cout << sum << ' ';
            }
            else if (ans[i][j]) {
                cout << 4 << ' ';
            }
            else {
                cout << 1 << ' ';
            }
        }
        cout << endl;
    }
}

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t = 1;
    rep (t) solve();
}