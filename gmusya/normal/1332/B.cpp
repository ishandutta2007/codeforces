#include <iostream>
#include <vector>

using namespace std;

int MAXN = 1001;

int main() {
	vector <int> lp(MAXN), pr;
	for (int i = 2; i < MAXN; i++) {
		if (!lp[i]) pr.push_back(i), lp[i] = i;
		for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] < MAXN; j++)
			lp[i * pr[j]] = pr[j];
	}
	vector <int> ans(MAXN);
	for (int i = 0; i < 11; i++)
		ans[pr[i]] = i + 1;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector <bool> used(12);
		vector <int> answer(n);
		for (int i = 0; i < n; i++)
			answer[i] = ans[lp[a[i]]];
		for (int i = 0; i < n; i++)
			used[answer[i]] = true;
		int sum = 0;
		for (int i = 0; i < 12; i++)
			sum += used[i];
		vector <int> hm(12);
		int cnt = 0;
		for (int i = 0; i < 12; i++) 
			if (used[i]) hm[i] = ++cnt;
		cout << sum << endl;
		for (int i = 0; i < n; i++)
			cout << hm[answer[i]] << " ";
		cout << endl;
	}
	return 0;
}