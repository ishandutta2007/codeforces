#include <bits/stdc++.h>
#define ll long long
#define maxn 4005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int n, m, k;
int a[maxn];
int b[maxn];
int d[maxn];
bool check(int num) {
	k = min(k, m - 1);
	d[0] = 0;
	for (int i = 1; i <= n; i++) {
		d[i] = 0;
		if (a[i] >= num) b[i] = 1;
		else b[i] = 0;
	}
	int nm = n - m;
	for (int i = 1; i <= n; i++)
		if (i + nm <= n && b[i] == 0 && b[i + nm] == 0) {
			int ls = i, rs = n - (i + nm) + 1;
			rs = k - rs;
			rs = max(rs, -1);
	//		cout << "???" << rs << endl;
			if (ls > rs)
				d[rs + 1]++, d[ls]--;
		}
	for (int i = 0; i <= k; i++) {
		if (i) d[i] += d[i - 1];
		if (d[i] <= 0) return 1;
	}	
//	cout << "!!!" << num << endl;
	return 0;
}
int u[maxn];
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), u[i] = a[i];
		sort(u + 1, u + n + 1);
		int l = 1, r = n;
	//	check(8);
	//	while (1);
		while (l < r) {
			int mid = (l + r) >> 1;
			if (check(u[mid + 1])) l = mid + 1;
			else r = mid;
		}
		cout << u[l] << endl;
	}
	return 0;
}