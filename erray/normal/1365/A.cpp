#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<int> visn(n, 1), vism(m, 1);
		for (int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				int x;
				cin >> x;
				visn[i] &= !x;
				vism[j] &= !x;
			}
		}
		cout << (min(accumulate(visn.begin(), visn.end(), 0), accumulate(vism.begin(), vism.end(), 0))&1 ? "Ashish" : "Vivek") << '\n';
	}
}