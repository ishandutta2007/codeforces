//Author: Heltion
//Date: 07-31-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr LL maxn = 1200;
LL d[maxn][maxn];
LL sx[maxn], a[maxn], f[maxn], bx[maxn], dd[maxn];
vector<int> G[maxn];
LL bb[maxn], x[maxn];
bool find(int u){
	for(int v : G[u]) if(not bb[v]){
		bb[v] = 1;
		if(not x[v] || find(x[v])) return x[v] = u, true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	LL n, m;
	cin >> n >> m;
	for(LL i = 1; i <= n; i += 1)
		for(LL j = 1; j <= n; j += 1) if(i != j) d[i][j] = 1e9;
	for(LL i = 1; i <= m; i += 1){
		LL u, v;
		cin >> u >> v;
		if(u != v) d[u][v] = d[v][u] = 1;
	}
	for(LL k = 1; k <= n; k += 1)
		for(LL i = 1; i <= n; i += 1)
			for(LL j = 1; j <= n; j += 1)
				d[i][j] = min(d[i][j], d[i][k] + d[j][k]);
	LL s, b, k, h;
	cin >> s >> b >> k >> h;
	LL ans = 0;
	for(LL i = 1; i <= s; i += 1)
		cin >> sx[i] >> a[i] >> f[i];
	for(LL i = 1; i <= b; i += 1)
		cin >> bx[i] >> dd[i];
	for(LL i = 1; i <= s; i += 1)
		for(int j = 1; j <= b; j += 1)
			if(d[sx[i]][bx[j]] <= f[i] and a[i] >= dd[j]) 
				G[i].push_back(j);
	for(int i = 1; i <= s; i += 1){
		for(int j = 1; j <= b; j += 1) bb[j] = 0;
		if(find(i)) ans += 1;
	}
	cout << min(ans * k, s * h);
	return 0;
}