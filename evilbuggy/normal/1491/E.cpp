#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int K = 30;

vector<int> g[N];
int a[N], b[N], sz[N], dead[N], fib[K];

void init(int v, int p){
	sz[v] = 1;
	for(int i : g[v]){
		int u = a[i]^b[i]^v;
		if(u != p){
			init(u, v);
			sz[v] += sz[u];
		}
	}
}

bool dfs(int v, int p, int ind){
	if(ind == 1 || ind == 0)return true;
	for(int i : g[v]){
		int u = a[i]^b[i]^v;
		if(u == p || dead[i])continue;
		if(sz[u] == fib[ind - 1]){
			dead[i] = 1; sz[v] -= sz[u];
			return dfs(v, 0, ind - 2) && dfs(u, 0, ind - 1);
		}
		if(sz[u] == fib[ind - 2]){
			dead[i] = 1; sz[v] -= sz[u];
			return dfs(v, 0, ind - 1) && dfs(u, 0, ind - 2);
		}
	}
	for(int i : g[v]){
		int u = a[i]^b[i]^v;
		if(u == p || dead[i])continue;
		sz[v] -= sz[u];
		sz[u] += sz[v];
		if(dfs(u, v, ind))return true;
		sz[u] -= sz[v];
		sz[v] += sz[u];
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for(int i = 1; i < n; i++){
		cin >> a[i] >> b[i];
		g[a[i]].push_back(i);
		g[b[i]].push_back(i);
	}
	if(n <= 2){
		cout << "YES" << '\n';
		exit(0);
	}
	int ind = -1;
	fib[0] = fib[1] = 1;
	for(int i = 2; i < K; i++){
		fib[i] = fib[i - 1] + fib[i - 2];
		if(fib[i] == n)ind = i;
	}
	if(ind == -1){
		cout << "NO" << '\n';
		exit(0);
	}
	init(1, 0);
	memset(dead, 0, sizeof(dead));
	if(dfs(1, 0, ind)){
		cout << "YES" << '\n';
	}else{
		cout << "NO" << '\n';
	}

	return 0;
}