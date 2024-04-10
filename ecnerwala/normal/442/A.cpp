#include<bits/stdc++.h>

using namespace std;

const char colors[] = "RGBYW";

bool has[5][5];

int dsum(int i) {
	return i ? i % 2 + dsum(i / 2) : 0;
}

bool isGood(int i, int j) {
	for(int a = 0; a < 5; a++) {
		int cnt = 0;
		for(int b = 0; b < 5; b++) {
			if(has[a][b]) {
				if(j & (1 << b)) continue;
				cnt++;
			}
		}
		if(cnt > 1) return false;
	}

	for(int b = 0; b < 5; b++) {
		int cnt = 0;
		for(int a = 0; a < 5; a++) {
			if(has[a][b]) {
				if(i & (1 << a)) continue;
				cnt++;
			}
		}
		if(cnt > 1) return false;
	}
	int cnt = 0;
	for(int a = 0; a < 5; a++) {
		if(i & (1 << a)) continue;
		for(int b = 0; b < 5; b++) {
			if(j & (1 << b)) continue;
			if(has[a][b]) cnt++;
		}
	}
	if(cnt > 1) return false;
	return true;
}

int main() {
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		int a = 0;
		while(colors[a] != s[0]) a++;
		int b = s[1] - '1';
		has[a][b] = true;
	}
	int res = 10;
	for(int i = 0; i < (1 << 5); i++) {
		for(int j = 0; j < (1 << 5); j++) {
			if(isGood(i, j)) {
				int v = dsum(i) + dsum(j);
				if(v < res) res = v;
			}
		}
	}
	cout << res << '\n';
	return 0;
}