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

const int nax = 100*1000+10;
int n,t;
int a[nax];

int main() {_
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		int ans = -1;
		for(int i = 2; i <= n; ++i) {
			int x = 0;
			if(a[i] < a[i-1]) {
				int diff = a[i-1] - a[i];
				for(int j = 0; j < 32; ++j) {
					if((1<<j)&diff) x = j;
				}
				a[i] = a[i-1];
				ans = max(ans,x);
			}
		}
		cout << ans +1 << "\n";
	}
}