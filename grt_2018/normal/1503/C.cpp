#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

//#pragma GCC optimize ("O3")
//#pragma GCC target("tune=native")

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

const int nax = 1e5 + 10;
const ll INF = 1e18;
int n, nr;
pi a[nax];
map<int,int>sc;
vector<pi>V[2 * nax];
ll ans = 0;
ll dist[2 * nax];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].ST >> a[i].ND;
		sc[a[i].ST];
		sc[a[i].ST + a[i].ND];
		ans += a[i].ND;
	}
	sort(a + 1, a + n + 1);
	int last = -1;
	for(auto &it : sc) {
		it.ND = ++nr;
		if(last != -1) {
			//cout << nr - 1 << " " << nr << ": " << it.ST - last << "\n";
			V[nr - 1].emplace_back(nr, it.ST - last);
			V[nr].emplace_back(nr - 1, 0);
		}
		last = it.ST;
	}
	for(int i = 1; i <= n; ++i) {
		V[sc[a[i].ST]].emplace_back(sc[a[i].ST + a[i].ND], 0);
	}
	priority_queue<pair<ll,int>>PQ;
	PQ.push({0,1});
	for(int i = 1; i <= nr; ++i) dist[i] = INF;
	dist[1] = 0;
	while(!PQ.empty()) {
		pair<ll,int>tp = PQ.top();
		PQ.pop();
		tp.ST = -tp.ST;
		if(dist[tp.ND] != tp.ST) continue;
		for(auto nbh : V[tp.ND]) {
			if(dist[nbh.ST] > tp.ST + nbh.ND) {
				dist[nbh.ST] = tp.ST + nbh.ND;
				PQ.push({-dist[nbh.ST], nbh.ST});
			}
		}
	}
	//for(int i = 1; i <= nr; ++i) {
		//cout << dist[i] << " ";
	//}
	//cout << "\n";
	ll mi = INF;
	for(int i = sc[a[n].ST]; i <= nr; ++i) {
		mi = min(mi, dist[i]);
	}
	//cout << mi << "\n";
	ans += mi;
	cout << ans;
}