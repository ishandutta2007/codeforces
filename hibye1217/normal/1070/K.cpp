#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

ll arr[100020], prf[100020];
ll ans[100020];

void Main(){
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++){ cin >> arr[i]; }
	for (int i = 1; i <= n; i++){ prf[i] = prf[i-1] + arr[i]; }
	ll sum = prf[n]; if (sum % k != 0){ cout << "No"; return; }
	ll tar = sum / k; int mul = 1;
	for (int i = 1; i <= n; i++){
		//cout << "P " << prf[i] << ' ' << tar*mul << endl;
		if (prf[i] == tar*mul){ ans[mul] = i; mul += 1; }
		else if (prf[i] > tar*mul){ cout << "No"; return; }
	}
	cout << "Yes" << endl;
	for (int i = 1; i <= k; i++){ cout << ans[i]-ans[i-1] << ' '; }
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