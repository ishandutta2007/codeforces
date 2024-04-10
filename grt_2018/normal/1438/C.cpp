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

int t, n, m;
int a[110][110];

int main() {_
	cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				cin >> a[i][j];
			}
		}
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				bool b = (i + j)&1;
				if(a[i][j]%2!=b) {
					a[i][j]++;
				}
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
	}
	
}