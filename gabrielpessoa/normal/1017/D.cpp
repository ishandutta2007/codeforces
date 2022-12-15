#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int ms = (1<<12) + 1;

int qnt[ms];
int ans[ms][105];
int w[15];
int trueW[ms];
int n, m, q;

int value(string &s) {
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '1') ans += (1 << i);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> q;
	for(int i = 0; i < n; i++) {
		cin >> w[i];
	}
	for(int i = 0; i <(1 << n); i++) {
		for(int j = 0; j < 12; j++) {
			if(!(i & (1 << j))) {
				trueW[i] += w[j];
			}
		}
	}
	string s;
	while(m--) {
		cin >> s;
		qnt[value(s)]++;
	}
	for(int i = 0; i < (1 << n); i++) {
		for(int j = 0; j < (1 << n); j++) {
			int wei = trueW[(i ^ j)];
			if(wei <= 100) {
				ans[i][wei] += qnt[j];
			}
		}
		for(int j = 1; j <= 100; j++) {
			ans[i][j] += ans[i][j-1];
		}
	}
	while(q--) {
		int k;
		string t;
		cin >> t >> k;
		cout << ans[value(t)][k] << '\n';
	}
	return 0;
}