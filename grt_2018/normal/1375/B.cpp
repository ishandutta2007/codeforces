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

const int nax = 300+10;
int t,n,m;
int g[nax][nax];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main() {_
	cin >> t;
	while(t--) {
		cin >> n >> m;
		bool ok = 1;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				cin >> g[i][j];
				int good = 0;
				for(int k = 0; k < 4; ++k) {
					int x = i + dx[k], y = j + dy[k];
					if(0<=x&&x<n&&0<=y&&y<m) {
						good++;
					}
				}
				if(good < g[i][j]) ok = 0;
				//~ if(!ok) break;
				g[i][j] = good;
			}
			//~ if(!ok) break;
		}
		if(!ok) cout << "NO\n";
		else {
			cout << "YES\n";
			for(int i = 0; i < n; ++i) {
				for(int j = 0; j <m; ++j) {
					cout << g[i][j] << " ";
				}
				cout << "\n";
			}
		}
	}
	
}