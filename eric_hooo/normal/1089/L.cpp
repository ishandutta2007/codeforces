#include <bits/stdc++.h>
using namespace std;

int a[100010], b[100010];
vector <int> all[100010];
vector <int> v;

bool cmp(int x, int y){
	return b[x] < b[y];
}

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		all[a[i]].push_back(i);
	}
	for (int i = 0; i < n; i++){
		scanf("%d", &b[i]);
	}
	int tot = 0;
	for (int i = 1; i <= k; i++){
		if (all[i].size() == 0){
			tot++;
			continue;
		}
		sort(all[i].begin(), all[i].end(), cmp);
		for (int j = 0; j < all[i].size() - 1; j++){
			v.push_back(all[i][j]);
		}
	}
	sort(v.begin(), v.end(), cmp);
	long long ans = 0;
	for (int i = 0; i < tot; i++){
		ans += b[v[i]];
	}
	printf("%I64d\n", ans);
	return 0;
}