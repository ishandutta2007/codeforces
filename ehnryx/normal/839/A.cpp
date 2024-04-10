#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define End return 0; }
#define lame cin.tie(0);LAME
#define of ios::sync_with_stdio(0);
#define story int main() {
#define The

The story of lAme:

int n, k, a, res;
res = 0;
cin >> n >> k;
for (int i = 1; i <= n; i++) {
	cin >> a;
	res += a;
	k -= min(8, res);
	res -= min(8, res);
	if (k <= 0) {
		cout << i << endl;
		return 0;
	}
}
cout << -1 << endl;

The End