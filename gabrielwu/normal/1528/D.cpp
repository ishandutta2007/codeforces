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

	int n, m;
	cin >> n >> m;

	vector<vector<int>> cann(n, vector<int>(n, 2*MOD));
	forn(i, m){
		int a, b, c;
		cin >> a >> b >> c;
		cann[a][b] = c;
	}

	forn(i, n){
		int curr = cann[i][0];
		forn(j, n){
			ckmin(cann[i][j], curr);
			ckmin(curr, cann[i][j]);
			curr++;
		}
		forn(j, n){
			ckmin(cann[i][j], curr);
			ckmin(curr, cann[i][j]);
			curr++;
		}
	}
	// cout << cann << "\n";

	forn(u, n){
		vector<int> dist(n, 2*MOD);
		vector<bool> vis(n);
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		pq.push(mp(0, u));
		dist[u] = 0;
		int unvis = n;
		while(unvis){
			int d = pq.top().f, x = pq.top().s;
			pq.pop();

			if(vis[x]) continue;
			vis[x] = true;
			// if(d > dist[x]) continue;
			unvis--;

			forn(i, n){
				// cout << "Push " <<mp(d+cann[x][i], (i+d)%n) << "\n";
				int val = d + cann[x][i], node = (i+d)%n;
				if(ckmin(dist[node], val)) pq.push(mp(val, node));
			}
		}

		forn(i, n){
			cout << dist[i] << " ";
		}cout << "\n";
	}
}