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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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

	int q; cin >> q;
	forn(qi, q) {
		string t; cin >> t;
		int len = t.size();

		unordered_map<string, int> keys;
		int n; cin >> n;
		forn(i, n) {
			string s; cin >> s;
			keys[s] = i+1;
		}

		vector<int> dp(len+1, MOD);
		vector<int> backtrack(len+1, -1);
		vector<pii> move(len+1);
		dp[0] = 0;
		forn(i, len) {
			string curr = "";
			int reach = -1;
			int use = -1;
			for(int j=i; j<len; j++) {
				curr += t.at(j);
				if(keys[curr]) {
					reach = j+1;
					use = keys[curr];
				}
			}

			for(int j=i; j<=reach; j++) {
				if(ckmin(dp[j], dp[i] + 1)) {
					backtrack[j] = i;
					move[j] = {use, i};
				}
			}
		}

		if(dp[len] == MOD) {
			cout << -1 << "\n";
		} else {
			cout << dp[len] << "\n";
			int x = len;
			while(x > 0) {
				cout << move[x].f << " " << move[x].s+1 << "\n";
				x = move[x].s;
			}
		}

	}
}