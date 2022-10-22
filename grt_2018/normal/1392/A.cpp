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

const int nax = 200 * 1000 + 10;
int t, n, a[nax];

int main() {_
	cin >> t;
	while(t--) {
		cin >> n;
		bool same = 1;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			if(i > 1 && a[i] != a[i - 1]) same = 0;
		}
		if(!same) cout << "1\n";
		else cout << n << "\n";
	}
	
}