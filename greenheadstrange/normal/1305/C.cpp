#include <bits/stdc++.h>
#define ll long long
#define maxn 200005
#define db double
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int fl[maxn];
int x[maxn];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
		fl[x[i] % m]++;
	}
	for (int i = 0; i < m; i++)
		if (fl[i] >= 2) {
			printf("0\n");
			return 0;
		}
	ll ans = 1;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			ans = ans * (abs(x[i] - x[j])) % m;
	cout << ans << endl;
	return 0;
}
/*
1 1 0
1 1000000000
1 1000000000
*/