#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define maxn 320000
int f[maxn], L[maxn], R[maxn];
int getf(int u){
	return u == f[u] ? u : f[u] = getf(f[u]);
}
void DFS(int u){
	if(not L[u]) cout << u << " ";
	else{
		DFS(L[u]);
		DFS(R[u]);
	}
}
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1) f[i] = i;
	for(int i = 1; i < n; i += 1){
		int u, v;
		cin >> u >> v;
		int fu = getf(u), fv = getf(v);
		L[n + i] = fu, R[n + i] = fv;
		f[n + i] = f[fu] = f[fv] = n + i;
	}
	DFS(2 * n - 1);
}