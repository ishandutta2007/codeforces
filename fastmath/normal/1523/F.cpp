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
const int M = 103, N = 14, INF = 1e18;
int maxscore[M][1 << N], mintime[M][1 << N];
bool used[M][1 << N];

int X[N], Y[N];
int x[M], y[M], t[M];

int GO_quest[1 << N][M], GO_tower[1 << N][N];

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    FOR (i, M) {
        FOR (j, 1 << N) {
            maxscore[i][j] = -INF;
            mintime[i][j] = INF;
        }
    }
    FOR (i, M) {
        maxscore[i][0] = 1;
    }
    FOR (mask, 1 << N) {
        if (bp(mask) == 1) {
            mintime[0][mask] = 0;
        }
    }
    int n, m;
    cin >> n >> m;
    FOR (i, n) {
        cin >> X[i] >> Y[i];
    }

    V <vi> T;
    FOR (i, m) {
        cin >> x[i] >> y[i] >> t[i];
        T.app({t[i], x[i], y[i]});
    }
    sort(all(T));
    FOR (i, m) {
        t[i] = T[i][0];
        x[i] = T[i][1];
        y[i] = T[i][2];
    }

    FOR (mask, 1 << n) {
        FOR (i, m) {
            GO_quest[mask][i] = INF;
            FOR (j, n) {
                if (Bit(mask, j)) {
                    ckmin(GO_quest[mask][i], abs(X[j] - x[i]) + abs(Y[j] - y[i]));
                }
            }
        }
        FOR (i, n) {
            GO_tower[mask][i] = INF;
            FOR (j, n) {
                if (Bit(mask, j)) {
                    ckmin(GO_tower[mask][i], abs(X[j] - X[i]) + abs(Y[j] - Y[i]));
                }
            }
        }
    }

    FOR (i, m) {
        FOR (have, m + 1) {
            FOR (mask, 1 << n) {
                if (mintime[have][mask] <= t[i] && !used[have][mask]) {
                    used[have][mask] = 1;
                    FOR (go, n) {
                        if (!Bit(mask, go)) {
                            ckmin(mintime[have][mask + (1 << go)], mintime[have][mask] + GO_tower[mask][go]);
                        }
                    }
                    FOR (go, m) {
                        if (mintime[have][mask] + GO_quest[mask][go] <= t[go]) {
                            ckmax(maxscore[go][mask], have + 1);
                        }
                    }
                }
            }
        }
        FOR (mask, 1 << n) {
            int have = maxscore[i][mask];
            if (have > 0) {
                for (int j = i + 1; j < m; ++j) {
                    if (t[i] + min(GO_quest[mask][j], abs(x[i] - x[j]) + abs(y[i] - y[j])) <= t[j]) {
                        ckmax(maxscore[j][mask], have + 1);
                    }
                }
                FOR (j, n) {
                    if (!Bit(mask, j)) {
                        ckmin(mintime[have][mask + (1 << j)], t[i] + min(GO_tower[mask][j], abs(x[i] - X[j]) + abs(y[i] - Y[j])));
                    }
                }
            }
        }
    }

    int ans = 0;
    FOR (i, m) {
        FOR (j, 1 << n) {
            ckmax(ans, maxscore[i][j]);
        }
    }
    cout << ans << endl;
}