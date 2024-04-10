#include<bits/stdc++.h>
 
using namespace std;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n * 2);
		bitset<2001> bs;
		bs[0] = true;
		for (int i = 0; i < n * 2; --a[i], ++i) cin >> a[i];
		a.push_back(2 * n);
		for (int i = 0; i < n * 2; ++i) {
			int ind = i + 1;
			while (a[ind] < a[i]) ++ind;
			bs |= (bs << (ind - i));
			i = ind - 1;  
		}
		cout << (bs[n] ? "YES" : "NO") << '\n';
	}
}