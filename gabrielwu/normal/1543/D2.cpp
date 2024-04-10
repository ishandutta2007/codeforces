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
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<vi> vii;

//Printing pairs and vectors
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
		int n, k;
		cin >> n >> k;

		int LG = 20;
		vector<int> curr(LG), guess(LG);

		function<ll(vector<int>)> decimal = [&](vector<int> v){
			ll ans = 0;
			for(int i=LG-1; i>=0; i--){
				ans *= k;
				ans += v[i];
			}
			return ans;
		};
		function<vector<int>(vector<int>)> inc = [&](vector<int> v){
			int i=0;
			while(v[i] == k-1){
				v[i] = 0;
				i++;
			}
			v[i]++;
			return v;
		};
		function<vector<int>(vector<int>, vector<int>)> minus = [&](vector<int> v, vector<int> u){
			vector<int> ans(LG);
			forn(i, LG){
				ans[i] = (v[i] - u[i] + k)%k;
			}
			return ans;
		};


		forn(i, n){
			cout << decimal(guess) << endl;
			int r;
			cin >> r;
			if(r == 1){
				break;
			}else if(r == -1){
				return 0;
			}

			if(i%2 == 0){
				guess = minus(curr, inc(curr));
			}else{
				guess = minus(inc(curr), curr);
			}
			curr = inc(curr);
		}
	}
}