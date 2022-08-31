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
int p[maxn], b[maxn], n; 
int fl[maxn];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	int c = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]), c^=b[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (fl[i]) continue;
		ans++; 
		int pl = i;
		while (1) {
			fl[pl] = 1, pl = p[pl];
			if (pl == i) break;
		}
	}
	if (ans == 1) ans--;
	if (!c) ans++;
	cout << ans << endl;
	return 0;
}