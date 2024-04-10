#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
    int n;
    vector <int> t;

    void modify(int x, int val) {
        for (t[x += n] = val; x > 1; x >>= 1) {
            t[x >> 1] = max(t[x], t[x ^ 1]);
        }
    }
 
    int get(int l, int r) {
        ++r;
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, t[l++]);
            if (r & 1) res = max(res, t[--r]);
        }
        return res;
    }
 
    SegmentTree(int n) {
    	t.resize(2 * n);
    }
};

void solve() {
	int n;
	cin >> n;
	vector <int> nxt(n);
	for (int i = 0; i < n; ++i) {
		cin >> nxt[i];
		if (nxt[i] != -1) --nxt[i];
	}
	vector <int> cnt(n);
	for (int i = 0; i < n; ++i) {
		if (0 <= nxt[i] && nxt[i] < n) ++cnt[nxt[i]];
	}
	set <pair <int, int>> kek;
	for (int i = 0; i < n; ++i) kek.insert({cnt[i], -i});
	vector <int> p(n);
	for (int i = 0; i < n; ++i) {
		auto pr = *kek.begin();
		kek.erase(kek.begin());
		int id = -pr.second;
		p[id] = i;
		if (0 <= nxt[id] && nxt[id] < n) {
			int x = nxt[id];
			kek.erase({cnt[x], -x});
			--cnt[x];
			kek.insert({cnt[x], -x});
		}
	}
	vector <int> st;
	vector <int> nx(n);
	for (int i = n - 1; i >= 0; --i) {
		while (!st.empty() && p[i] > p[st.back()]) st.pop_back();
		if (st.empty()) nx[i] = n;
		else nx[i] = st.back(); 
		st.push_back(i);
	}
	bool fl = true;
	for (int i = 0; i < n; ++i) {
		if (nxt[i] == -1) continue;
		fl &= nxt[i] == nx[i];
	}

	if (!fl) cout << "-1\n";
	else {
		for (int i = 0; i < n; ++i) {
			cout << p[i] + 1 << ' ';
		}
		cout << '\n';
	}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) solve();
}