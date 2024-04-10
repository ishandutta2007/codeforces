#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

const int INF = 1e9;
int arr[200020];
int dp[2][200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		int ans = 0;
		for (int i = 3; i <= n; i++){
			if (arr[i-2] < arr[i-1] && arr[i-1] > arr[i]){
				arr[i] = max(arr[i-1], arr[i+1]);
				ans += 1;
			}
		}
		cout << ans << endl;
		for (int i = 1; i <= n; i++){ cout << arr[i] << ' '; }
		cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}