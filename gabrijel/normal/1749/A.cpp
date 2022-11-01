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
		int n, m;
		cin >> n >> m;
		vector <pair <int, int> > svi(m);
		REP(i, m) {
			cin >> svi[i].first >> svi[i].second;
		}
		if(m < n) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}