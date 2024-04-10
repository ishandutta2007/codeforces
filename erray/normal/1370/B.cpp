#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n * 2);
		vector<vector<int>> st(2);
		for (int i = 0; i < n * 2; ++i) { 
			cin >> a[i];
			st[a[i] & 1].push_back(i + 1);
		}
		if (accumulate(a.begin(), a.end(), 0ll) & 1) {
			st[1].pop_back();
			st[0].pop_back();		
		} else {
			bool b = st[0].size() < 2;
			st[b].pop_back(); 		
			st[b].pop_back();
		}
		for (int j = 0; j < 2; ++j) {
			for (int i = 0; i < max((int)st[j].size() - 1, 0); i += 2) {
				cout << st[j][i] << ' ' << st[j][i + 1] << '\n';
			}
		}
	}
}