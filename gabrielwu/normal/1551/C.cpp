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

//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max


int main(){
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	forn(ti, t){
		int n;
		cin >> n;
		vector<vector<int>> v(n, vector<int>(5));
		forn(i, n){
			vector<int> cnt(5);
			string s;
			cin >> s;
			for(char c: s){
				cnt[c-'a']++;
			}
			v[i] = cnt;
		}

		int best = 0;
		forn(c, 5){
			vector<int> x(n);
			forn(i, n){
				forn(d, 5){
					if(d == c) x[i] += v[i][d];
					else x[i] -= v[i][d];
				}
			}
			sort(x.begin(), x.end());
			int sum = 0;
			int used = 1;
			for(; used<=n+1; used++){
				if(used > n) break;
				sum += x[n - used];
				if(sum <= 0) break;
			}
			best = max(best, used-1);

		}

		cout << best << "\n";
	}
}