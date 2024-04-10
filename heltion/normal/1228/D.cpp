//Author: Heltion
//Date: 09-29-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 120000;
set<int> G[maxn];
int c[maxn], cnt[4];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, m;
	cin >> n >> m;
	for(int i = 1, u, v; i <= m; i += 1){
		cin >> u >> v;
		G[u].insert(v);
		G[v].insert(u);
	}
	int r1 = 0;
	for(int i = 1; i <= n; i += 1) if(not c[i]){
		r1 = i;
		break;
	}
	for(int i = 1; i <= n; i += 1) if(not G[r1].count(i)){
		c[i] = 1;
		cnt[1] += 1;
	}
	int r2 = 0;
	for(int i = 1; i <= n; i += 1) if(not c[i]){
		r2 = i;
		break;
	}
	if(not r2) no(-1);
	for(int i = 1; i <= n; i += 1) if(not G[r2].count(i)){
		c[i] = 2;
		cnt[2] += 1;
	}
	int r3 = 0;
	for(int i = 1; i <= n; i += 1) if(not c[i]){
		r3 = i;
		break;
	}
	if(not r3) no(-1);
	for(int i = 1; i <= n; i += 1) if(not G[r3].count(i)){
		c[i] = 3;
		cnt[3] += 1;
	}
	if(cnt[1] + cnt[2] + cnt[3] != n) no(-1);
	for(int i = 1; i <= n; i += 1){
		for(int j : G[i]) if(c[i] == c[j]) no(-1);
		if(cnt[c[i]] + (int)G[i].size() != n) no(-1);
	}
	for(int i = 1; i <= n; i += 1) cout << c[i] << " ";
	return 0;
}