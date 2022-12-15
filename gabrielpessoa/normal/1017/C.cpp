#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int ms = 1e5+5;

int ans[ms];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int best = n + 1, bestNum = 1;
	for(int i = 2; i <= n; i++) {
		int val = (n-1)/i + 1 + i;
		if(val < best) {
			best = val;
			bestNum = i;
		}
	}
	int maior = 0;
	for(int i = 1; i <= (n-1)/bestNum + 1; i++) {
		for(int j = 0; j < bestNum; j++) {
			if(i*bestNum - j <= n) cout << i*bestNum - j << ' ';
		}
	}
	cout << '\n';
	return 0;
}