#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<vector<int> > a(n + 1, vector<int>(n));
	for(int i = 0; i < n; i++){
		cin >> a[0][i];
	}
	for(int i = 1; i <= n; i++){
		vector<int> f(n + 1);
		for(int j = 0; j < n; j++){
			f[a[i - 1][j]]++;
		}
		for(int j = 0; j < n; j++){
			a[i][j] = f[a[i - 1][j]];
		}
	}
	int q;
	cin >> q;
	while(q--){
		int x, k;
		cin >> x >> k;
		k = min(k, n);
		cout << a[k][x - 1] << '\n';
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}