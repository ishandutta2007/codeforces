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

	int n;
	cin >> n;
	ll x;
	cin >> x;

	unordered_map<ll, int> tried;
	int best = MOD;
	function<void(ll, int)> dfs = [&](ll u, int sofar) {
		if(tried[u] > 0 && tried[u] <= sofar + 100) return;
		tried[u] = sofar + 100;
		if(sofar > best) return;

		ll x = u;
		int cnt = 0;
		vector<bool> cont(10);
		while(x > 0) {
			cnt++;
			cont[x%10] = true;
			x /= 10;
		}

		if(cnt == n) {
			best = sofar;
			return;
		}

		for(int i=9; i>=2; i--) {
			if(cont[i]) dfs(u*i, sofar+1);
		}
	};

	dfs(x, 0);
	if(best == MOD) best = -1;
	cout << best << "\n";
}