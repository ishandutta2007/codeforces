#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;

ll arr[200020], prf[200020], suf[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		prf[0] = 0; for (int i = 1; i <= n; i++){ prf[i] = prf[i-1] + arr[i]; }
		suf[n+1] = 0; for (int i = n; i >= 1; i--){ suf[i] = suf[i+1] + arr[i]; }
		int p1 = 1, p2 = n;
		int ans = 0;
		while (p1 < p2){
			if (prf[p1] == suf[p2]){ ans = max(ans, p1 + n-p2+1); }
			if (prf[p1] <= suf[p2]){ p1 += 1; } else{ p2 -= 1; }
		}
		cout << ans << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}