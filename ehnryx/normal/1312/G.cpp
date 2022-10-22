//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-11;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

template <class T> struct min_stack : public stack<T> {
  stack<T> mins; // vals stored in stack inherited from the STL stack
  int mins_top() { return (mins.empty() ? INF : mins.top()); }
  void push(int x) { mins.push(min(x, mins_top())); stack<T>::push(x); }
  int pop() { mins.pop(); int x=stack<T>::top(); stack<T>::pop(); return x; }
  int minimum() { return mins_top(); }
};

const int N = 1e6 + 1;
const int M = 26;
int adj[N][M];
int depth[N], order[N];
int ans[N];
bool add[N];
int dp[N];

min_stack<int> ost;

void build(int u, int& id) {
	id += add[u];
	order[u] = id;
	if(add[u]) {
		dp[u] = min(dp[u], ost.minimum() + order[u]);
	}
	ost.push(dp[u] - order[u] + add[u]);
	for(int i=0; i<M; i++) {
		if(!adj[u][i]) continue;
		depth[adj[u][i]] = depth[u] + 1;
		dp[adj[u][i]] = dp[u] + 1;
		build(adj[u][i], id);
	}
	ost.pop();
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		int p; char c;
		cin >> p >> c;
		adj[p][c-'a'] = i;
	}

	int m;
	cin >> m;
	for(int i=0; i<m; i++) {
		cin >> ans[i];
		add[ans[i]] = true;
	}

	int id = 0;
	build(0, id);

	for(int i=0; i<m; i++) {
		cout << dp[ans[i]] << " ";
	}
	cout << nl;

	return 0;
}