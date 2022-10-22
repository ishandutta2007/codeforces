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
typedef pair<ll, pl2> pl3;

ll arr[100020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; ll m; cin >> n >> m;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		sort(arr+1, arr+n+1, [](ll a, ll b){ return a > b; });
		ll sum = 0;
		for (int i = 1; i <= n; i++){ sum += arr[i]; }
		sum -= arr[n]; sum += arr[1];
		sum += n;
		cout << (sum <= m ? "Yes" : "No") << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}