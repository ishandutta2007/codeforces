#include <bits/stdc++.h>

using namespace std;
template<class T1, class T2> inline void chkmin(T1 &x, T2 const &y) {if (x > y) x = y;}
template<class T1, class T2> inline void chkmax(T1 &x, T2 const &y) {if (x < y) x = y;}
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define mp make_pair
#define left left228
#define right right228



int n, m, k;
bool good[200];
vector<pair<int, int> > who[202];
int p[200];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (int i = 0; i  < n; i++) {
		int id;
		cin >> id;
		who[id].pb({p[i], i});
	}
	for (int i = 1; i <= m; i++) {
		sort(all(who[i]));
		good[who[i].back().second] = true;
	}
	int ans = 0;
	for (int i = 0; i <  k; i++) {
		int c;
		cin >> c;
		c--;
		if (!good[c]) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}