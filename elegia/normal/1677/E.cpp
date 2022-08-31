#include <cmath>

#include <algorithm>
#include <stack>
#include <bitset>
#include <numeric>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

typedef long long ll;

using namespace std;

// const int P = 998244353;

// int norm(int x) { return x >= P ? x - P : x; }
// int reduce(int x) { return x < 0 ? x + P : x; }
// int neg(int x) { return x ? P - x : 0; }
// void add(int& x, int y) { if ((x += y - P) < 0) x += P; }
// void sub(int& x, int y) { if ((x -= y) < 0) x += P; }
// void fam(int& x, int y, int z) { x = (x + y * (ull)z) % P; }
// int mpow(int x, unsigned k) {
// 	if (k == 0) return 1;
// 	int ret = mpow(x * (ull)x % P, k >> 1);
// 	if (k & 1) ret = ret * (ull)x % P;
// 	return ret;
// }

const int _ = 200005;

int N, Q;
int p[_], q[_], vl[_], vr[_], nl[_], nr[_];
vector<pair<int, int>> qry[_], prs[_];
vector<int> pts[_];
ll ans[1000005];

struct FWT {
	ll fw[_];
	void chg(int k, ll x) {
		for (; k <= N; k += k & -k) fw[k] += x;
	}
	ll qry(int k) {
		ll ret = 0;
		for (; k; k &= k - 1) ret += fw[k];
		return ret;
	}
} f00, f01, f10, f11;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> Q;
	for (int i = 1; i <= N; ++i) { cin >> p[i]; q[p[i]] = i; }
	for (int i = 1; i <= Q; ++i) {
		int l, r; cin >> l >> r;
		qry[l].emplace_back(r, i);
	}
	for (int val = 1; val <= N; ++val) {
		int i = q[val];
		int cl = i, cr = i;
		if (vl[i - 1]) cl = vl[i - 1];
		if (vr[i + 1]) cr = vr[i + 1];
		nl[i] = cl; nr[i] = cr;
		vl[cl] = vl[cr] = cl;
		vr[cl] = vr[cr] = cr;
		// cerr << val << ": " << i << ", " << cl << ' ' << cr << '\n';
	}
	for (int i = 1; i <= N; ++i)
		for (int j = i + 1; j <= N / i; ++j) {
			int k = i * j, pos = q[k];
			int ii = q[i], jj = q[j]; if (ii > jj) swap(ii, jj);
			
			if (ii < nl[pos] || jj > nr[pos]) continue;
			// cerr << ii << ' ' << pos << ' ' << jj << ": " << nl[pos] << ' ' << nr[pos] << '\n';
			prs[pos].emplace_back(min(ii, pos), max(jj, pos));
		}
	auto pb = [&](int l, int r) {
		// cerr << "PB " << l << ' ' << r << '\n';
		pts[l].push_back(r);
	};
	for (int i = 1; i <= N; ++i) {
		sort(prs[i].begin(), prs[i].end(), greater<pair<int, int>>());
		vector<pair<int, int>> cur;
		for (const auto& pr : prs[i])
			if (cur.empty() || cur.back().second > pr.second)
				cur.push_back(pr);
		reverse(cur.begin(), cur.end());
		if (!cur.empty()) {
			// cerr << i << ": ";
			// for (const auto& pr : cur) cerr << pr.first << ", " << pr.second << " "; cerr << '\n';
			// cerr << "[" << nl[i] << ' ' << nr[i] << "]\n";
			for (const auto& pr : cur) {
				pb(pr.first, pr.second);
				// cerr << pr.first << ", " << pr.second << " ";
			}
			// cerr << '\n';
			for (int i = 1; i != cur.size(); ++i) {
				int l = cur[i - 1].first, r = cur[i].second;
				pb(l, -r);
			}
			int l = cur.back().first, r = cur.front().second;
			int L = nl[i], R = nr[i];
			pb(l, -(R + 1));
			pb(L - 1, -r);
			pb(L - 1, R + 1);
		}
	}
	// pts[2].push_back(2);
	for (int i = N; i; --i) {
		for (int j : pts[i]) {
			int pos = j, sgn = 1;
			if (j < 0) { pos = -j; sgn = -1; }
			f11.chg(pos, sgn);
			f01.chg(pos, sgn * (i + 1));
			f10.chg(pos, sgn * (pos - 1));
			f00.chg(pos, sgn * (i + 1LL) * (pos - 1LL));
		}
		// cerr << pts[i].size() << ", " << qry[i].size() << '\n';
		for (const auto& qr : qry[i]) {
			int j = qr.first, id = qr.second;
			// cerr << "qry " << i << " " << j << " -> " << id << '\n';
			// cerr << f00.qry(j) << ' ' << f01.qry(j) << ' ' << f10.qry(j) << ' ' << f11.qry(j) << '\n';
			ans[id] -= f00.qry(j);
			ans[id] += f01.qry(j) * j;
			ans[id] += f10.qry(j) * i;
			ans[id] -= f11.qry(j) * i * j;
		}
	}
	for (int i = 1; i <= Q; ++i) cout << ans[i] << '\n';

	return 0;
}