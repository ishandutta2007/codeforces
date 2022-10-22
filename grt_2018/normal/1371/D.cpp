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

int t;
int n,k;
bool grid[301][301];

int main() {_
	cin >> t;
	while(t--) {
		cin >> n >> k;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				grid[i][j] = 0;
			}
		}
		for(int i = 0; i < n; ++i) {
			for(int step = 0; step < n; step++) {
				if(k == 0) break;
				grid[step][(i + step)%n] = 1;
				k--;
			}
			if(k == 0) {
				break;
			}
		}
		int mxR = 0,miR=301,ans = 0;
		for(int i = 0; i < n; ++i) {
			int sum = 0;
			for(int j = 0; j < n; ++j) {
				sum += grid[i][j];
			}
			mxR = max(mxR, sum);
			miR = min(miR, sum);
		}
		ans += (mxR - miR)* (mxR - miR);
		mxR = 0; miR = 301;
		for(int i = 0; i < n; ++i) {
			int sum = 0;
			for(int j = 0; j < n; ++j) {
				sum += grid[j][i];
			}
			mxR = max(mxR, sum);
			miR = min(miR, sum);
		}
		ans += (mxR - miR)* (mxR - miR);
		cout << ans << "\n";
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				cout << grid[i][j];
			}
			cout << "\n";
		}
	}
	
}