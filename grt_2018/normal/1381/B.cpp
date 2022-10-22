#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
#define ST first
#define ND second
#define PB push_back
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int nax = 2000 + 10;
int t,n;
int p[2*nax];
bool dp[nax];

int main() {_
	cin >> t;
	while(t--) {
		cin >> n;
		vi g = {};
		int last = -1, r = 1;
		for(int i = 1; i <= 2 * n; ++i) {
			cin >> p[i];
			if(i == 1) last = p[i];
			else {
				if(p[i] < last) {
					r++;
				} else {
					g.PB(r);
					r = 1;
					last = p[i];
				}
			}
		}
		g.PB(r);
		for(int i = 1; i <= n; ++i) dp[i] = 0;
		dp[0] = 1;
		for(int x : g) {
			for(int i = n; i >= x; --i) {
				dp[i] = dp[i] | dp[i - x];
			}
		}
		if(dp[n]) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
		
	
}