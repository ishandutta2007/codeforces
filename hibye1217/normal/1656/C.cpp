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

ll arr[100020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		sort(arr+1, arr+n+1);
		bool one = (arr[n]==1), dif = 0;
		for (int i = 1; i < n; i++){
			if (arr[i] == 1){ one = 1; }
			if (arr[i+1] - arr[i] == 1){ dif = 1; }
		}
		if (one && dif){ cout << "NO"; } else{ cout << "YES"; }
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