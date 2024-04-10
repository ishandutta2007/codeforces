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

#define double long double

const int N = 1e5+7;
double dp[N][10];
bool take[N][10];
int prv[N][10];

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, w;
    cin >> n >> w;
    vi a(n);
    cin >> a;

    FOR (i, n + 1)
    	FOR (j, 10)
    		dp[i][j] = -1;

    dp[0][1] = 0;
    FOR (i, n) {
    	double l = log(a[i]);
    	FOR (c, 10) {
    		if (dp[i][c] >= 0) {
    			if (ckmax(dp[i + 1][c], dp[i][c])) {
    				take[i + 1][c] = 0;
    				prv[i + 1][c] = c;
    			}
    			int to = (c * a[i]) % 10;
    			if (ckmax(dp[i + 1][to], dp[i][c] + l)) {
    				take[i + 1][to] = 1;
    				prv[i + 1][to] = c;
    			}
    		}
    	}
    }
    if (dp[n][w] < 0) {
    	cout << -1 << endl;
    }
    else if (dp[n][w] > 0) {
    	vi ans;
    	int c = w;
    	for (int i = n; i; --i) {
    		if (take[i][c]) {
    			ans.app(a[i - 1]);
    		}
    		c = prv[i][c];
    	}
    	cout << ans.size() << endl;
    	cout << ans << endl;
    }
    else {
    	trav (e, a) {
    		if (e == 1) {
    			cout << 1 << endl << 1 << endl;
    			exit(0);
    		}
    	}
    	cout << -1 << endl;
    }
}