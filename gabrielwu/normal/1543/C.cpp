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

	int t;
	cin >> t;
	cout << setprecision(16);
	lld EPS = 1e-16;
	forn(ti, t){
		lld c, m, p, v;
		cin >> c >> m >> p >> v;
		lld tot = 1;
		for(int i=1; i<=18; i++){
			forn(b, 1<<i){
				int x = b;
				lld curr = 1;
				lld C=c, M=m, P=p;
				forn(j, i){
					if(curr < EPS) break;
					if(x%2){
						curr *= max((lld) 0, C);
						if(C > v+EPS){
							C -= v;
							if(M > -0.5){
								M += v/2;
								P += v/2;
							}else{
								P += v;
							}
						}else if(C > -.5){
							if(M > -0.5){
								M += C/2;
								P += C/2;
							}else{
								P += C;
							}
							C = -1;
						}
					} else {
						curr *= max((lld) 0, M);
						if(M > v+EPS){
							M -= v;
							if(C > -0.5){
								C += v/2;
								P += v/2;
							}else{
								P += v;
							}
						}else if(M > -.5){
							if(C > -0.5){
								C += M/2;
								P += M/2;
							}else{
								P += M;
							}
							M = -1;
						}
					}
					x /= 2;
				}
				curr *= P;
				// cout << curr << " " << i << " " << b << "\n";
				tot += curr * i;
			}
		}

		cout << setprecision(16) << tot << "\n";
	}
}