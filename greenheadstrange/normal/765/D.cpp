#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int f[maxn];
int id[maxn], cnt = 0;
int h[maxn], g[maxn];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &f[i]);
	for (int i = 1; i <= n; i++) {
		if (f[f[i]] != f[i]) {
			printf("-1\n");
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (f[i] == i) {
			cnt++;
			h[cnt] = i;
			id[i] = cnt;
		}
	}
	cout << cnt << endl;
	for (int i = 1; i <= n; i++)
		printf("%d ", id[f[i]]);
	cout << endl;
	for (int i = 1; i <= cnt; i++)
		printf("%d ", h[i]);
	cout << endl;
	return 0;
}