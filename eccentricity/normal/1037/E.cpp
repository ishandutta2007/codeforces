#include<bits/stdc++.h>
#define maxn 240000
using namespace std;
typedef long long LL;
set<int> G[maxn];
set<int> LEF;
queue<int> DEL;
int deg[maxn], u[maxn], v[maxn], ans[maxn];
void DELET(int k){
	while(DEL.empty() == false){
		int u = DEL.front();
		DEL.pop();
		for(int v: G[u])
			if(LEF.count(v)){
				G[v].erase(u);
				if(-- deg[v] < k){
					LEF.erase(v);
					DEL.push(v);
				} 
			}
	}
}
int main(){
	int n, m, k;
	scanf("%d %d %d", &n ,&m, &k);
	for(int i = 0; i < m; i += 1){
		scanf("%d %d", u + i, v + i);
		G[u[i]].insert(v[i]);
		G[v[i]].insert(u[i]);
		deg[u[i]] += 1;
		deg[v[i]] += 1;
	}
	for(int i = 1; i <= n; i += 1){
		LEF.insert(i);
		if(deg[i] < k){
			LEF.erase(i);
			DEL.push(i);
		}
	}
	DELET(k);
	for(int i = m - 1; i >= 0; i -= 1){
		ans[i] = LEF.size();
		if(LEF.count(u[i]) && LEF.count(v[i])){
			G[v[i]].erase(u[i]);
			G[u[i]].erase(v[i]);
			if(-- deg[v[i]] < k){
				LEF.erase(v[i]);
				DEL.push(v[i]);
			}
			if(-- deg[u[i]] < k){
				LEF.erase(u[i]);
				DEL.push(u[i]);
			}
		}
		//for(int i = 1; i <= n; i += 1) printf("deg[%d] = %d ", i, deg[i]); printf("\n");
		DELET(k);
	}
	for(int i = 0; i < m; i += 1) printf("%d\n", ans[i]);
}