#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Tree {
	ll t[500007 * 4];
	int ma[500007 * 4];
	ll p[500007 * 4];

	inline void push(int v, int vl, int vr) {
		if (p[v] != 0) {
			t[v] += p[v] * (vr - vl + 1);
			ma[v] += p[v];
			if (v * 2 +1< 500007 * 4) p[v * 2 + 1] += p[v];
			if (v * 2 + 2< 500007 * 4) p[v * 2 + 2] += p[v];
			p[v] = 0;
		}
	}

	void add(int v, int vl, int vr, int l, int r, int val) {
		push(v, vl, vr);
		if (r < vl || l > vr) return;
		if (vl >= l && vr <= r) {
			p[v] += val;
			push(v, vl, vr);
		} else {
			int vm = (vl + vr) >> 1;
			add(v * 2 + 1, vl, vm, l, r, val);
			add(v * 2 + 2, vm + 1, vr, l, r, val);
			t[v] = t[v * 2 + 1] + t[v * 2 + 2];
			ma[v] = max(ma[v * 2 + 1], ma[v * 2 + 2]);
		}
	}

	ll get(int v, int vl, int vr, int l, int r) {
		push(v, vl, vr);
		if (r < vl || l > vr) return 0;
		if (vl >= l && vr <= r) return t[v];
		int vm = (vl + vr) >> 1;
		return get(v * 2 + 1, vl, vm, l, r) + get(v * 2 + 2, vm + 1, vr, l, r);
	}

	int get_pos(int v, int vl, int vr, int val) {
		push(v, vl, vr);
		if (vl == vr) return vl;
		int vm = (vl + vr) >> 1;
		push(v * 2 + 1, vl, vm);
		if (ma[v * 2 + 1] < val) return get_pos(v * 2 + 2, vm + 1, vr, val);
		return get_pos(v * 2 + 1, vl, vm, val);
	}
} tr;

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s >> s;
	ll ans = 0;

	int len = 0;
	for (int i = (int)s.size() - 1; i >= 0; --i) {
		if (s[i] == '0') {
			len = 0;
		} else {
			++len;
			int pos = tr.get_pos(0, 0, s.size(), len);
			if (i <= pos - 1)
			tr.add(0, 0, s.size(), i, pos - 1, 1);
		}
		ans += tr.get(0, 0, s.size(), 0, s.size());
	//	cout << tr.get(0, 0, s.size(), 0, s.size()) << endl;
	}

	cout << ans;
}