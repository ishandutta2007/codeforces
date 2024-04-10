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

	int t;
	cin >> t;
	forn(ti, t){
		int n;
		cin >> n;
		vector<bool> v(n);
		forn(i, n){
			char c;
			cin >> c;
			v[i] = (c == '1');
		}

		int e=0, o=0;
		forn(i, n/2){
			if(!(v[i]||v[n-1-i])) e++;
			else if(v[i]^v[n-1-i]) o++;
		}
		int c = 0;
		forn(i, n) c += !v[i];
		int a = 0;

		assert(o == 0);
		if(n%2 && !v[n/2]){
			a = (e > 1 ? e : 1);
		}else{
			if(e) a = e+1;
		}
		// if(n%2 &&  !v[n/2]){
		// 	if(e%2 && o==0){
		// 		a = 2*(e/2)+1;
		// 	} else if(e%2 && o>0){
		// 		a = 2*((e+1)/2);
		// 	} else {
		// 		a = e+1;
		// 	}
		// } else {
		// 	if(o == 0){
		// 		a = 2*((e+1)/2);
		// 	} else {
		// 		a = min(2*((e+1)/2), 2*(e/2)+1);
		// 	}
		// }

		if(a > c-a){
			cout<< "BOB";
		} else if(a < c-a){
			cout << "ALICE";
		} else {
			cout << "DRAW";
		}
		cout << "\n";
	}
}