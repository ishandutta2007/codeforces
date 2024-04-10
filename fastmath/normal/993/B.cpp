#include <bits/stdc++.h>
   
using namespace std; 
 
const int MAXN = 15;

pair <int, int> a[MAXN], b[MAXN];
bool ch[MAXN][MAXN];

int check(pair <int, int> a, pair <int, int> b) {
 	if (a.first == b.first && a.second != b.second) return a.first;
 	if (a.second == b.second && a.first != b.first) return a.second;
 	if (a.first == b.second && a.second != b.first) return a.first;
 	if (a.second == b.first && a.first != b.second) return a.second;
 	return 0;
}

int cnt[10];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
	 	cin >> a[i].first >> a[i].second;
	}

	for (int i = 0; i < m; ++i) {
	 	cin >> b[i].first >> b[i].second;
	}
	
	for (int i = 0; i < n; ++i) {
	 	for (int j = 0; j < m; ++j) {
	 	    ch[i][j] = check(a[i], b[j]);
	 	    ++cnt[check(a[i], b[j])];
	 	}
	}
	
	int c = 0;
	for (int i = 0; i < n; ++i) {
	 	for (int j = 0; j < m; ++j) {
			c += ch[i][j];
		}
	}
	
	for (int i = 1; i <= 9; ++i) {
		if (cnt[i] == c) {
		 	cout << i << '\n';
		 	return 0;
		}
	}

	for (int i = 0; i < n; ++i) {
		set <int> ms;
		for (int j = 0; j < m; ++j) {
			if (check(a[i], b[j])) ms.insert(check(a[i], b[j]));
		}
		if (1 < ms.size()) {
		 	cout << "-1\n";
		 	return 0;
		}
	}

	for (int j = 0; j < m; ++j) {
	    set <int> ms;
	 	for (int i = 0; i < n; ++i) {
	 		if (check(a[i], b[j])) ms.insert(check(a[i], b[j]));
	 	}
	 	if (1 < ms.size()) {
	 	    cout << "-1\n";
	 	    return 0;
	 	}	
	}

	cout << "0\n";
    return 0;
}