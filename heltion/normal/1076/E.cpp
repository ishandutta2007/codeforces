#include<bits/stdc++.h>
#define maxn 360000
using namespace std;
typedef long long LL;
vector<int> G[maxn];
vector<pair<int, int> > T[maxn];
LL S[maxn], A[maxn];
int n, m;
void add(int p, int x){
	for(;p <= n; p += p & -p) S[p] += x;
}
void add(int L, int R, int x){
	add(L, x);
	add(R + 1, -x);
}
LL ask(int p){
	LL res = 0;
	for(; p; p -= p & -p) res += S[p];
	return res;
}
void DFS(int u, int d, int f){
	for(auto p: T[u])
		add(d, min(d + p.first, n), p.second);
	A[u] = ask(d);
	for(int v : G[u]) if(v != f) DFS(v, d + 1, u); 
	for(auto p: T[u])
		add(d, min(d + p.first, n), -p.second);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i < n; i += 1){
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	cin >> m;
	for(int i = 0; i < m; i += 1){
		int v, d, x;
		cin >> v >> d >> x;
		T[v].push_back({d, x});
	}
	DFS(1, 1, 0);
	for(int i = 1; i <= n; i += 1) cout << A[i] << " ";
}