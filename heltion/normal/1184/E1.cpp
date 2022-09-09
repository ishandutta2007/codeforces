//Author: Heltion
//Date: 07-31-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 1200000;
int pa[maxn];
int getpa(int u){
	return u == pa[u] ? u : pa[u] = getpa(pa[u]);
}
struct edge{
	int u, v, w;
	bool operator < (const edge &b){
		return w < b.w;
	}
}e[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i += 1) pa[i] = i;
	for(int i = 0; i < m; i += 1) cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e + 1, e + m);
	int ans = 0;
	for(int i = 1; i < m; i += 1){
		if(getpa(e[0].u) != getpa(e[0].v)) ans = e[i].w;
		pa[getpa(e[i].u)] = getpa(e[i].v);
	}
	if(getpa(e[0].u) != getpa(e[0].v)) ans = 1e9;
	cout << ans;
	return 0;
}