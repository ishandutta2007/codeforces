#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k, pos;
	vector<int> ppl;
	vector<int> key;
	cin >> n >> k >> pos;
	ppl.resize(n);
	key.resize(k);
	for (int i = 0; i < n; i++)
		cin >> ppl[i];
	for (int i = 0; i < k; i++)
		cin >> key[i];
	sort(ppl.begin(), ppl.end());
	sort(key.begin(), key.end());

	int ttime, mintime;
	mintime = 2*1e9+7;
	for (int i = 0; i <= k-n; i++) {
		ttime = 0;
		for (int j = 0; j < n; j++) {
			ttime = max(ttime, abs(pos-key[i+j]) + abs(key[i+j]-ppl[j]));
		}
		mintime = min(mintime, ttime);
	}
	cout << mintime << endl;

	return 0;
}