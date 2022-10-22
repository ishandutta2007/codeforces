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

int t,k,n;
set<int>s;


int main() {_
	cin >> t;
	while(t--) {
		cin >> n >> k;
		s.clear();
		for(int a,i = 0; i < n; ++i) {
			cin >> a;
			s.insert(a);
		}
		if((int)s.size() > k) {
			cout << "-1\n";
			continue;
		}
		vi v = {};
		for(auto it : s) {
			v.PB(it);
		}
		cout << n * k << "\n";
		while((int)v.size() < k) v.PB(v[0]);
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= k; ++j) {
				cout << v[j-1] << " ";
			}
		}
		cout << "\n";
	}
}