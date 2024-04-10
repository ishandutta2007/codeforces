#include <bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;
int n;
int x[maxn], y[maxn];
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, x;
		cin >> n >> x;
		int mx = 0;
		for (int i = 1; i <= n; i++) 
			scanf("%d", &y[i]), 
			mx = max(mx, y[i]);
		int dv = x / mx;
		if (x % mx) dv++;
		if (dv == 1) {
			dv++;
			for (int j = 1; j <= n; j++)
				if (y[j] == x) {
					dv = 1;
				}
		}
		printf("%d\n", dv);
	} 
	return 0;
}