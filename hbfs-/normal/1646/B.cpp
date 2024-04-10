#include <bits/stdc++.h>
#define N 1000500
using namespace std;
inline int rd() {int r;scanf("%d",&r);return r;}
int a[N], n;
int main() {
	int T = rd();
	while (T--) {
		n = rd();
		for (int i=1;i<=n;i++) a[i] = rd();
		sort(a+1, a+n+1);
		long long sum_red = 0, sum_blue = a[1];
		bool flag = false;
		for (int i=2;i<=n;i++) { // num of blue
			int cur_red = n-i+2;
			if (cur_red <= i) break;
			sum_red += a[cur_red];
			sum_blue += a[i];
			if (sum_red > sum_blue) flag = true;
		}
		puts(flag ? "YES" : "NO");
	}

	return 0;
}