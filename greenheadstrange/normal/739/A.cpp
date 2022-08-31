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
int fa[maxn], sz[maxn];
int gfa(int a) {
	if (fa[a] == a) return a;
	return fa[a] = gfa(fa[a]);
}
int c[maxn];
int cc(int a) {
	return a * (a - 1) / 2;
}
int main() {
	int n, m;
	cin >> n >> m;
	int ans = 1e9;
	for (int i = 1; i <= m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		ans = min(ans, r - l + 1);
	} 
	cout << ans << endl;
	for (int i = 0; i < n; i++)
		printf("%d ", i % ans);
	return 0;
}