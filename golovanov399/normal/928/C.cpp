#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

struct Proj {
	string name;
	int ver;

	bool operator <(const Proj& ot) const {
		return make_pair(name, ver) < make_pair(ot.name, ot.ver);
	}
};

ostream& operator <<(ostream& ostr, const vector<auto>& v) {
	ostr << "{";
	for (int i = 0; i < (int)v.size(); ++i) {
		if (i) ostr << ", ";
		ostr << v[i];
	}
	ostr << "}";
	return ostr;
}

int main() {
	cin.sync_with_stdio(0);
	int n = nxt();

	map<Proj, int> M;
	vector<Proj> ps(n);
	function<int(const Proj&)> getIdx = [&](const Proj& p) {
		int idx;
		if (!M.count(p)) {
			idx = M.size();
			M[p] = idx;
			ps[idx] = p;
			// cerr << idx << ": " << p.name << ", " << p.ver << "\n";
		} else {
			idx = M[p];
		}
		return idx;
	};

	vector<vector<int>> a(n);
	for (int i = 0; i < n; ++i) {
		// cerr << "start " << i << "\n";
		Proj p;
		cin >> skipws >> p.name >> p.ver;

		int idx = getIdx(p);

		int m = nxt();
		// cerr << "m = " << m << "\n";
		for (int j = 0; j < m; ++j) {
			Proj q;
			cin >> q.name >> q.ver;
			// cerr << "read " << q.name << " " << q.ver << "\n";
			a[idx].push_back(getIdx(q));
		}
	}

	map<pair<int, string>, vector<int>> q;
	q[{0, ps[0].name}] = {0};
	vector<int> dist(n, -1);
	dist[0] = 0;
	set<string> used_names;
	set<Proj> ans;

	while (!q.empty()) {
		auto [pr, ids] = *q.begin();
		auto [d, name] = pr;
		q.erase(q.begin());
		if (used_names.count(name)) {
			continue;
		}
		used_names.insert(name);
		int idx = *min_element(all(ids), [&](int x, int y) {
			return ps[x].ver > ps[y].ver;
		});

		ans.insert(ps[idx]);
		for (int to : a[idx]) {
			if (dist[to] > -1 || used_names.count(ps[to].name)) {
				continue;
			}
			dist[to] = d + 1;
			q[{d + 1, ps[to].name}].push_back(to);
		}
	}

	ans.erase(ps[0]);
	cout << ans.size() << "\n";;
	for (auto p : ans) {
		cout << p.name << " " << p.ver << "\n";
	}

	return 0;
}