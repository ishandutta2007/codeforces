#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int n, q;
int a[2][maxn];
int ans = 0;
int cal(int t) {
	int res = 0;
	if (a[0][t] && a[1][t + 1]) res++;
	if (a[1][t] && a[0][t + 1]) res++;
	if (a[0][t] && a[1][t]) res++;
	return res;
}
int main() {
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		int r, c;
		scanf("%d%d", &r, &c);
		ans -= cal(c), ans -= cal(c - 1);
		a[r - 1][c] ^= 1;
		ans += cal(c), ans += cal(c - 1);
		if (ans) {
			printf("No\n");
		}
		else printf("Yes\n");
	}
	return 0;
}