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

	int q;
	cin >> q;
	forn(qi, q){
		int n, k;
		cin >> n >> k;
		vector<int> a(k), t(k);
		forn(i, k){
			cin >> a[i]; a[i]--;
		}
		forn(i, k){
			cin >> t[i];
		}

		vector<int> dist(n, -1);
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		forn(i, k){
			pq.push(mp(t[i], a[i]));
		}

		while(!pq.empty()){
			pii top = pq.top(); pq.pop();
			if(dist[top.s] != -1) continue;
			dist[top.s] = top.f;
			if(top.s > 0) pq.push(mp(top.f+1, top.s-1));
			if(top.s < n-1) pq.push(mp(top.f+1, top.s+1));
		}

		forn(i, n){
			cout << dist[i] << " ";
		}cout << "\n";
	}
}