#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 100000 + 1;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(20);
	int T;
	for(cin >> T; T; T -= 1){
		int n, q;
		cin >> n >> q;
		for(int i = 1; i <= n; i += 1) cin >> a[i];
		int m = n;
		while(a[m] == m and m) m -= 1;
		double ans = 1, p;
		for(int i = 1, r; i <= q; i += 1){
			cin >> r >> p;
			if(r >= m) ans *= 1 - p;
		}
		if(m == 0) cout << "1\n";
		else cout << 1 - ans << "\n";
	}
	return 0;
}