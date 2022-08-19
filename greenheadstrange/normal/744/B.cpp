#include <bits/stdc++.h>
#define ll long long
#define maxn 400005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int dp[maxn];
int t[maxn];
int ans[maxn];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) ans[i] = 1e9 + 7;
	for (int i = 0; i < 10; i++) {
		for (int tp = 0; tp < 2; tp++) {
			vi cur;
			for (int j = 1; j <= n; j++) 
				if (((j >> i) & 1) == tp) cur.pb(j);
			if (!cur.size()) continue;
			cout << cur.size() << endl;
			for (auto v : cur) cout << v << ' ';
			cout << endl;
			fflush(stdout);
			for (int j = 1; j <= n; j++) {
				int res;
				scanf("%d", &res);
				if (((j >> i) & 1) == tp) continue;
				ans[j] = min(ans[j], res);
			}
		}
	}
	cout << -1 << endl;
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	cout << endl;
	fflush(stdout);
 	return 0;
}