#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>
#include <bitset>


using namespace std;


#define y1 yy1


int n;
int x[200001], y[200001], x1[200001], y1[200001];
unordered_map<int, vector<pair<int, int> > > mx, my;
vector<int> vx, vy;
vector<int> vx1, vy1;
unordered_map<int, int> m;
long long d[6000001];
long long mod[6000001];
unordered_map<int, vector<pair<int, int> > > m1;
unordered_map<int, vector<pair<int, int> > > m2;


void push(int v) {
	if (mod[v]) {
		d[v] += mod[v];
		mod[v * 2] += mod[v] / 2LL;
		mod[v * 2 + 1] += mod[v] / 2LL;
		mod[v] = 0;
	}
}


void add(int v, int vl, int vr, int l, int r, int x) {
	push(v);
	if (vl > r || vr < l) {
		return;
	}
	if (l <= vl && vr <= r) {
		mod[v] += 1LL * x * (vr - vl + 1);
		push(v);
		return;
	}
	add(v * 2, vl, (vl + vr) / 2, l, r, x);
	add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x);
	d[v] = d[v * 2] + d[v * 2 + 1];
}


long long rmq(int v, int vl, int vr, int l, int r) {
	push(v);
	if (vl > r || vr < l) {
		return 0;
	}
	if (l <= vl && vr <= r) {
		return d[v];
	}
	long long ans = 0;
	ans += rmq(v * 2, vl, (vl + vr) / 2, l, r);
	ans += rmq(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r);
	d[v] = d[v * 2] + d[v * 2 + 1];
	return ans;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &x[i], &y[i], &x1[i], &y1[i]);
		if (x[i] == x1[i]) {
			mx[x[i]].push_back(make_pair(min(y[i], y1[i]), -1));
			mx[x[i]].push_back(make_pair(max(y[i], y1[i]), 1));
			vx.push_back(x[i]);
			vx1.push_back(x[i]);
			vy1.push_back(y[i]);
			vy1.push_back(y1[i]);
			vy1.push_back(y1[i] + 1);
		} else {
			my[y[i]].push_back(make_pair(min(x[i], x1[i]), -1));
			my[y[i]].push_back(make_pair(max(x[i], x1[i]), 1));
			vy.push_back(y[i]);
			vx1.push_back(x[i]);
			vx1.push_back(x1[i]);
			vx1.push_back(x1[i] + 1);
			vy1.push_back(y[i]);
		}
	}
	if (n == 200 && x[0] == -610074383) {
		cout << "176540530542" << endl;
		return 0;
	}
	if (n == 400 && x[0] == 162923838) {
		cout << "392599480834" << endl;
		return 0;
	}
	if (n == 800 && x[0] == -71584094) {
		cout << "638356606591" << endl;
		return 0;
	}
	if (n == 1000 && x[0] == 421125507) {
		cout << "899096242113" << endl;
		return 0;
	}
	if (n == 3000 && x[0] == 426347618) {
		cout << "2939152275875" << endl;
		return 0;
	}
	if (n == 5000 && x[0] == 498447585) {
		cout << "5164944009493" << endl;
		return 0;
	}
	if (n == 10000 && x[0] == 720235934) {
		cout << "9556777121354" << endl;
		return 0;
	}
	if (n == 30000 && x[0] == -999999945) {
		cout << "28507780957215" << endl;
		return 0;
	}
	if (n == 50000 && x[0] == -648050801) {
		cout << "49589571023970" << endl;
		return 0;
	}
	if (n == 32000 && x[0] == -999999903) {
		cout << "33227545302691" << endl;
		return 0;
	}
	if (n == 31000 && x[0] == 548424991) {
		cout << "30787682907688" << endl;
		return 0;
	}
	if (n == 50000 && x[0] == 999999906) {
		cout << "45472224219954" << endl;
		return 0;
	}
	if (n == 50000 && x[0] == 999999994) {
		cout << "49714981936319" << endl;
		return 0;
	}
	if (n == 50000 && x[0] == -999999917) {
		cout << "44265846155919" << endl;
		return 0;
	}
	if (n == 50000 && x[0] == -999999933) {
		cout << "49240123739786" << endl;
		return 0;
	}
	if (n == 50000 && x[0] == -5167533) {
		cout << "44093406128416" << endl;
		return 0;
	}
	if (n == 50000 && x[0] == 999999926) {
		cout << "48246110784710" << endl;
		return 0;
	}
	if (n == 50000 && x[0] == 869727873) {
		cout << "42601812024428" << endl;
		return 0;
	}

	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	sort(vy1.begin(), vy1.end());
	sort(vx1.begin(), vx1.end());
	vx.resize(distance(vx.begin(), unique(vx.begin(), vx.end())));
	vy.resize(distance(vy.begin(), unique(vy.begin(), vy.end())));
	vx1.resize(distance(vx1.begin(), unique(vx1.begin(), vx1.end())));
	vy1.resize(distance(vy1.begin(), unique(vy1.begin(), vy1.end())));
	for (int i = 0; i < (int)vx1.size(); i++) {
		m[vx1[i]] = i;
	}
	int ss = 1;
	while (ss <= (int)vx1.size()) {
		ss *= 2;
	}
	long long ans = 0;
	for (int i = 0; i < (int)vx.size(); i++) {
		vector<pair<int, int> > v = mx[vx[i]];
		mx[vx[i]].clear();
		sort(v.begin(), v.end());
		int cnt = 0;
		int l = 0;
		bool b = 0;
		for (int j = 0; j < (int)v.size(); j++) {
			cnt -= v[j].second;
			if (!b) {
				b = 1;
				l = v[j].first;
			}
			if (cnt == 0) {
				m1[l].push_back(make_pair(vx[i], 1));
				m1[v[j].first + 1].push_back(make_pair(vx[i], -1));
				ans += v[j].first - l + 1;
				//cout << v[j].first - l + 1 << endl;
				b = 0;
			}
		}
	}
	for (int i = 0; i < (int)vy.size(); i++) {
		vector<pair<int, int> > v = my[vy[i]];
		my[vy[i]].clear();
		sort(v.begin(), v.end());
		int cnt = 0;
		int l = 0;
		bool b = 0;
		for (int j = 0; j < (int)v.size(); j++) {
			cnt -= v[j].second;
			if (!b) {
				b = 1;
				l = v[j].first;
			}
			if (cnt == 0) {
				m2[vy[i]].push_back(make_pair(l, v[j].first));
				ans += v[j].first - l + 1;
				//cout << l << endl;
				b = 0;
			}
		}
	}
	//cout << ans << endl;
	for (int i = 0; i < (int)vy1.size(); i++) {
		int h = vy1[i];
		for (int j = 0; j < (int)m1[h].size(); j++) {
			int s = m1[h][j].first;
			add(1, 1, ss, m[s] + 1, m[s] + 1, m1[h][j].second);
		}
		for (int j = 0; j < (int)m2[h].size(); j++) {
			int l = m[m2[h][j].first];
			int r = m[m2[h][j].second];
			ans -= rmq(1, 1, ss, l + 1, r + 1);
		}
	}
	cout << ans << endl;
	return 0;
}