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
		vector<int> v(n);
		forn(i, n) cin >> v[i];

		function<bool(int,int,int)> row = [&](int i, int j, int k){
			return v[j] >= min(v[i], v[k]) && v[j] <= max(v[i], v[k]);
		};

		ll ans = n + max(0, n-1) + max(0, n-2) + max(0, n-3);
		for(int i=0; i+2<n; i++){
			if(row(i, i+1, i+2)) ans--;
		}
		for(int i=0; i+3<n; i++){
			if(row(i,i+1,i+2)||row(i,i+1,i+3)||row(i,i+2,i+3)||row(i+1,i+2,i+3)) ans--;
		}
		cout << ans << "\n";
	}
}