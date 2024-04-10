#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
#define fr first
#define sc second
using pi2 = pair<int, int>;

pi2 arr[1020];

void Main(){
	int n; cin >> n;
	for (int i = 1; i <= n; i++){ cin >> arr[i].fr >> arr[i].sc; }
	int ans = 0, res = 0;
	for (int i = 1; i <= n; i++){
		res -= arr[i].fr; ans = max(ans, res);
		res += arr[i].sc; ans = max(ans, res);
	}
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}