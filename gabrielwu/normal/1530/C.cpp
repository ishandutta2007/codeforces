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
		vector<int> a(n), b(n);
		forn(i, n) cin >> a[i];
		forn(i, n) cin >> b[i];

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int used = n - n/4;
		ll acurr=0, bcurr=0;
		forn(i, used){
			acurr += a[n-i-1];
			bcurr += b[n-i-1];
		}
		int ait = n-used;
		int bit = n-used;
		int ans = 0;
		while(acurr < bcurr){
			// cout << acurr << " " << bcurr << "\n";
			ans++;
			acurr += 100;
			a.pb(100);
			if((n+ans)%4 == 0){
				acurr -= a[ait++];
			}else{
				if(bit > 0){
					bcurr += b[--bit];
				}
			}
		}
		cout << ans << "\n";
	}
}