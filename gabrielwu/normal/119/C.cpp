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

	int n, m;
	ll k;
	cin >> n >> m >> k;

	//dp[i][j][h] is if the ith day can have the jth subject using the hth homework
	vector<pair<pii, pll>> v;
	forn(i, m){
		ll a, b;
		int c;
		cin >> a >> b >> c;
		v.pb(mp(mp(c, i), mp(a, b)));
	}

	sort(v.begin(), v.end());
	vector<int> trans(m);
	forn(i, m) {
		trans[i] = v[i].f.s;
	}

	vector<vector<vector<pair<int, pll>>>> dp(n, vector<vector<pair<int, pll>>>(m, vector<pair<int, pll>>(101, mp(-1, mp(-1, -1)))));
	for(int j=0; j<m; j++) {
		for(int h = 0; h<101; h++) {
			if(h <= v[j].s.s - v[j].s.f) {
				dp[0][j][h] = mp(0, mp(0, v[j].s.f+h));
			}
		}
	}

	for(int i=1; i<n; i++) {
		for(int j=i; j<m; j++) {
			for(int h = 0; h<101; h++) {
				if(h > v[j].s.s - v[j].s.f) continue;
				ll best = -1;
				ll z = v[j].s.f + h;
				pair<int, ll> works = mp(-1, -1);
				for(int oth = i-1; oth < j; oth++) {
					if(v[oth].f.f >= v[j].f.f) continue;
					if(v[oth].s.f <= z-k && v[oth].s.s >= z-k && dp[i-1][oth][z-k-v[oth].s.f].s.s > best){
						works = mp(oth, z-k);
						best = dp[i-1][oth][z-k-v[oth].s.f].s.s;
					}
				}
				if(z%k == 0) {
					for(int oth = i-1; oth < j; oth++) {
						if(v[oth].f.f >= v[j].f.f) continue;
						if(v[oth].s.f <= z/k && v[oth].s.s >= z/k && dp[i-1][oth][z/k-v[oth].s.f].s.s > best){
							works = mp(oth, z/k);
							best = dp[i-1][oth][z/k-v[oth].s.f].s.s;
						}
					}

				}
				if(works.f != -1) dp[i][j][h] = mp(works.f, mp(works.s, best + z));
			}
		}
	}


	pair<int, pll> sub = mp(-1, mp(-1, -1));
	for(int j=n-1; j<m; j++) {
		for(int h = 0; h<101; h++) {
			if(dp[n-1][j][h].s.s > sub.s.s) {
				sub.f = j;
				sub.s.f = v[j].s.f + h;
				sub.s.s = dp[n-1][j][h].s.s;
			}
		}
	}

	// cout << sub << "\n";
	// cout << dp[n-1][4] << "\n";

	if(sub.f == -1){
		cout << "NO\n";
	} else {
		cout << "YES\n";
		vector<pair<int, ll>> ans(n);
		ans[n-1] = mp(sub.f, sub.s.f);
		for(int i=n-1; i>0; i--) {
			sub = dp[i][sub.f][sub.s.f - v[sub.f].s.f];
			ans[i-1] = mp(sub.f, sub.s.f);
		}

		for(pair<int, ll> x: ans) {
			cout << trans[x.f]+1 << " " << x.s << "\n";
		}
	}
}