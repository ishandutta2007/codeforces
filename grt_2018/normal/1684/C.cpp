//GRT_2018
#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

int t, n, m;
vector<vi>v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n >> m;
		v.resize(n);
		bool ok = true;
		vi p = {};
		for(int i = 0; i < n; ++i) {
			v[i].resize(m);
			vi vec(m);
			for(auto &x : v[i]) {
				cin >> x;
			}
			for(int j = 0; j < m; ++j) {
				vec[j] = v[i][j];
			}
			sort(vec.begin(), vec.end());
			vi pos = {};
			for(int j = 0; j < m; ++j) {
				if(v[i][j] != vec[j]) {
					pos.PB(j);
				}
			}
			if((int)pos.size() > 2) {
				ok = false;
				continue;
			} else if((int)pos.size() == 2) {
				if((int)p.size() != 0 && p != pos) {
					ok = false;
				}
				p = pos;
			}
		}
		if(!ok) {
			cout << "-1\n";
			continue;
		}
		if((int)p.size() == 0) {
			cout << "1 1\n";
			continue;
		}
		//cerr << "(" << p[0] << " " << p[1] << ")\n";
		bool ok2 = true;
		for(int i = 0; i < n; ++i) {
			swap(v[i][p[0]], v[i][p[1]]);
			for(int j = 1; j < m; ++j) {
				if(v[i][j - 1] > v[i][j]) {
					ok2 = false;
				}
			}
		}
		if(!ok2) {
			cout << "-1\n";
			continue;
		}
		cout << p[0] + 1 << " " << p[1] + 1 << "\n";
	}
}