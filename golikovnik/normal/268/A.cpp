#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		a[i] = mp(x, y);
	}       
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j == i) continue;
			if (a[i].first == a[j].second) ++cnt;
		}
	}
	cout << cnt << endl;
	return 0;
}