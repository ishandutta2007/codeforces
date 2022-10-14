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

	int n, k;
	cin >> n >> k;
	vector<int> v(n*k);
	forn(i, n*k){
		cin >> v[i];
		v[i]--;
	}

	vector<pii> ans;
	int alive = n;
	vector<bool> killed(n);
	while(alive){
		vector<int> bef(n, -1);
		forn(i, n*k){
			if(killed[v[i]]) continue;
			if(bef[v[i]] >= 0){
				killed[v[i]] = true;
				ans.pb(mp(bef[v[i]]+1, i+1));
				alive--;
				bef = vector<int>(n, -1);
			} else {
				bef[v[i]] = i;
			}
		}
	}

	assert(ans.size() == n);
	sort(ans.begin(), ans.end(), [&](pii a, pii b){return v[a.f-1] < v[b.f-1];});
	forn(i, n){
		cout << ans[i].f << " " << ans[i].s << "\n";
	}
}