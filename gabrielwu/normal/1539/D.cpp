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

	int n;
	cin >> n;

	vector<ll> a(n), b(n);
	forn(i, n){
		cin >> a[i] >> b[i];
	}

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	forn(i, n){
		pq.push(mp(b[i], i));
	}

	vector<int> order(n);
	forn(i, n){
		order[i] = i;
	}
	sort(order.begin(), order.end(), [&](int x, int y){return b[x] > b[y];});

	ll curr = 0;
	ll ans = 0;
	int oi = 0;
	while(oi < n){
		if(!pq.empty() && pq.top().f <= curr){
			int i = pq.top().s;
			pq.pop();
			ll use = a[i];
			a[i] = 0;
			ans += use;
			curr += use;
		}else{
			if(a[order[oi]] == 0) oi++;
			else{
				ll use = (pq.empty() ? a[oi] : min(a[order[oi]], pq.top().f - curr));
				a[order[oi]] -= use;
				ans += 2*use;
				curr += use;
			}
		}
		// cout << a << " " << b << " " << curr << " " << ans << " " << "\n";
	}

	cout << ans << "\n";

}