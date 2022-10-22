#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

pi2 arr[1020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++){ cin >> arr[i].fr; }
		for (int i = 1; i <= n; i++){ cin >> arr[i].sc; }
		sort(arr+1, arr+n+1);
		for (int i = 1; i <= n; i++){
			if (m < arr[i].fr){ break; }
			m += arr[i].sc;
		}
		cout << m << endl;
	}
}

//#define DEBUG
int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}