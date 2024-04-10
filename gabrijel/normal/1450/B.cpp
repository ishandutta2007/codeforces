#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		int n, k;
		cin >> n >> k;
		vector <pair <int, int> > svi;
		int a, b;
		REP(i, n) {
			cin >> a >> b;
			svi.push_back(make_pair(a, b));
		}
		bool nasao = 0;
		REP(i, n) {
			int x = svi[i].first, y = svi[i].second;
			bool da = 1;
			REP(j, n) {
				if(abs(svi[j].first - x) + abs(svi[j].second - y) > k) {
					da = 0;
					break;
				}
			}
			if(da) {
				cout << 1 << endl;
				nasao = 1;
				break;
			}
		}
		if(!nasao) cout << -1 << endl;
	}
	return 0;
}