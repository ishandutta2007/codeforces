#include <bits/stdc++.h>
#define ll long long
#define maxn 500005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int n, m;
int a[maxn];
int main() {
	int st = 1e8 + 9;
	int pls = 20000;
	cin >> n >> m;
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		if (cur + (i - 1) / 2 <= m) {
			cur += (i - 1) / 2;
			a[i] = i;
		}
		else {
			if (cur >= m) {
				a[i] = st;
				st += pls;
			}
			else {
				int nd = (m - cur);
				int bg = i - 1, ed = bg - 2 * nd + 1;
				a[i] = bg + ed;
				cur = m;
			}
		}
	}
	if (cur != m) cout << -1 << endl;
	else {
		for (int i = 1; i <= n; i++) cout << a[i] << ' ';
		cout << endl;
	}
	return 0;
}
/*
CHHOCH
*/