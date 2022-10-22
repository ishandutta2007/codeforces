#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	map<int,int> hmap;
	int f[n+1];
	vector<int> h;
	set<int> good, found;
	for (int i = 1; i <= n; i++) {
		cin >> f[i];
		if (f[i] == i) {
			found.insert(f[i]);
			good.insert(f[i]);
			h.push_back(f[i]);
			hmap.insert(pair<int,int>(f[i],h.size()));
		}
		else
			found.insert(f[i]);
	}
	if (found != good) {
		cout << -1 << endl;
	}
	else {
		cout << h.size() << endl;
		for (int i = 1; i <= n; i++)
			cout <<  hmap[f[i]] << " ";
		cout << endl;
		for (auto &i : h)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}