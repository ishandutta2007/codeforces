#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 7;

int x[N], r[N], q[N];

struct fenwick {
	int n;
	vector <int> f;
	fenwick() {}
	void modify(int x, int y) {
		for (int i = x; i < n; i |= (i + 1)) f[i] += y;
	}
	int get(int r) {
		int sum = 0;
		for (int i = r; i >= 0; i &= i + 1, --i) sum += f[i];
		return sum;
	}
	int sum(int l, int r) {
		return get(r) - get(l - 1);
	}
};

unordered_map <int, fenwick> fn;
unordered_map <int, vector <int>> iq;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
    	cin >> x[i] >> r[i] >> q[i];
    	iq[q[i]].push_back(i);
    }
    vector <int> idx;
    for (int i = 0; i < n; ++i) idx.push_back(i);
    sort(idx.begin(), idx.end(), [&] (int i, int j) {
    	return r[i] > r[j];
    });
	for (auto &p : iq) {
		sort(p.second.begin(), p.second.end(), [&] (int i, int j) {
			return x[i] < x[j];
		});
		fn[p.first].f.resize(p.second.size());
		fn[p.first].n = p.second.size();
	}
	ll ans = 0;
	for (auto i : idx) {
		int L = x[i] - r[i];
		int R = x[i] + r[i];
		for (int j = q[i] - k; j <= q[i] + k; ++j) {
			if (iq.count(j)) {
				int cl = lower_bound(iq[j].begin(), iq[j].end(), L, [&] (int ii, int jj) {
					return x[ii] < jj;
				}) - iq[j].begin();
				int cr = upper_bound(iq[j].begin(), iq[j].end(), R, [&] (int ii, int jj) {
					return ii < x[jj];
				}) - iq[j].begin();
				if (cr > cl) {
					ans += fn[j].sum(cl, cr - 1);
				}
			}
		}
		int id = lower_bound(iq[q[i]].begin(), iq[q[i]].end(), x[i], [&] (int ii, int jj) {
			return x[ii] < jj;
		}) - iq[q[i]].begin();
		fn[q[i]].modify(id, 1);
	}
	cout << ans << '\n';
}