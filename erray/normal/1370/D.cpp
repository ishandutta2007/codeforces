#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	set<int> st(a.begin(), a.end());
	vector<int> a2(st.begin(), st.end());
	auto ch = [&] (int mid) {
		for (int j = 0; j < 2; ++j) {
			int lst = 0;
			for (int i = 0, vis = 0; i < n; ++i) {
				if (vis ^ j || a2[mid] >= a[i]) {
					++lst;
					vis ^= 1;
				}			
			}
			if (lst >= k) return 1;
		}
		return 0;
	};
	int s = 0, e = a2.size() - 1;
	while (e - s > 1) {
		int mid = s + e >> 1;
		if (ch(mid)) e = mid;
		else s = mid;		
	}
	cout << a2[ch(s) ? s : e];
}