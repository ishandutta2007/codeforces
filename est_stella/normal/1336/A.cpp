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

int n, k;
vector<int> g[200010];
int p[200010];
int d[200010];
int sum[200010];
vector<int> ans;

void dfs(int x) {
	sum[x] = 1;

	for(auto i : g[x]) {
		if(i == p[x]) continue;

		d[i] = d[x] + 1;
		p[i] = x;

		dfs(i);

		sum[x] += sum[i];
	}

	ans.eb(d[x] - sum[x] + 1);
}

int main() {
	fast;

	cin >> n >> k;

	for(int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;

		g[u].eb(v);
		g[v].eb(u);
	}

	dfs(1);

	sort(all(ans));
	reverse(all(ans));

	ll a = 0;
	for(int i=0; i<k; i++) {
		a += ans[i];
	}

	cout << a << "\n";
}