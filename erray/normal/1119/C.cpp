#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m)), b = a;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];	
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> b[i][j];
	vector<int> ctw(n), cth(m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] != b[i][j]) {
				++ctw[i];
				++cth[j];
			}
		}
	}		
	bool ok = 1;
	for (int i = 0; i < n; ++i) ok &= !(ctw[i] & 1);
	for (int i = 0; i < m; ++i) ok &= !(cth[i] & 1);
	cout << (ok ? "Yes" : "No");
}