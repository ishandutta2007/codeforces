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
		int n, l, r;
		cin >> n >> l >> r;
		vector<int> counts(n);
		forn(i, l){
			int x;
			cin >> x;
			x--;
			counts[x]++;
		}
		int pairs = 0, odds = 0, lpairs=0, rpairs=0;
		forn(i, r){
			int x;
			cin >> x;
			x--;
			if(counts[x] > 0) pairs++;
			counts[x]--;
		}
		forn(i, n){
			odds += counts[i]%2;
			if(counts[i] < 0){
				rpairs += -counts[i]/2;
			}else{
				lpairs += counts[i]/2;
			}
		}
		if(odds < 0){
			cout << n/2-pairs+max(-odds/2 - lpairs, 0) << "\n";
		}else{
			cout << n/2-pairs+max(odds/2 - rpairs, 0) << "\n";

		}
	}	
}