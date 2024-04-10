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

const int nax = 100;
int t,n;
int a[nax],b[nax];

int main() {_
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
			if(i%2==0) a[i] = -abs(a[i]);
			else a[i] = abs(a[i]);
		}
		for(int i = 0; i < n; ++i) {
			cout << a[i] << " ";
		}
		cout << "\n";
	}
	
}