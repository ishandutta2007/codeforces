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

	function<bool(int,int,int)> ask = [](int i, int j, int k){
		assert(i != j && i != k && j != k);
		cout << "? " << i+1 << " " << j+1 << " " << k+1 << endl;
		int x;
		cin >> x;
		return (x == 1);
	};

	int t;
	cin >> t;
	forn(ti, t){
		int n;
		cin >> n;

		int bt = -1, wt = -1, bi = -1, wi = -1;
		vector<int> trip(n/3, -1);
		forn(i, n/3){
			trip[i] = ask(3*i, 3*i+1, 3*i+2);
			if(trip[i]){
				bt = i;
			} else {
				wt = i;
			}
			if(bt >= 0 && wt >= 0){
				break;
			}
		}

		vector<int> ans(n, -1);
		//The 6 technique
		if(ask(3*bt, 3*bt+1, 3*wt)){
			if(ask(3*bt, 3*bt+1, 3*wt+1)){
				if(ask(3*bt, 3*wt, 3*wt+1)){
					bi = 3*bt;
					wi = 3*wt+2;
				} else {
					bi = 3*bt;
					wi = 3*wt;
				}
			} else {
				bi = 3*bt+2;
				wi = 3*wt+1;
			}
		} else {
			bi = 3*bt+2;
			wi = 3*wt;
		}

		ans[bi] = 1;
		ans[wi] = 0;
		forn(i, n/3){
			if(trip[i] == -1){
				ans[3*i] = ask(bi, wi, 3*i);
				ans[3*i+1] = ask(bi, wi, 3*i+1);
				ans[3*i+2] = ask(bi, wi, 3*i+2);
			} else if(i == bt){
				if(3*i != bi) ans[3*i] = ask(bi, wi, 3*i);
				if(3*i+1 != bi) ans[3*i+1] = ask(bi, wi, 3*i+1);
				if(3*i+2 != bi) ans[3*i+2] = ask(bi, wi, 3*i+2);
			} else if(i == wt){
				if(3*i != wi) ans[3*i] = ask(bi, wi, 3*i);
				if(3*i+1 != wi) ans[3*i+1] = ask(bi, wi, 3*i+1);
				if(3*i+2 != wi) ans[3*i+2] = ask(bi, wi, 3*i+2);
			} else {
				if(trip[i] == 0){
					if(ask(3*i, 3*i+1, bi) == 0){
						ans[3*i] = 0;
						ans[3*i+1] = 0;
						ans[3*i+2] = ask(3*i+2, bi, wi);
					} else {
						ans[3*i+2] = 0;
						ans[3*i] = ask(3*i, bi, wi);
						ans[3*i+1] = 1 - ans[3*i];
					}
				} else {
					if(ask(3*i, 3*i+1, wi) == 1){
						ans[3*i] = 1;
						ans[3*i+1] = 1;
						ans[3*i+2] = ask(3*i+2, bi, wi);
					} else {
						ans[3*i+2] = 1;
						ans[3*i] = ask(3*i, bi, wi);
						ans[3*i+1] = 1 - ans[3*i];
					}

				}
			}
		}

		int k = 0;
		forn(i, n){
			if(ans[i] == 0) k++;
		}
		cout << "! " << k << " ";
		forn(i, n){
			if(ans[i] == 0) cout << i+1 << " ";
		}
		cout << endl;
	}
}