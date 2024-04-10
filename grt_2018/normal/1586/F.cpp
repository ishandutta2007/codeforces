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

const int nax = 1000 + 10;
int n, k;
int w[nax][nax];
int ans;

int main() {_
	cin >> n >> k;
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			for(int s = 1, x = k; ; x *= k, s++) {
				if(i / x == j / x) {
					w[j][i] = s;
					ans = max(ans, s);
					break;
				}
			}
		}
	}
	cout << ans << "\n";
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			cout << w[j][i] << " ";
		}
	}
	
}