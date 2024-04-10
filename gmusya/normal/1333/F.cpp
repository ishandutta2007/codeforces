#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> lp(n + 1), pr;
	for (int i = 2; i <= n; i++) {
		if (!lp[i]) lp[i] = i, pr.push_back(i);
		for (int j = 0; j < pr.size() && pr[j] <= lp[i] && pr[j] * i <= n; j++) 
			lp[pr[j] * i] = pr[j];
	}
	vector <int> hm;
	for (int i = 2; i <= n; i++)
		hm.push_back(i / lp[i]);
	sort(hm.begin(), hm.end());
	for (int i = 0; i < hm.size(); i++)
		cout << hm[i] << " ";
	return 0;
}