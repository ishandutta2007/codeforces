#include <bits/stdc++.h>
using namespace std;

const int maxN = 555555;
const int mod = 1000000007;

long long c[maxN];
int a[maxN], b[maxN], par[maxN], power2[maxN];

inline void add(int &x, int y){
	x += y; if(x >= mod)x -= mod;
}

void init(){
	power2[0] = 1;
	for(int i = 1; i < maxN; i++){
		power2[i] = power2[i - 1] << 1;
		if(power2[i] >= mod)power2[i] -= mod;
	}
}

int find(int v){
	return (par[v] < 0)?v:(par[v] = find(par[v]));
}

bool combine(int u, int v){
	u = find(u);
	v = find(v);
	if(u == v){
		return false;
	}
	if(par[u] > par[v])swap(u, v);
	par[u] += par[v]; par[v] = u;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();
	
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	map<long long, vector<int> > xorEdges;
	for(int i = 1; i <= m; i++){
		cin >> a[i] >> b[i];
		xorEdges[c[a[i]]^c[b[i]]].emplace_back(i);
	}
	int ans = power2[n + k];
	memset(par, -1, sizeof(par));
	for(auto x : xorEdges){
		vector<int> vec = x.second;
		
		int cnt = n;
		for(auto i : vec){
			if(combine(a[i], b[i]))cnt--;
		}
		add(ans, power2[cnt]);
		add(ans, mod - power2[n]);
		for(int i : vec){
			par[a[i]] = par[b[i]] = -1;
		}
	}
	cout << ans << '\n';

	return 0;
}