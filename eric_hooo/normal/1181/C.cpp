#include <bits/stdc++.h>
using namespace std;

char a[1010][1010];
int nxt[1010][1010];
int f[1010][10];

int get_minj(int l, int r){
	int k = log(r - l + 1) / log(2);
	return min(f[l][k], f[r - (1 << k) + 1][k]);
}

int main(){
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++){
		scanf("%s", a[i]);
		for (int j = m - 1; j >= 0; j--){
			if (a[i][j] == a[i][j + 1]) nxt[i][j] = nxt[i][j + 1] + 1;
			else nxt[i][j] = 1;
		}
	}
	long long ans = 0;
	for (int j = 0; j < m; j++){
		int now = 0;
		vector <int> v;
		for (int i = 0; i < n; i++){
			if (i == now){
				while (a[now][j] == a[i][j]) now++;
				v.push_back(now);
			}
		}
		for (int i = 0; i < n; i++){
			f[i][0] = nxt[i][j];
		}
		for (int j = 1; j < 10; j++){
			for (int i = 0; i < n; i++){
				if (i + (1 << j) - 1 >= n) continue;
				f[i][j] = min(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
			}
		}
		now = 0;
		for (int i = 0; i < n; i++){
			while (a[now][j] == a[i][j]) now++;
			int x = now, y = x + now - i, z = y + now - i;
			if (x >= n || y >= n) continue;
			if (a[x][j] == a[y][j]) continue;
			if (upper_bound(v.begin(), v.end(), x) != upper_bound(v.begin(), v.end(), y - 1)) continue;
			if (upper_bound(v.begin(), v.end(), y) != upper_bound(v.begin(), v.end(), z - 1)) continue;
			ans += get_minj(i, z - 1);
		}
	}
	printf("%I64d\n", ans);
	return 0;
}