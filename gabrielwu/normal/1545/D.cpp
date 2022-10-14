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

	int m, k;
	cin >> m >> k;
	vector<vector<ll>> v(k, vector<ll>(m));
	vector<ll> sum(k), sum2(k);
	forn(i, k){
		forn(j, m){
			cin >> v[i][j];
			sum[i] += v[i][j];
			sum2[i] += v[i][j] * v[i][j];
		}
	}

	vector<ll> diff(k-1);
	forn(i, k-1){
		diff[i] = sum[i+1] - sum[i];
	}

	bool onside = true;
	int bad = -1;
	ll delta;
	for(int i=1; i<k-3; i++){
		if(diff[i] != diff[i+1]){
			onside = false;
		}
	}
	// cout << onside << endl;


	if(onside){
		if(diff[0] != diff[1]){
			bad = 0;
			delta = diff[1] - diff[0];
		}
		else{
			bad = k-1;
			delta = diff[k-2] - diff[k-3];
		}
	}else{
		if(diff[0] == diff[1]){
			for(int i=2; i<k-2; i++){
				if(diff[i] != diff[0]){
					bad = i+1;
					delta = diff[i] - diff[0];
					break;
				}
			}
		}else{
			if(diff[2] == diff[3]){
				bad = 1;
				delta = diff[0] - diff[2];
			}else{
				bad = 2;
				delta = diff[1] - diff[0];
			}
		}
	}
	// cout << "HERE " << bad << endl;

	function<bool(vector<ll>)> quad = [](vector<ll> x){
		int n = x.size();
		vector<ll> diff(n-1), diff2(n-2);
		forn(i, n-1){
			diff[i] = x[i+1] - x[i];
		}
		forn(i, n-2){
			diff2[i] = diff[i+1] - diff[i];
		}
		bool works = true;
		forn(i, n-3){
			works &= diff2[i] == diff2[i+1];
		}
		return works;
	};

	int ans = 0;
	forn(i, m){
		ll change = 2*v[bad][i]*(-delta) + delta*delta;
		sum2[bad] += change;
		if(quad(sum2)) ans = v[bad][i] - delta;
		sum2[bad] -= change;
	}
	cout << bad << " " << ans << endl;

}

/*
5 7
1 2 3 4 5
2 3 4 5 6
3 4 5 6 7
4 5 6 7 8
5 6 7 8 9
6 7 8 9 10
7 8 9 10 1
*/