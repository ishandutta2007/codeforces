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

const int N = 507, INF = 1e18;

int n, m, k;
int a[N][N];
int cost[N][N][4];
int hor[N][N], ver[N][N];
V <ii> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int dp[21][N][N];

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    cin >> n >> m >> k;
    if (k & 1) {
    	FOR (i, n) {
    		FOR (j, m) {
    			cout << -1 << ' ';
    		}
    		cout << endl;
    	}
    	exit(0);
    }

    FOR (i, n) {
    	FOR (j, m - 1) {
    		cin >> hor[i][j];
    		cost[i][j][1] = cost[i][j + 1][0] = hor[i][j];
    	}
    }
    FOR (i, n - 1) {
    	FOR (j, m) {
    		cin >> ver[i][j];
    		cost[i][j][3] = cost[i + 1][j][2] = ver[i][j];
    	}
    }

    FORN (t, k/2) {
    	FOR (i, n) {
    		FOR (j, m) {
    			dp[t][i][j] = INF;
    		}
    	}
    }
    FOR (t, k/2) {
    	FOR (i, n) {
    		FOR (j, m) {
				int num = 0;
	    		trav (e, dir) {
	    			int u = i + e.x, v = j + e.y;
	    			if (0 <= u && u < n && 0 <= v && v < m) {
	    				ckmin(dp[t + 1][u][v], dp[t][i][j] + cost[i][j][num]);
	    			}
	    			num++;
	    		} 
    		}
    	}
    }

    FOR (i, n) {
    	FOR (j, m) {
    		cout << dp[k/2][i][j]*2 << ' ';
    	}
    	cout << endl;
    }
}