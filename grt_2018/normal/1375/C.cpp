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

int t,n;
const int nax = 300*1000+10;
int a[nax];

int main() {_
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		int last = a[1];
		int selast = -1;
		int cnt = 1;
		for(int i = 2; i <= n; ++i) {
			if(a[i] > last) {
				cnt = 1;
				continue;
			}
			cnt++;
		}
		if(cnt == 1) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
	
}