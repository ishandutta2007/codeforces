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

	int LG = 20;
	int q;
	cin >> q;
	vector<vector<int>> anc(q+1, vector<int>(LG, -1));
	vector<ll> a(q+1), c(q+1);
	cin >> a[0] >> c[0];

	forn(i, q){
		int type; cin >> type;
		if(type == 1){
			cin >> anc[i+1][0] >> a[i+1] >> c[i+1];
			int pow = 0;
			while(anc[anc[i+1][pow]][pow] != -1){
				anc[i+1][pow+1] = anc[anc[i+1][pow]][pow];
				pow++;
			}
		} else if(type == 2){
			ll v, w;
			cin >> v >> w;
			function<int(int, int)> getanc = [&](int v, int h){
				int pow = 0;
				while(h){
					if(v == -1) return -1;
					if(h%2){
						v = anc[v][pow];
					}
					pow++;
					h/=2;
				}
				return v;
			};

			int lo = -1, hi = i+5;
			while(lo < hi){
				int mid = (lo+hi+1)/2;
				int x = getanc(v, mid);
				if(x == -1 || a[x] == 0){
					hi = mid-1;
				}else{
					lo = mid;
				}
			}
			// cout << lo << "\n";
			ll cost = 0, count = 0;
			while(lo >= 0 && w > 0){
				int x = getanc(v, lo);
				ll use = min(w, a[x]);
				a[x] -= use;
				w -= use;
				cost += use*c[x];
				count += use;
				lo--;
			}
			cout << count << " " << cost << endl;
		}
	}

}