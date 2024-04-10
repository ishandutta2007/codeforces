#include <bits/stdc++.h>
using namespace std;

const int MAX = 550;
int mod;

inline int add(int a, int b) {
	return a+b >= mod ? a+b-mod : a+b;
}

int f[MAX][MAX];
int a[MAX];

int main(){
	int n, m, b;
	scanf("%d %d %d %d", &n, &m, &b, &mod);
	for (int i = 0; i < n; i++){
		scanf("%d", a+i);
	}
	f[0][0] = 1 % mod;
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= m; j++){
			for (int k = 0; k <= b; k++){
				if (k + a[i] <= b && j < m) f[j+1][k+a[i]] = add(f[j+1][k+a[i]], f[j][k]);
			}
		}
	}
	int ans = 0;
	for (int k = 0; k <= b; k++) ans = add(ans, f[m][k]);
	printf("%d\n", ans);
	return 0;
}