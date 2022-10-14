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

	int n, k;
	cin >> n >> k;
	if(n%2 && !(k%2)){
		cout << -1 << endl;
		return 0;
	}

	ll ans = 0;
	vector<int> v(n, 1);
	int sum = n;
	int ind = 0;
	int biggest = 0;
	while(sum%k || sum/k < biggest){
		v[ind]+=2;
		biggest = max(biggest, v[ind++]);
		ind %= n;
		sum += 2;
	}

	vector<pii> ps;
	forn(i, n){
		ps.pb(mp(v[i], i));
	}

	forn(i, sum/k){
		sort(ps.begin(), ps.end(), [](pii a, pii b){return b<a;});
		cout << "? ";
		forn(j, k){
			cout << ps[j].s+1 << " ";
			ps[j].f--;
		}
		cout << endl;
		ll x;
		cin >> x;
		ans ^= x;
	}
	cout << "! " << ans << endl;
}