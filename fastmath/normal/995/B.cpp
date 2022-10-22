#include <bits/stdc++.h>
     
using namespace std;

const int MAXN = 207;

int a[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);

	int n;
	cin >> n;
	for (int i = 0; i < 2 * n; ++i) cin >> a[i];

	int ans = 0;
    for (int i = 0; i < n; ++i) {
     	int x = a[2 * i];
     	int p = -1;

     	for (int j = 2 * i + 1; j < 2 * n; ++j) {
     	 	if (a[j] == x) {
				p = j;
				break;
     	 	}
     	}

     	while (a[p - 1] != a[p]) {
     	 	++ans;
     	 	swap(a[p], a[p - 1]);
     	 	--p;
     	}
    }

    cout << ans << '\n';
    return 0;
}