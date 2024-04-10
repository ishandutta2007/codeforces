#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

///* advent of code
typedef istringstream iss;
#define pb push_back
#define ins insert
#define multiset mset
#define getl(A) getline(cin, A)
//*/

const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;

int dfs(vector<int> g[], int c[], int cur, int col) {
	int res = 0;
	if (c[cur] != col) {
		res++;
	}
	for (int i : g[cur]) {
		res += dfs(g, c, i, c[cur]);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int a;
	vector<int> graph[n];
	for (int i = 1; i < n; i++) {
		cin >> a;
		graph[a-1].push_back(i);
	}
	int c[n];
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	cout << dfs(graph, c, 0, -1) << nl;

	return 0;
}