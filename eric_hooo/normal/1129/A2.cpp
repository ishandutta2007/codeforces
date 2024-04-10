#include <bits/stdc++.h>
using namespace std;

vector <int> all[5010];
int mind[5010];
int n, m;

int dist(int a, int b){
	return b >= a ? b - a : b + n - a;
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		int a, b; scanf("%d%d", &a, &b);
		all[a].push_back(b);
	}
	for (int i = 1; i <= n; i++){
		mind[i] = 0x3f3f3f3f;
		for (int j = 0; j < all[i].size(); j++){
			int to = all[i][j];
			mind[i] = min(mind[i], dist(i, to));
		}
	}
	for (int i = 1; i <= n; i++){
		int ans = 0;
		for (int j = 1; j <= n; j++){
			if (all[j].size() == 0) continue;
			ans = max(ans, dist(i, j) + ((int)all[j].size() - 1) * n + mind[j]);
		}
		printf("%d ", ans);
	}
	printf("\n");
	return 0;
}