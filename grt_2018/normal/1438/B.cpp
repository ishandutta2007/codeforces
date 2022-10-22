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
set<int>s;

int main() {_
	cin >> t;
	while(t--) {
		cin >> n;
		s.clear();
		for(int a,i = 0; i < n; ++i) {
			cin >> a;
			s.insert(a);
		}
		if((int)s.size() == n) cout << "NO\n";
		else cout << "YES\n";
	}
	
}