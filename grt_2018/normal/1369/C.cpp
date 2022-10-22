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
	int t,n,k;
	vi a, w;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		a.resize(n);
		w.resize(k);
		for(int i = 0; i < n; ++i) cin >> a[i];
		for(int i = 0; i < k; ++i) cin >> w[i];
		sort(w.begin(), w.end());
		sort(a.begin(), a.end());
		ll sum = 0;
		int big = n-1, sm = 0;
		int x = 0;
		while(x < k &&w[x] == 1) {
				sum += 2*a[big];
				big--;
				x++;
			}
		for(int i = k-1; i >= x; --i) {
			if(w[i] == 1) {
				sum += a[big];
				big--;
				continue;
			}
			sum += a[sm];
			sm++;
			w[i]--;
			while(w[i] > 1) {
				sm++;
				w[i]--;
			}
			sum += a[big];
			big--;
		}
		cout << sum << "\n";
	}	
				
	
			
	
}