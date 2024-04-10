#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// DON'T USE THESE MACROS DURING ICPC PRACTICE
#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct Node {
	int i; ll d;
	bool operator < (const Node& o) const {
		return d > o.d;
	}
};

const int N = 2e5+1;
vector<int> row[N];
int safe[N];
int r[N], c[N], o[N];
vector<int> adj[N];
ll dist[N];

int getd(int i, int j, int k) {
	if (r[i] == r[j]) {
		return abs(c[i] - o[j]) + abs(o[j] - c[j]);
	} else {
		int res = INF;
		int* it = lower_bound(safe, safe+k, c[i]);
		if (it != safe+k) {
			res = min(res, abs(c[i] - *it) + abs(*it - o[j]) + abs(o[j] - c[j]));
		}
		if (it != safe) {
			--it;
			res = min(res, abs(c[i] - *it) + abs(*it - o[j]) + abs(o[j] - c[j]));
		}
		return res + abs(r[j]-r[i]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, m, k, q;
	cin >> n >> m >> k >> q;

	For(i,k) {
		int a, b;
		cin >> a >> b;
		row[a].push_back(b);
	}

	For(i,q) {
		cin >> safe[i];
	}
	sort(safe, safe+q);

	int id = 0;
	r[id] = c[id] = 1;
	vector<int> pre = { 0 };
	FOR(i,1,n) {
		if (row[i].empty()) {
			continue;
		} else if (row[i].size() == 1) {
			++id;
			r[id] = i;
			c[id] = row[i].front();
			o[id] = c[id];
			for (int j : pre) {
				adj[j].push_back(id);
			}
			pre = { id };
		} else {
			sort(row[i].begin(), row[i].end());
			++id;
			r[id] = i;
			c[id] = row[i].front();
			o[id] = row[i].back();
			++id;
			r[id] = i;
			c[id] = row[i].back();
			o[id] = row[i].front();
			for (int j : pre) {
				adj[j].push_back(id);
				adj[j].push_back(id-1);
			}
			pre = { id-1, id };
		}
	}

	memset(dist, -1, sizeof dist);
	priority_queue<Node> dijk;
	dijk.push({0,0});
	while (!dijk.empty()) {
		Node cur = dijk.top();
		dijk.pop();
		if (dist[cur.i] == -1) {
			dist[cur.i] = cur.d;
			for (int v : adj[cur.i]) {
				dijk.push({v, cur.d + getd(cur.i, v, q)});
			}
		}
	}
	cout << min(dist[pre.front()], dist[pre.back()]) << nl;

	return 0;
}