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
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define FORN(i, n) for (int i = 1; i <= n; ++i)
#define pb push_back
#define trav(a, x) for (auto& a : x)
using vi = vector<int>;
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
tcT> void re(V<T>& x) { 
    trav(a, x)
        cin >> a;
}
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

V <ii> d[3][3];

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        V <string> a(3);

        cin >> a;

        vi ptr(3);
        FOR (i, 3) {
            FOR (j, 3) {
                d[i][j].clear();
            }
        }

        while (1) {
            int x = -1, y = -1;
            FOR (i, 3) {
                for (int j = i + 1; j < 3; ++j) {
                    if (a[i][ptr[i]] == a[j][ptr[j]]) {
                        x = i;
                        y = j;
                        break;
                    }
                }
            }
            d[x][y].app(mp(ptr[x], ptr[y]));
            ptr[x]++;
            ptr[y]++;

            if (ptr[x] == 2 * n) {
                break;
            }

            if (ptr[y] == 2 * n) {
                break;
            }
        }

        int x = -1, y = -1;
        FOR (i, 3) {
            for (int j = i + 1; j < 3; ++j) {
                if (d[i][j].size() >= n) {
                    x = i; y = j;
                    break;
                }
            }
        }
        assert(x != -1);

        int px = 0, py = 0;
        trav (e, d[x][y]) {
            cout << a[x].substr(px, e.x - px);
            cout << a[y].substr(py, e.y - py);
            cout << a[x][e.x];
            px = e.x + 1;
            py = e.y + 1;
        }
        cout << a[x].substr(px, 2 * n - px);
        cout << a[y].substr(py, 2 * n - py);
        cout << endl;
    }
}