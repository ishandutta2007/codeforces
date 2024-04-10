#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)
#define mp make_pair
  
typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const long long INF = 1e18;  
const int inf = 1e9;

int n;
vector<int> g[200010];
int d[200010];

void dfs(int x, int p) {
	for(auto i : g[x]) {
		if(i == p) continue;

		d[i] = d[x] + 1;
		dfs(i, x);
	}
}

int main() {
	fast;

	cin >> n;

	for(int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;

		g[u].eb(v);
		g[v].eb(u);
	}

	dfs(1, 0);

	int cnt = 0;
	for(int i=1; i<=n; i++) {
		if(d[i] % 2 == 0) cnt++;
	}

	cout << min(cnt, n-cnt) - 1 << "\n";
}