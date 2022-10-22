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
int t, n, a[nax];
ll k;

int main() {_
	cin >> t;
	while(t--) {
		cin >> n >> k;
		int A = -INF, B = INF;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			A = max(A, a[i]);
			B = min(B, a[i]);
		}
		k--;
		if(k % 2 == 0) {
			for(int i = 1; i <= n; ++i) {
				cout << A - a[i] << " ";
			}
		} else {
			for(int i = 1; i <= n; ++i) {
				cout << a[i] - B << " ";
			}
		}
		cout << "\n";
	}
	
}