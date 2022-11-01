#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector <int> cnt(n + 1);
		for (int i = 0; i < n; i++)
			cnt[a[i]]++;
		set <int> mex;
		for (int i = 0; i <= n; i++)
			if (!cnt[i])
				mex.insert(i);
		vector <int> ans;
		vector <bool> used(n);
		int cn = 0;
		while (cn < n) {
			int hm = *mex.begin();
			cnt[hm]++;
			mex.erase(hm);
			if (hm == n) {
				int pos = 0;
				while (used[pos]) pos++;
				ans.push_back(pos);
				cnt[a[pos]]--;
				if (!cnt[a[pos]]) mex.insert(a[pos]);
				a[pos] = hm;
				continue;
			}
			int pos = hm;
			if (pos >= n) pos--;
			if (used[pos]) pos--;
			ans.push_back(pos);
			cnt[a[pos]]--;
			if (!cnt[a[pos]]) mex.insert(a[pos]);
			a[pos] = hm;
			used[pos] = true;
			cn++;
		}
		cout << ans.size() << '\n';
		for (auto &now : ans)
			cout << now + 1 << ' ';
		cout << '\n';
	}
	return 0;
}