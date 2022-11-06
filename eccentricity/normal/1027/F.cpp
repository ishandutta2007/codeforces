#include<bits/stdc++.h>
#define maxn 2400000 
using namespace std;
typedef long long LL;
int v[maxn], vsize;
map<int, int> m;
int a[maxn], b[maxn];
vector<int> G[maxn];
int cc[maxn], cc_cnt;
int edge[maxn];
vector<int> CC[maxn];
void DFS(int u){
	cc[u] = 1;
	CC[cc_cnt].push_back(v[u]);
	edge[cc_cnt] += G[u].size();
	for(int v: G[u]) if(cc[v] == 0) DFS(v);
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i += 1){
		scanf("%d %d", a + i, b + i);
		v[vsize ++] = a[i];
		v[vsize ++] = b[i];
	}
	sort(v, v + vsize);
	vsize = unique(v, v + vsize) - v;
//	for(int i = 0; i < vsize; i += 1){
//		printf("v[%d] = %d\n", i, v[i]);
//	}
	for(int i = 0; i < vsize; i += 1) m[v[i]] = i;
	for(int i = 0; i < n; i += 1){
		G[m[a[i]]].push_back(m[b[i]]);
		G[m[b[i]]].push_back(m[a[i]]);
	}
	for(int i = 0; i < vsize; i += 1)
		if(cc[i] == 0){
			cc_cnt += 1;
			DFS(i);
		}
	int ans = 0;
	for(int i = 1; i <= cc_cnt; i += 1){
		//printf("%d : %d %d\n", i, CC[i].size(), edge[i]);
		//for(int v: CC[i]) printf("%d ", v); printf("\n");
		sort(CC[i].begin(), CC[i].end(), greater<int>());
		if(CC[i].size() == edge[i] / 2){
			ans = max(ans, CC[i][0]);
		}
		else if(CC[i].size() == edge[i] / 2 + 1){
			ans = max(ans, CC[i][1]);
		}
		else{
			printf("-1");
			return 0;
		}
	}
	printf("%d", ans);
}