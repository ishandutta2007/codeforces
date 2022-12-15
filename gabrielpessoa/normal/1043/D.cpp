#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 1e5+5;

int a[12][ms];
int start[12][ms];
int pos[12];
vector<int> ans;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	if(m == 1) {
		cout << (1ll * n * (n+1))/2 << '\n';
		return 0;
	}
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
			start[i][a[i][j]] = j;
		}
	}
	ll ans = 0;
	for(int j = 0; j < n; ) {
		int jInicial = j;
		ll sz = 0;
		int val = a[0][j];
		for(int k = 1; k < m; k++) {
			pos[k] = start[k][val];
		}
		bool valid = true;
		while(valid) {
			for(int k = 1; k < m; k++) {
				if(pos[k] < n && a[k][pos[k]] == a[0][j]) {
					pos[k]++;
				} else {
					valid = false;
				}
			}
			if(valid) {
				j++;
				sz++;
			}
		}
		ans += (sz * (sz + 1)) /2;
	}
	cout << ans << endl;
}