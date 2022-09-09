#include<bits/stdc++.h>
#define maxm 120
using namespace std;
bool vis[maxm];
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i += 1){
		int l, r;
		scanf("%d %d", &l, &r);
		for(int j = l; j <= r; j += 1) vis[j] = true;
	}
	vector<int> ans;
	for(int i = 1; i <= m; i += 1)
		if(vis[i] == false) ans.push_back(i);
	printf("%d\n", ans.size());
	for(auto u: ans) printf("%d ", u);
}