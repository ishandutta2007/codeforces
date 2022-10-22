#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() )

// #define DEBUG

ll N = 1e9;
vector<ll> res;

void Main(){
	for (ll i = 1; i*i <= N; i++){ res.push_back(i*i); }
	for (ll i = 1; i*i*i <= N; i++){ res.push_back(i*i*i); }
	unq(res);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		auto it = upper_bound( all(res), n ) - res.begin();
		cout << it << endl;
	}
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