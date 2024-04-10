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

const int nax = 110;
int t, n, k;
pi p[nax];

int main() {_
	cin >> t;
	while(t--) {
		cin >> n >> k;
		for(int i = 0; i < n; ++i) {
			cin >> p[i].ST >> p[i].ND;
		}
		bool ok = 0;
		for(int i = 0; i < n; ++i) {
			int mx = 0;
			for(int j = 0; j < n; ++j) {
				mx = max(mx, abs(p[i].ST - p[j].ST) + abs(p[i].ND - p[j].ND));
			}
			if(mx <= k) {
				ok = 1;
				break;
			}
		}
		if(ok) cout << "1\n";
		else cout << "-1\n";
	}
			
	
}