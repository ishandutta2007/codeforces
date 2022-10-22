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

int t, n;

int main() {_
	cin >> t;
	while(t--) {
		cin >> n;
		if(n == 1) cout << "0\n";
		else if(n == 2) cout << "1\n";
		else if(n == 3) cout << "2\n";
		else if(n % 2 == 0) cout << "2\n";
		else cout << "3\n";
	}
	
}