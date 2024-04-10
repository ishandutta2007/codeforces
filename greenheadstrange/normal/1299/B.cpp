#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
using namespace std;
int n;
int x[maxn], y[maxn];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d%d", &x[i], &y[i]);
	if (n % 2) {
		printf("NO\n");
		return 0;
	}
	int cx = x[0] + x[n / 2], cy = y[0] + y[n / 2]; 
	for (int i = 1; i < n / 2; i++) {
		if (x[i] + x[i + n / 2] != cx) {
				printf("NO\n");
			return 0;
		}
		if (y[i] + y[i + n / 2] != cy) {
			printf("NO\n");
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}