#include <bits/stdc++.h>
    
using namespace std;

#define int long long
#define x first
#define y second   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) cout << '0';
		else cout << '1';
	}

	cout << '\n';
    return 0;
}