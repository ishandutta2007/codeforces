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
		ll a, b, c;
		cin >> n >> a >> b >> c;
		vector<bool> v(n);
		forn(i, n){
			char c;
			cin >> c;
			v[i] = (c == '1');
		}
		int op1 = 0, op2 = 0;
		forn(i, n-1){
			if(v[i] == v[i+1]){
				if(v[i]){
					op2++;
				} else {
					op1++;
				}
			}
		}

		vector<int> p;
		int curr = -1;
		forn(i, n){
			if(v[i]){
				if(curr > 0){
					p.pb(curr-1);
				}
				curr = 0;
			} else {
				if(curr > -1) curr++;
			}
		}

		p.pb(MOD);

		sort(p.begin(), p.end());

		ll ans;
		if(c >= b){
			if(op1 > op2){
				ans = (op2+1)*a + op2*b;
			} else if(op2 > op1){
				ans = (op1+1)*b + op1*a;
			} else {
				ans = op1*a + op2*b;
			}
		} else {
			if(op1 > op2){
				ans = (op2+1)*a + op2*b;
				int primed = 0;
				int left = op2;
				while(left >= p[primed]){
					left -= p[primed];
					primed++;
				}
				ans += (b-c)*primed;
			} else if(op2 > op1){
				ans = (op1+1)*b + op1*a;
				int primed = 0;
				int left = op1;
				while(left >= p[primed]){
					left -= p[primed];
					primed++;
				}
				if(op2 == op1+2){
					if(v[0] == 0 || v[n-1] == 0){
						ans += b-c;
					}
				} else if(op2 >= op1+3) {
					if(v[0] == 0 || v[n-1] == 0){
						ans += b-c;
					}
					if(v[0] == 0 && v[n-1] == 0){
						ans += b-c;
					}
				}
				ans += (b-c)*primed;
			} else {
				ans = op1*a + op2*b;
				int primed = 0;
				int left = op1;
				while(left >= p[primed]){
					left -= p[primed];
					primed++;
				}
				ans += (b-c)*primed;

			}
		}

		cout << ans << "\n";
	}
}