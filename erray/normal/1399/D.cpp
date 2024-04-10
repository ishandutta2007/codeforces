#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		string s;
		cin >> n >> s;
		vector<int> bel(n), zero, one, f(n);
		iota(f.rbegin(), f.rend(), 0);	
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') {		
				if (one.empty()) {
					bel[i] = f.back();
					f.pop_back();
				} else {
					bel[i] = one.back();
					one.pop_back();
				}
				zero.push_back(bel[i]);
			} else {
				if (zero.empty()) {
					bel[i] = f.back();
					f.pop_back();
				} else {
					bel[i] = zero.back();
					zero.pop_back();
				}				
				one.push_back(bel[i]);
			}
		}
		cout << n - (int) f.size() << '\n';
		for (auto el : bel) cout << el + 1 << ' ';
		cout << '\n';
	}
}