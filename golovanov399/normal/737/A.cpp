#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	int n = nxt(), k = nxt(), s = nxt(), t = nxt();
	vector<pair<int, int>> cars(n);
	for (int i = 0; i < n; ++i) {
		cars[i].first = nxt();
		cars[i].second = nxt();
	}

	vector<int> g(k);
	for (int i = 0; i < k; ++i) {
		g[i] = nxt();
	}
	g.push_back(0);
	sort(all(g));
	g.push_back(s);
	vector<int> d(k + 1);
	for (int i = 0; i <= k; ++i) {
		d[i] = g[i + 1] - g[i];
	}

	sort(all(d));
	vector<int> pref(d.size() + 1);
	for (int i = 0; i < (int)d.size(); ++i) {
		pref[i + 1] = pref[i] + d[i];
	}

	int opt = -1;
	for (int i = 0; i < n; ++i) {
		int v = cars[i].second;
		auto lb1 = upper_bound(all(d), v / 2);
		auto lb2 = upper_bound(all(d), v);
		if (lb2 != d.end()) {
			continue;
		}
		int left1 = lb1 - d.begin();
		int left2 = lb2 - d.begin();
		long long tm = pref[left1] - pref[0];
		tm += 3ll * (pref[left2] - pref[left1]);
		tm -= v * 1ll * (left2 - left1);
		if (tm <= t) {
			if (opt == -1 || cars[opt].first > cars[i].first) {
				opt = i;
			}
		}
	}

	printf("%d\n", (opt == -1) ? -1 : cars[opt].first);

	return 0;
}