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
		vi a(n);
		int s = 0;
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
			s += a[i];
		}
		if(s == 0) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		vi b(n);
		for(int i = 0; i < n; ++i) {
			if(s - a.back() != 0) {
				b[n - i - 1] = a.back();
				s -= a.back();
				a.pop_back();
			} else {
				for(int j = (int)a.size() - 2; j >= 0; --j) {
					if(a[j] != a.back()) {
						swap(a.back(), a[j]);
						break;
					}
				}
				b[n - i - 1] = a.back();
				s -= a.back();
				a.pop_back();
			}
		}
		for(int x : b) cout << x << " ";
		cout << "\n";
	}
	
	
}