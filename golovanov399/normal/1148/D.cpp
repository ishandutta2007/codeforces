#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Seg {
	int l, r, id;
};

vector<int> solve(vector<Seg> segs) {
	if (segs.empty()) {
		return {};
	}

	sort(all(segs), [](const Seg& p, const Seg& q) {
		return p.l < q.l;
	});

	pair<int, int> opt = {0, 0};
	int len = 1;
	int l = 0;
	int r = segs[0].r;
	for (int i = 1; i < (int)segs.size(); ++i) {
		if (segs[i].l > r) {
			opt = max(opt, {len, l});
			l = i;
			r = segs[i].r;
			len = 1;
		} else {
			r = max(r, segs[i].r);
			len += 1;
		}
	}
	opt = max(opt, {len, l});

	vector<int> ans;
	vector<int> to_add;
	r = segs[l].r;
	ans.push_back(segs[l].id);
	for (int i = l + 1; i < l + len; ++i) {
		if (segs[i].r < r) {
			to_add.push_back(segs[i].id);
		} else {
			ans.push_back(segs[i].id);
			r = segs[i].r;
		}
	}
	reverse(all(to_add));
	ans.insert(ans.end(), all(to_add));
	return ans;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<Seg> segs[2];
	for (int i = 0; i < n; ++i) {
		int l = nxt() - 1, r = nxt() - 1;
		segs[l > r].push_back({min(l, r), max(l, r), i});
	}

	vector<int> ans[2];
	for (int i = 0; i < 2; ++i) {
		ans[i] = solve(segs[i]);
	}
	reverse(all(ans[1]));
	auto res = (ans[0].size() > ans[1].size()) ? ans[0] : ans[1];
	printf("%d\n", (int)res.size());
	for (int x : res) {
		printf("%d ", x + 1);
	}
	printf("\n");

	return 0;
}