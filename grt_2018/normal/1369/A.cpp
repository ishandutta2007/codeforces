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

int main() {_
	int t,n;
	cin >> t;
	while(t--) {
		cin >> n;
		if(n%4==0) cout << "YES\n";
		else cout << "NO\n";
	}
	
}