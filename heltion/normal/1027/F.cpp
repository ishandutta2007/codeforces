#include<bits/stdc++.h>
#define maxn 2400000
using namespace std;
int a[maxn], b[maxn];
int v[maxn], vsize;
unordered_map<int, int> um;
vector<int> G[maxn];
bool vis[maxn];
int vertex, degree, firmax, secmax;
void DFS(int x){
	vis[x] = true;
	vertex += 1;
	degree += G[x].size();
	if(v[x] > firmax){
		secmax = firmax;
		firmax = v[x];
	}
	else if(v[x] > secmax) secmax = v[x];
	for(int y: G[x]) if(vis[y] == false) DFS(y);
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0, *p = v; i < n; i += 1){
		scanf("%d", a + i);
		scanf("%d", b + i);
		*p ++ = a[i];
		*p ++ = b[i];
	}
	sort(v, v + 2 * n);
	vsize = unique(v, v + 2 * n) - v;
	for(int i = 0; i < vsize; i += 1) um[v[i]] = i;
	for(int i = 0; i < n; i += 1){
		G[um[a[i]]].push_back(um[b[i]]);
		G[um[b[i]]].push_back(um[a[i]]);
	}
	int ans = 0;
	for(int i = 0; i < vsize; i += 1) if(vis[i] == 0){
		vertex = firmax = secmax = degree = 0;
		DFS(i);
		if(degree / 2 > vertex){
			printf("-1");
			return 0;
		}
		if(degree / 2 == vertex) ans = max(ans, firmax);
		else ans = max(ans, secmax);
	}
	printf("%d", ans);
}