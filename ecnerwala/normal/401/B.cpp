#include<iostream>
#include<algorithm>

using namespace std;

typedef pair<int, int> pii;

pii evts[8000];

int main() {
	int x, k; cin >> x >> k;
	for(int i = 0; i < k; i++) {
		int t; cin >> t;
		int v; cin >> v;
		evts[i] = pii(v, t);
		if(t == 1) cin >> v;
	}
	evts[k++] = pii(x, 0);
	sort(evts, evts + k);

	int st = 0;
	int mi = 0, ma = 0;
	for(int i = 0; i < k; i++) {
		int v = evts[i].first;
		mi += (v - st - 1 + 1) / 2;
		ma += v - st - 1;
		st = v;
		if(evts[i].second == 1) st++;
	}
	cout << mi << ' ' << ma << '\n';
	return 0;
}