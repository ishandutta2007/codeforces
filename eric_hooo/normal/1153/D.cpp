#include <bits/stdc++.h>
using namespace std;

int a[300010];
vector <int> from[300010];

int dfs(int x){
//	cout << "dfs:" << x << endl;
	if (from[x].size() == 0) return 1;
	int res = a[x] == 0 ? 0 : 0x3f3f3f3f;
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i];
		if (a[x] == 0) res += dfs(v);
		else res = min(res, dfs(v));
	}
	return res;
}

int main(){
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for (int i = 2; i <= n; i++){
		int f; scanf("%d", &f);
		from[f].push_back(i);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		if (!from[i].size()) cnt++;
	}
	printf("%d\n", cnt - dfs(1) + 1);
	return 0;
}