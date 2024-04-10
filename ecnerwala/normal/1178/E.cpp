#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	int l = 0, r = int(s.size()) - 1;
	string pref;
	string suff;
	while (l <= r) {
		if (l == r) {
			pref += s[l];
			break;
		} else if (s[l] == s[r]) {
			pref += s[l];
			suff += s[r];
			l++, r--;
		} else if (r - l == 1) {
			l++;
		} else if (s[r] == s[l+1]) {
			l++;
		} else if (s[l] == s[r-1]) {
			r--;
		} else {
			l++, r--;
		}
	}

	pref.insert(pref.end(), suff.rbegin(), suff.rend());
	cout << pref << '\n';
	return 0;
}