#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 9
using namespace std;
#define all(v) v.begin(),v.end()
using ll = long long;
#define fr first
#define sc second
using pi2 = pair<int, int>;

int arr[120];

void Main(){
	int n; cin >> n;
	for (int i = 1; i <= n; i++){ cin >> arr[i]; }
	int ans = 0;
	for (int st = 1; st <= n; st++){
		for (int ed = st; ed <= n; ed++){
			int res = 0;
			for (int i = st; i <= ed; i++){ arr[i] = 1 - arr[i]; }
			for (int i = 1; i <= n; i++){ res += arr[i]; }
			ans = max(ans, res);
			for (int i = st; i <= ed; i++){ arr[i] = 1 - arr[i]; }
		}
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