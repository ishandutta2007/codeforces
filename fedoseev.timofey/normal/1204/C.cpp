#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int Inf = 1e9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <vector <int>> d(n, vector <int> (n, Inf));
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		char c;
    		cin >> c;
    		if (c == '1') d[i][j] = 1;
    	}
    }
    for (int i = 0; i < n; ++i) d[i][i] = 0;
    for (int k = 0; k < n; ++k) {
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < n; ++j) {
    			d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    		}
    	}
    }
    int m;
    cin >> m;
    vector <int> p(m);
    for (int i = 0; i < m; ++i) cin >> p[i], --p[i];
    vector <int> np;
	np.push_back(p[0]);
	for (int i = 1; i + 1 < m; ++i) {
		if (d[np.back()][p[i]] + d[p[i]][p[i + 1]] > d[np.back()][p[i + 1]]) np.push_back(p[i]);
	}
	np.push_back(p[m - 1]);
	cout << np.size() << '\n';
	for (int x : np) cout << x + 1 << ' ';
}