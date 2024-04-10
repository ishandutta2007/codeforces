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

	int t;
	cin >> t;

	const int FIB = 70;
	vector<ll> fib(FIB);
	fib[0] = 1;
	fib[1] = 1;
	for(int i = 2; i < FIB; i++) {
		fib[i] = fib[i-1] + fib[i-2];
	}

	forn(ti, t) {
		int k; cin >> k;
		vector<ll> v(k);
		ll sm = 0;
		forn(i, k){
			cin >> v[i];
			sm += v[i];
		}

		int ind = 0;
		ll curr = 0;
		while(curr < sm) {
			curr += fib[ind];
			ind++;
		}

		// cout << curr << " " << sm << endl;

		if(curr > sm) {
			cout << "No\n";
			continue;
		}
		assert(curr == sm);
		bool works = true;
		int bef = -1;
		for(int i = ind-1; i>=0; i--) {
			// cout << v << "\n";
			vector<pll> good;
			forn(j, k) {
				if(v[j] >= fib[i] && j != bef) {
					good.pb({v[j], j});
				}
			}
			if(good.size() == 0) {
				works = false;
				// cout << "HERE" << endl;
				break;
			}
			sort(good.begin(), good.end());
			v[good.back().s] -= fib[i];
			bef = good.back().s;
		}
		if(works) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
}