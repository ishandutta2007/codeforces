#include <bits/stdc++.h>
using namespace std;

bitset <10010> a[60];
vector <int> from[60];
int in[60];

int main(){
	int m, n; scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++){
		int s; scanf("%d", &s);
		while (s--){
			int x; scanf("%d", &x);
			a[i].set(x);
		}
	}
	for (int i = 0; i < m; i++){
		for (int j = 0; j < m; j++){
			if (((~a[i]) & a[j]) == a[j]){
				from[i].push_back(j);
				in[j]++;
			}
		}
	}
	queue <int> q;
	for (int i = 0; i < m; i++){
		if (!in[i]) q.push(i);
	}
	int tot = 0;
	while (!q.empty()){
		int x = q.front(); q.pop();
		tot++;
		for (int i = 0; i < from[x].size(); i++){
			int v = from[x][i];
			in[v]--;
			if (in[v] == 0) q.push(v);
		}
	}
	if (tot == m) printf("possible\n");
	else printf("impossible\n");
	return 0;
}