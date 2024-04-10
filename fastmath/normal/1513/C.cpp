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

const int MOD = 1e9+7;

const int LG = 20;
int dp[LG][10][10];

void add(int &a, int b) {
	a += b;
	if (a >= MOD)
		a -= MOD;
}

int cur[10], to[10];

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    FOR (c, 10) {
    	if (c < 9) {
    		dp[0][c][c + 1] = 1;
    	}
    	else {
    		dp[0][c][0] = dp[0][c][1] = 1;
    	}
    }

    FORN (t, LG - 1) {
    	FOR (c, 10) {
    		FOR (x, 10) {
    			FOR (y, 10) {
    				add(dp[t][c][y], dp[t - 1][c][x] * dp[t - 1][x][y] % MOD);
    			}
    		}
    	}
    }

    int t;
    cin >> t;
    while (t--) {
    	int n, m;
    	cin >> n >> m;

    	FOR (i, 10)
    		cur[i] = 0;
    	string s = to_string(n);
    	trav (c, s) {
    		cur[c - '0']++;
    	}

    	FOR (bit, LG) {
    		if ((m >> bit) & 1) {
    			FOR (i, 10)
    				to[i] = 0;
    			FOR (x, 10) {
    				FOR (y, 10) {
    					add(to[y], cur[x] * dp[bit][x][y] % MOD);
    				}
    			}
    			FOR (i, 10)
    				cur[i] = to[i];
    		}
    	}

    	int ans = 0;
    	FOR (i, 10) {
    		add(ans, cur[i]);
    	}
    	cout << ans << endl;
    }
}