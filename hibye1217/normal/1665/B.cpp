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

int arr[100020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		sort(arr+1, arr+n+1);
		int cnt = 1, mx = 1;
		for (int i = 2; i <= n; i++){
			if (arr[i-1] == arr[i]){ cnt += 1; }
			else{ cnt = 1; }
			mx = max(mx, cnt);
		}
		int ans = n-mx;
		int num = mx;
		while (num < n){ num *= 2; ans += 1; }
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