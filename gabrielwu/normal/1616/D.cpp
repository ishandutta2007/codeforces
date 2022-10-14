#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f first
#define s second
#define rand(i, j) uniform_int_distribution<ll>((ll)(i), (ll)(j))(rng)
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max


int main(){
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	forn(ti, t){
		int n;
		cin >> n;
		vector<int> v(n);
		forn(i, n) cin >> v[i];
		int x;
		cin >> x;

		vector<vector<int>> dp(n+1, vector<int>(3, -MOD));
		dp[0][0] = 0;
		for(int i=1; i<=n; i++){
			ckmax(dp[i][0], dp[i-1][0]);
			ckmax(dp[i][0], dp[i-1][1]);
			ckmax(dp[i][0], dp[i-1][2]);

			ckmax(dp[i][1], dp[i-1][0]+1);
			if(i >= 2 && v[i-1] + v[i-2] >= x*2){
				ckmax(dp[i][2], dp[i-1][1]+1);
				if(i >= 3 && v[i-1] + v[i-2] + v[i-3] >= x*3){
					ckmax(dp[i][2], dp[i-1][2]+1);
				}
			}
		}

		cout << max(max(dp[n][0], dp[n][1]), dp[n][2]) << "\n";
	}
}