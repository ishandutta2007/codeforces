#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 200005;
int vis[N];
vector<int> vislist;
int arr[N], mu[N], lpf[N];
vector<int> g[N], fac[N], fl[N];
ll cnt[N];

void pre(){
	mu[1] = 1;
	memset(lpf, -1, sizeof(lpf));
	for(int n = 2; n < N; n++){
		if(lpf[n] == -1){
			for(int m = n; m < N; m += n){
				if(lpf[m] == -1)lpf[m] = n;
			}
		}
		int x = n/lpf[n];
		if(x%lpf[n] == 0)mu[n] = 0;
		else mu[n] = -mu[x];
	}
	for(int n = 1; n < N; n++){
		for(int m = n; m < N; m += n){
			fac[m].push_back(n);
		}
	}
}

int dfs(int v, int x){
	if(vis[v] == 1)return 0;
	vis[v] = 1;
	vislist.push_back(v);
	int ret = 1;
	for(auto u : g[v]){
		if(arr[u]%x == 0)ret += dfs(u, x);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	pre();
	int n, x, u, v;
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>x;
		for(auto y : fac[x]){
			fl[y].push_back(i);
		}
		arr[i] = x;
	}
	for(int i = 1; i < n; i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(vis, 0, sizeof(vis));
	for(int x = 1; x < N; x++){
		cnt[x] = 0;
		for(auto v : fl[x]){
			int tmp = dfs(v, x);
			cnt[x] += 1LL*tmp*(tmp + 1)/2;
		}
		for(auto v : vislist){
			vis[v] = 0;
		}
		vislist.clear();
	}
	for(int x = 1; x < N; x++){
		ll ans = 0;
		for(int y = x; y < N; y += x){
			ans += mu[y/x]*cnt[y];
		}
		if(ans > 0)cout<<x<<" "<<ans<<'\n';
	}

	return 0;
}