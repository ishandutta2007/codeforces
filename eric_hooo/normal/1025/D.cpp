#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b){
	return b == 0 ? a : GCD(b, a % b);
}

int f_l[710][710], f_r[710][710];
int vis[710][710];
int gcd[710][710];
int a[710];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			gcd[i][j] = GCD(a[i], a[j]) > 1;
		}
	}
	for (int len = 1; len <= n; len++){
		for (int l = 1; l <= n - len + 1; l++){
			int r = l + len - 1;
			if (l == r){
				f_l[l][r] = f_r[l][r] = 1;
				continue;
			}
			for (int i = l; i < r; i++){
				if (f_l[l][i] && f_r[i][r - 1] && gcd[r][i] && a[r] > a[i]){
					f_l[l][r] = 1;
					break;
				}
			}
			for (int i = l + 1; i <= r; i++){
				if (f_r[i][r] && f_l[l + 1][i] && gcd[l][i] && a[l] < a[i]){
					f_r[l][r] = 1;
					break;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		ans |= f_l[1][i] & f_r[i][n];
	}
	puts(ans ? "YES" : "NO");
	return 0;
}