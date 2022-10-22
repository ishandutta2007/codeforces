#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define DEBUG
//#define USE_MAGIC_IO

#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define ldouble long double
#define nl '\n'
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>> pts;
int getgood(int a, int b, int c) {
	int angle = 0;
	for (int i = 0; i < 5; i++) {
		angle += (pts[b][i] - pts[a][i])*(pts[c][i] - pts[a][i]);
	}
	if (angle <= 0) return a;
	angle = 0;
	for (int i = 0; i < 5; i++) {
		angle += (pts[a][i] - pts[b][i])*(pts[c][i] - pts[b][i]);
	}
	if (angle <= 0) return b;
	angle = 0;
	for (int i = 0; i < 5; i++) {
		angle += (pts[a][i] - pts[c][i])*(pts[b][i] - pts[c][i]);
	}
	if (angle <= 0) return c;
	else return -1;
}

bool check(int a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (i == j || i == a || j == a) continue;
			if (a != getgood(i, j, a))
				return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	pts.resize(n);
	for (int i = 0; i < n; i++) {
		pts[i].resize(5);
		cin >> pts[i][0] >> pts[i][1] >> pts[i][2] >> pts[i][3] >> pts[i][4];
	}
	int curr = 0;
	vector<int> active[2];
	for (int i = 0; i < n; i++) {
		active[curr%2].push_back(i);
	}
	int prev = INF;
	while (active[curr%2].size() != prev) {
		prev = active[curr%2].size();
		active[(curr+1)%2].clear();
		int i;
		for (i = 2; i < prev; i += 3) {
			int good = getgood(active[curr%2][i-2], active[curr%2][i-1], active[curr%2][i]);
			if (good != -1) active[(curr+1)%2].push_back(good);
		} i -= 2;
		while (i < prev) {
			active[(curr+1)%2].push_back(active[curr%2][i++]);
		}
		curr++;
	}
	// check points left
	vector<int> ans;
	for (int i = 0; i < active[curr%2].size(); i++) {
		if (check(active[curr%2][i], n))
			ans.push_back(active[curr%2][i]+1);
	}
	cout << ans.size() << nl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << nl;

	return 0;
}