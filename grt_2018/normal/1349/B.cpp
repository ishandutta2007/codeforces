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

const int nax = 100*1000+10;
int t,n,k;
int a[nax];

int main() {_
	cin >> t;
	while(t--) {
		cin >> n >> k;
		bool exist = 0;
		int mx = -1;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			if(a[i] == k) exist = 1;
			if(i > 1) {
				mx = max(mx,min(a[i],a[i-1]));
			}
			if(i > 2) {
				vi v = {};
				for(int j = i; j > i-3; --j) v.PB(a[j]);
				sort(v.begin(),v.end());
				mx = max(mx, v[1]);
			}
		}
		
		if(exist && n == 1) {
			cout << "yes\n";
			continue;
		}
		if(!exist || mx < k ) {
			cout << "no\n";
		} else {
			cout << "yes\n";
		}
	}
	
}