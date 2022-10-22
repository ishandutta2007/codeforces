#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int arr[200020];
ll dp[200020];

void Main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> arr[i];
		}
		dp[n] = arr[n];
		ll ans = dp[n];
		for (int i = n-1; i >= 1; i--){
			if (i+arr[i] > n){
				dp[i] = arr[i];
			}
			else{
				dp[i] = dp[ i+arr[i] ] + arr[i];
			}
			ans = max(ans, dp[i]);
		}
		cout << ans << endl;
		memset(dp, 0, sizeof(dp));
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}