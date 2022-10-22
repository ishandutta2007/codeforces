#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 300 * 1000 + 10;
int t, n;
int a[nax];
vi v[nax];
bool ans[nax];

int main() {_
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			v[i].clear();
			ans[i] = 0;
		}
		for(int i = 1; i <= n; ++i) {
			v[a[i]].PB(i);
		}
		int x = 1, y = n;
		for(int i = 1; i <= n; ++i) {
			if((int)v[i].size() == 0) break;
			ans[i] = 1;
			if((int)v[i].size() > 1) break;
			if(v[i][0] == x) {
				x++;
			} else if(v[i][0] == y) {
				y--;
			} else {
				break;
			}
		}
		bool ok = 1;
		for(int i = 1; i <= n; ++i) {
			if((int)v[i].size() != 1) {
				ok = 0;
				break;
			}
		}
		if(ok) ans[n] = 1;
		for(int i = 1; i <= n; ++i) {
			cout << ans[n - i + 1];
		}
		cout << "\n";
	}
	
}