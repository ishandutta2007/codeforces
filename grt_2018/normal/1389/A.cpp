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

int t,l,r;

int main() {_
	cin >> t;
	while(t--) {
		cin >> l >> r;
		if(2 * l <= r) {
			cout << l << " " << 2 * l << "\n";
		} else {
			cout << "-1 -1\n";
		}
	}
			
	
}