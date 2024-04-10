#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

const int nax = 300 *1000 + 10, INF = 1e9 + 10;
int t,n;
int a[nax];
vi occ[nax];
int ans[nax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			occ[i].clear();
			occ[i] = {0};
			ans[i] = INF;
		}
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			occ[a[i]].PB(i);
		}
		for(int i = 1; i <= n; ++i) {
			occ[i].PB(n+1);
			int mx = 0;
			for(int j = 1; j < (int)occ[i].size(); ++j) {
				mx = max(mx, occ[i][j] - occ[i][j - 1]);
			}
			ans[mx] = min(ans[mx], i);
		}
		for(int i = 2; i <= n; ++i) {
			ans[i] = min(ans[i], ans[i - 1]);
		}
		for(int i = 1; i <= n; ++i) cout << (ans[i] == INF ? -1 : ans[i]) << " ";
		cout << "\n";
				
	}
	
	
}