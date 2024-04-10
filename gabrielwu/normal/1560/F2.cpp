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
		int n, k;
		cin >> n >> k;
		vector<int> dig;
		vector<bool> used(10);
		while(n > 0){
			dig.pb(n%10);
			n/=10;
		}
		reverse(dig.begin(), dig.end());
		int d = dig.size();
		bool g;

		function<bool(int)> ok = [&](int i){
			int uc = 0;
			int best = 0;
			forn(op, 10){
				uc += used[op];
				if(used[op])ckmax(best, op);
			}
			if(uc > k) return false;
			if(g) return true;
			if(i == d) return true;
			if(uc < k) return true;
			if(best < dig[i]) return false;
			if(best > dig[i]) return true;
			if(best == dig[i]) return ok(i+1);

			return false;
		};

		ll x = 0;
		int uc = 0;
		g = false;
		forn(i, d){
			vector<bool> bef = used;
			bool gbef = g;
			for(int j=0; j<10; j++){
				if(j < dig[i] && !g) continue;
				used[j] = true;
				if(j > dig[i]) g = true;
				if(ok(i+1)){
					x *= 10;
					x += j;
					break;
				}
				g = gbef;
				used = bef;
			}
		}
		cout << x << "\n";


		// int uc = 0;
		// ll x = 0;
		// int i = 0;
		// int big = 0;
		// for(; i<d; i++){
		// 	if(uc == k && !used[dig[i]]){
		// 		break;
		// 	}
		// 	x *= 10;
		// 	x += dig[i];
		// 	if(!used[dig[i]]){
		// 		used[dig[i]] = true;
		// 		ckmax(big, dig[i]);
		// 		uc++;
		// 	}
		// }

		// if(i == d || dig[i] < big){
		// 	bool g = false;
		// 	bool works = true;
		// 	for(; i<d; i++){
		// 		forn(op, 10){
		// 			if(used[op]){
		// 				if(g){
		// 					x *= 10;
		// 					x += op;
		// 					break;
		// 				}
		// 				if(op < dig[i]) continue;
		// 				assert(op > dig[i]);
		// 				g = true;
		// 				x *= 10;
		// 				x += op;
		// 				break;
		// 			}
		// 		}
		// 	}
		// 	cout << x << "\n";
		// } else {
		// 	used.assign(10, false);
		// 	uc = 0;
		// 	i = 0;
		// 	x = 0;
		// 	for(; i<d; i++){
		// 		if(uc == k-1 && !used[dig[i]]){
		// 			break;
		// 		}
		// 		x *= 10;
		// 		x += dig[i];
		// 		if(!used[dig[i]]){
		// 			used[dig[i]] = true;
		// 			ckmax(big, dig[i]);
		// 			uc++;
		// 		}
		// 	}
		// 	assert(i != d);
		// 	if(used[dig[i]+1]){
		// 		used[0] = true;
		// 	}
		// 	used[dig[i]+1] = true;
		// 	x*= 10;
		// 	x += dig[i]+1;
		// 	i++;
		// 	for(; i<d; i++){
		// 		forn(op, 10){
		// 			if(used[op]){
		// 				x *= 10;
		// 				x += op;
		// 				break;
		// 			}
		// 		}
		// 	}
		// 	cout << x << "\n";
		// }


	}
}