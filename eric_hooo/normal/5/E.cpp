#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int f_r[2000010], f_l[2000010], all[2000010];
int a[2000010];

int main(){
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
	int n, maxj = 0, pos = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		a[i + n] = a[i];
		if (a[i] > maxj) pos = i;
		maxj = max(maxj, a[i]);
	}
	a[0] = a[2 * n + 1] = INF;
	for (int i = 2 * n; i >= 1; i--){
		f_r[i] = i + 1;
		while (a[f_r[i]] <= a[i]) f_r[i] = f_r[f_r[i]];
	}
	for (int i = 1; i <= 2 * n; i++){
		f_l[i] = i - 1;
		while (a[f_l[i]] <= a[i]) f_l[i] = f_l[f_l[i]];
	}
	for (int i = 1; i <= 2 * n; i++){
		int t = i - 1;
		while (a[t] < a[i]) t = f_l[t];
		all[i] = a[t] != a[i] ? 0 : all[t] + 1;
	}
	long long res = 0;
	for (int i = 1; i <= n; i++){
		int tmp = (i >= pos ? all[i] : all[i + n]);
		res += (i >= pos ? all[i] : all[i + n]) + 2;
//		cout << i << " " << f_r[i] << " " << f_l[i + n] << " " << tmp << endl;
		if (a[i] == maxj) res -= 2;
		else if ((f_r[i] - 1) % n + 1 == (f_l[i + n] - 1) % n + 1) res--;
	}
	printf("%I64d\n", res);
	return 0;
}