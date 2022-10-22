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

// #define DEBUG

set<int> val;
vector<int> v[150020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){
			int x; cin >> x;
			val.insert(x); v[x].push_back(i);
		}
		int ans = -1;
		for (int x : val){
			int vl = v[x].size();
			for (int i = 1; i < vl; i++){
				int v1 = v[x][i-1], v2 = v[x][i];
				int res = n - (v2-v1);
				ans = max(ans, res);
			}
		}
		cout << ans << endl;
		for (int x : val){ v[x].clear(); } val.clear();
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