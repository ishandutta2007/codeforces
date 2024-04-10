#include <bits/stdc++.h>
using namespace std;

int a[200010], pos[200010];
int f[200010][20];
int n;

void get_f(){
	for (int i = 0; i < n; i++){
		f[i][0] = a[i];
	}
	for (int j = 1; j < 20; j++){
		for (int i = 0; i < n; i++){
			if (i + (1 << j) - 1 >= n) break;
			f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
		}
	}
}

int get_max(int l, int r){
	int k = log(r - l + 1) / log(2);
	return max(f[l][k], f[r - (1 << k) + 1][k]); 
}

int ans = 0;

void dfs(int l, int r){
	if (l >= r) return ;
	int mid = pos[get_max(l, r)];
	if (mid - l < r - mid){
		for (int i = l; i < mid; i++){
			if (pos[a[mid] - a[i]] > mid && pos[a[mid] - a[i]] <= r) ans++;
		}
	} else {
		for (int i = mid + 1; i <= r; i++){
			if (pos[a[mid] - a[i]] < mid && pos[a[mid] - a[i]] >= l) ans++;
		}
	}
	dfs(l, mid - 1), dfs(mid + 1, r);
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	get_f();
	dfs(0, n - 1);
	printf("%d\n", ans);
	return 0;
}