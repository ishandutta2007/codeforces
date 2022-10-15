#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<long long> s(n);
	for (int i = 0; i < n; ++i) cin >> s[i];
	sort(s.begin(), s.end());
	vector<long long> ct(n - 1); 
	for (int i = 1; i < n; ++i) {
		ct[i - 1] = s[i] - s[i - 1];				
	}
	sort(ct.begin(), ct.end());
	vector<long long> pref(n);
	for (int i = 0; i < n - 1; ++i) pref[i + 1] = pref[i] + ct[i];
	int q;                                                           
	cin >> q;
	while (q--) {
		long long l, r;
		cin >> l >> r;
		r -= l - 1;
		int a = upper_bound(ct.begin(), ct.end(), r) - ct.begin();
		cout << pref[a] + r * (n - a) << ' ';
	}
}