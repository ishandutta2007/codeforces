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
const int N = 3007;
int n, k, ans = 0;
vi a[N];
int len[N];

const int LG = 30;
int was[LG][N];

int dp[N];
void solve(int l, int r, int dep) {
	if (l == r) {
		FOR (i, k + 1) {
			if (k - i <= len[l]) {
				ckmax(ans, dp[i] + a[l][k - i]);	
			}
		}
		return;
	}
	int m = (l + r) >> 1;

	FOR (i, k + 1) {
		was[dep][i] = dp[i];
	}

	for (int i = m + 1; i <= r; ++i) {
		int w = len[i];
		int c = a[i].back();
		for (int j = k - w; j >= 0; --j) {
			ckmax(dp[j + w], dp[j] + c);
		}
	}

	solve(l, m, dep + 1);

	FOR (i, k + 1) {
		dp[i] = was[dep][i];
	}
	for (int i = l; i <= m; ++i) {
		int w = len[i];
		int c = a[i].back();
		for (int j = k - w; j >= 0; --j) {
			ckmax(dp[j + w], dp[j] + c);
		}
	}

	solve(m + 1, r, dep + 1);
}

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> k;
    FOR (i, n) {
        cin >> len[i];
        a[i].resize(len[i]);
        cin >> a[i];
        for (int j = 1; j < len[i]; ++j) {
            a[i][j] += a[i][j - 1];
        }
        a[i].insert(a[i].begin(), 0);
    }
    solve(0, n - 1, 0);
    cout << ans << endl;
}