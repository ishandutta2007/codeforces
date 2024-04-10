#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

#define int ll

 main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		ll k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
 	
 		if (k > 5) {
 			if (k % 2 == 1) k = 5; else k = 6;
 		}

 		while (k--) {
 			int ma = *max_element(all(a));
 			for (int& x : a) x = ma - x;
 		}

 		for (int x : a) cout << x << ' ';
 			cout << "\n";

	}

}