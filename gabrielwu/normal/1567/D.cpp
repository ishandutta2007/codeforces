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
		ll s, n;
		cin >> s >> n;
		int N = n;

		const int LG = 10;
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		int oc = 0;

		vector<int> digs(LG);
		int x = s;
		int ds = 0;
		forn(i, LG){
			digs[i] = x%10;
			ds += digs[i];
			x /= 10;
		}

		int it = 0;
		while(n > 1){
			while(digs[it] == 0){
				it++;
				if(it == LG) break;
			}
			if(it == LG) break;

			s -= pow(10, it);
			if(it == 0) oc++;
			else pq.push(pow(10, it));
			digs[it]--;
			n--;
		}
		// cout << n << endl;

		// assert(1 == 0);
		if(s){
			assert(n == 1);
			pq.push(s);
			n = 0;
		} else {
			while(n > 0){
				ll x = pq.top(); pq.pop();
				int len = 0;
				ll p = 1;
				while(p < x){
					len++; p*=10;
				}

				// cout << x << " "<< len << endl;
				assert(x == pow(10, len));
				if(n >= 9){
					n -= 9;
					if(len == 1){
						oc += 10;
					} else {
						forn(i, 10) pq.push(pow(10, len-1));
					}
				} else {
					forn(i, n){
						pq.push(pow(10, len-1));
					}
					pq.push(pow(10, len) - pow(10, len-1)*n);
					n = 0;
				}
			}
		}

		assert(oc + pq.size() == N);
		while(!pq.empty()){
			cout << pq.top() << " ";
			pq.pop();
		}
		forn(i, oc){
			cout << 1 << " ";
		}
		cout << "\n";
	}
}