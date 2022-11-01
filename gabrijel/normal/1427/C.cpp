#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int maxn = 501;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int r, n;
	cin >> r >> n;
	int t, x, y;
	vector <pair <pair <int, int>, pair <int, int> > > svi;
	svi.push_back(make_pair(make_pair(0, 0), make_pair(0, 0)));
	REP(i, n) {
		cin >> t >> x >> y;
		x--; y--;
		svi.push_back(make_pair(make_pair(t, -1), make_pair(x, y)));
	}
	int rj = 0;
	for(int i = 1; i < n + 1; i++) {
		int poc = max(i - 4 * r - 10, 0);
		for(int j = poc; j < i; j++) {
			if(abs(svi[i].second.second - svi[j].second.second) + abs(svi[i].second.first - svi[j].second.first) <= svi[i].first.first - svi[j].first.first) {
				if(svi[j].first.second != -1) svi[i].first.second = max(svi[i].first.second, svi[j].first.second + 1);
			}
		}
		rj = max(rj, svi[i].first.second);
	}
	cout << rj << "\n";
	return 0;
}