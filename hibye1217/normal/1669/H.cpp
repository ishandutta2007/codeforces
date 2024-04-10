#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;

int arr[200020];
int cnt[40];

void Main(){
	int t; cin >> t;
	while (t--){
		int n, q; cin >> n >> q;
		for (int i = 1; i <= n; i++){
			cin >> arr[i];
			for (int j = 30; j >= 0; j--){ if (arr[i] & (1<<j)){ cnt[j] += 1; } }
		}
		int ans = 0;
		for (int j = 30; j >= 0; j--){
			if (q >= n-cnt[j]){ q -= n-cnt[j]; ans |= (1<<j); }
		}
		cout << ans << endl;
		for (int j = 30; j >= 0; j--){ cnt[j] = 0; }
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}