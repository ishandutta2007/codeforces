#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct Segment {
	int x, a, b;
	bool operator < (const Segment& v) const {
		if (x == v.x) return a < v.a;
		else return x < v.x;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int top, bottom, left, right;
	cin >> left >> top >> right >> bottom;

	int n;
	cin >> n;

	vector<pii> p;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		p.push_back(pii(a,b));
	}

	vector<Segment> segs;
	for (int i = 0; i < n; i++) {
		if (p[i].first == p[(i+1)%n].first) {
			segs.push_back({p[i].first, p[i].second, p[(i+1)%n].second});
		}
	}
	sort(segs.begin(), segs.end());


	int ans = 0;
	set<pii> cur;
	for (const Segment& s : segs) {
		// no need to continue
		if (s.x >= right) break;

		a = s.a;
		b = s.b;

		// enter, check connected ?
		if (a > b) {
			swap(a, b);
			if (b <= bottom || a >= top) continue;
			a = max(a, bottom);
			b = min(b, top);

			auto nxt = cur.lower_bound(pii(a,b));
			if (nxt != cur.begin()) {
				auto pre = prev(nxt);
				if (pre->second == a) {
					a = pre->first;
					cur.erase(pre);
				}
			}
			if (nxt->first == b) {
				b = nxt->second;
				cur.erase(nxt);
			}

			cur.insert(pii(a,b));
		}

		// exit, check contained ?
		else {
			if (b <= bottom || a >= top) continue;
			a = max(a, bottom);
			b = min(b, top);

			auto it = prev(cur.upper_bound(pii(a,INF)));
			if (it->first == a && it->second == b) {
				cur.erase(it);
				if (s.x > left) ans++;
			}
			else if (it->first == a) {
				a = b;
				b = it->second;
				cur.erase(it);
				cur.insert(pii(a,b));
			}
			else if (it->second == b) {
				b = a;
				a = it->first;
				cur.erase(it);
				cur.insert(pii(a,b));
			}
			else {
				if (s.x > left) ans--;
				int va = it->first;
				int vb = a;
				a = b;
				b = it->second;
				cur.erase(it);
				cur.insert(pii(va,vb));
				cur.insert(pii(a,b));
			}
		}
	}

	// add the unfinished sections
	ans += cur.size();

	cout << ans << nl;

	return 0;
}