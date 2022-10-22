#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

// #define DEBUG

ll arr[520][520];
int pfx[520][520], pfy[520][520];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		ll ans = 0;
		for (int i = 1; i <= 2*n; i++){
			for (int j = 1; j <= 2*n; j++){
				cin >> arr[i][j];
				if (i <= n && j <= n){ ans += arr[i][j]; arr[i][j] = 0; }
				if (i > n && j > n){ ans += arr[i][j]; arr[i][j] = 0; }
			}
		}
		ll mn = min(arr[1][n+1], arr[1][2*n]);
		mn = min(mn, arr[n][n+1]);
		mn = min(mn, arr[n][2*n]);
		mn = min(mn, arr[n+1][1]);
		mn = min(mn, arr[n+1][n]);
		mn = min(mn, arr[2*n][1]);
		mn = min(mn, arr[2*n][n]);
		cout << ans + mn << endl;
	}
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}