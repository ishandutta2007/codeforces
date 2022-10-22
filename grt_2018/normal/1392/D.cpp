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

const int nax = 200 * 1000 + 10, INF = 1e9 + 10;
int t, n;
char a[nax];
ll k;

int main() {_
	cin >> t;
	while(t--) {
		cin >> n;
		bool same = 1;
		int x = 1;
		vi len = {};
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			if(i > 1 && a[i] != a[i - 1]) {
				same = 0;
				len.PB(x);
				x = 1;
			} else if(i > 1) {
				x++;
			}
		}
		len.PB(x);
		if((int)len.size() == 1) {
			cout << (n - 1) / 3 + 1 << "\n";
		} else {
			int ans = 0;
			if(a[1] == a[n]) {
				len[0] += len.back();
				len.pop_back();
			}
			for(int y : len) {
				ans += y / 3;
			}
			cout << ans << "\n";
		}
		
	}
	
}