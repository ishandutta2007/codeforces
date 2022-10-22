#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;

const int INF = 0x3f3f3f3f;

int a[110][110];
vector <pair <int, int> > res;

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	int pd = 0;
	if (n > m){
		swap(n, m), pd = 1;
		int b[110][110];
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				b[i][j] = a[j][i];
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				a[i][j] = b[i][j];
			}
		}
	}
	for (int i = 1; i <= n; i++){
		int minj = INF;
		for (int j = 1; j <= m; j++){
			minj = min(minj, a[i][j]);
		}
		if (minj == 0) continue;
		for (int j = 0; j < minj; j++){
			res.push_back(mp(i, 0));
		}
		for (int j = 1; j <= m; j++){
			a[i][j] -= minj;
		}
	}
	for (int i = 1; i <= m; i++){
		int minj = INF;
		for (int j = 1; j <= n; j++){
			minj = min(minj, a[j][i]);
		}
		if (minj == 0) continue;
		for (int j = 0; j < minj; j++){
			res.push_back(mp(i, 1));
		}
		for (int j = 1; j <= n; j++){
			a[j][i] -= minj;
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (a[i][j] != 0){
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++){
		if (res[i].se == pd) printf("row ");
		else printf("col ");
		printf("%d\n", res[i].fi);
	}
	return 0;
}