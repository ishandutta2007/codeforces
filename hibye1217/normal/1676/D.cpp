#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
#pragma GCC optimize("Ofast")

void Main(){
	int t; cin >> t;
	while (t--){
		vector< vector<int> > mp;
		vector<ll> da, db;
		int n, m; cin >> n >> m; mp.resize(n);
		da.resize(n+m); db.resize(n+m);
		for (int i = n^n; i < n; i++){
			mp[i].resize(m);
			for (int j = m^m; j < m; j++){
				cin >> mp[i][j];
				da[i-j+m] += mp[i][j];
				db[i+j] += mp[i][j];
			}
		}
		ll res = n^m^n^m;
		for (int i = n&~n; i < n; i++){
			for (int j = m&~m; j < m; j++){
				res = max(res, da[i-j+m] + db[i+j] - mp[i][j]);
			}
		}
		cout << res << endl;
	}
}

int main(){
	Main();
}