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
#define pb push_back
#define trav(a, x) for (auto& a : x)
using vi = vector<int>;
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

const int N = 507;
string a[N];
bool used[N][N];

#define y1 lalala

int n, m;
int x1, y1, x2, y2;

V <ii> di = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

ii ban = mp(-1, -1);

void dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || used[x][y])
        return;

    if (mp(x, y) == ban)
        return;

    if (mp(x, y) != mp(x1, y1) && mp(x, y) != mp(x2, y2) && a[x][y] == 'X')
        return;

    used[x][y] = 1;
    trav (v, di) {
        int i = x + v.x, j = y + v.y;
        dfs(i, j);
    }
}

signed main() {
    #ifdef ONLINE_JUDGE
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >>m ;
    FOR (i, n)
        cin >> a[i];
    cin >> x1 >> y1 >> x2 >> y2;

    x1--; y1--; x2--; y2--;

    auto YES = [&] () {
        cout << "YES" << endl;
        exit(0);
    };

    auto NO = [&] () {
        cout << "NO" << endl;
        exit(0);
    };

    dfs(x1, y1);

    if (mp(x1, y1) == mp(x2, y2)) {
        trav (v, di) {
            int i = x1 + v.x, j = y1 + v.y;
            if (0 <= i && i < n && 0 <= j && j < m && a[i][j] == '.') {
                YES();
            }
        }
        NO();
    }

    if (a[x2][y2] == 'X') {
        if (used[x2][y2]) {
            YES();
        }
        else {
            NO();
        }
    }
    else {
        if (used[x2][y2]) {
            trav (v, di) {
                int i = x2 + v.x, j = y2 + v.y;
                if (0 <= i && i < n && 0 <= j && j < m && a[i][j] == '.') {
                    memset(used, 0, sizeof used);
                    ban = mp(i, j);
                    dfs(x1, y1);
                    if (used[x2][y2]) {
                        YES();
                    }
                }
            }
            NO();
        }
        else {
            NO();
        }
    }
}