#include <bits/stdc++.h>
using namespace std;

int a[1010][1010];
int n, m;
int TOT1, TOT2;
int sum1[1010][1010];
int sum2[1010][1010];

long long get_cnt(int x){
	if (x == 0) return 0;
	if (x == 1) return 1;
	long long now = 1;
	while (now < x) now *= 2;
	now /= 2;
	return x - now - get_cnt(x - now) + (now == 1 ? 1 : now / 2);
}

long long get_ans(int x, int y){
	int nx = x / n, ny = y / m;
//	cout << "nx & ny:" << nx << " " << ny << endl;
	long long cnt1 = get_cnt(nx), cnt2 = get_cnt(ny);
//	cout << "cnt1 & cnt2:" << cnt1 << " " << cnt2 << endl;
	long long ans = (cnt1 * cnt2 + (nx - cnt1) * (ny - cnt2)) * TOT1 + ((nx - cnt1) * cnt2 + cnt1 * (ny - cnt2)) * TOT2;
//	cout << "  ans:" << (cnt1 * cnt2 + (nx - cnt1) * (ny - cnt2)) << endl;
	int pd1 = get_cnt(nx + 1) - get_cnt(nx), pd2 = get_cnt(ny + 1) - get_cnt(ny);
	ans += pd1 ? sum1[x % n][m] * cnt2 + sum2[x % n][m] * (ny - cnt2) : sum1[x % n][m] * (ny - cnt2) + sum2[x % n][m] * cnt2;
	ans += pd2 ? sum1[n][y % m] * cnt1 + sum2[n][y % m] * (nx - cnt1) : sum1[n][y % m] * (nx - cnt1) + sum2[n][y % m] * cnt1;
	ans += !((!pd1) ^ (!pd2)) ? sum1[x % n][y % m] : sum2[x % n][y % m];
	return ans;
}

long long get_ans(int x1, int x2, int y1, int y2){
	return get_ans(x2, y2) - get_ans(x1 - 1, y2) - get_ans(x2, y1 - 1) + get_ans(x1 - 1, y1 - 1);
}

int main(){
	int q; scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++){
		char s[1010]; scanf("%s", s + 1);
		for (int j = 1; j <= m; j++){
			a[i][j] = s[j] - '0';
			sum1[i][j] = sum1[i - 1][j] + sum1[i][j - 1] - sum1[i - 1][j - 1] + a[i][j];
			sum2[i][j] = sum2[i - 1][j] + sum2[i][j - 1] - sum2[i - 1][j - 1] + (a[i][j] ^ 1);
		}
	}
	TOT1 = sum1[n][m], TOT2 = sum2[n][m];
//	cout << "get_ans:" << get_ans(4, 4) << endl;
	while (q--){
		int x1, x2, y1, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%I64d\n", get_ans(x1, x2, y1, y2));
	}
	return 0;
}