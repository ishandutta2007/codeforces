#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
    inline int pidorand() {
        return ((rand() & 32767) << 15) | (rand() & 32767);
    }
    #define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void panic() {
	puts("NO");
	exit(0);
}

int main(){
	int n = nxt(), m = nxt();
	vector<vector<int>> a(n);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 0; i < n; ++i) {
		a[i].push_back(i);
		sort(all(a[i]));
	}

	vector<pair<vector<int>, int>> p(n);
	for (int i = 0; i < n; ++i) {
		p[i] = {a[i], i};
	}

	sort(all(p));
	vector<int> label(n);
	vector<int> hmm;
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			label[p[i].second] = 0;
		} else {
			label[p[i].second] = label[p[i - 1].second] + (p[i].first == p[i - 1].first ? 0 : 1);
		}
		if (hmm.size() <= (int)label[p[i].second]) {
			hmm.push_back(p[i].second);
		} else {
			hmm[label[p[i].second]] = p[i].second;
		}
	}

	int start = -1;
	for (int v = 0; v < n; ++v) {
		set<int> labels;
		for (int w : a[v]) {
			labels.insert(label[w]);
			if (labels.size() > 3) {
				panic();
			}
		}
		if (labels.size() <= 2) {
			start = label[v];
			break;
		}
	}
	if (start == -1) {
		panic();
	}

	vector<int> num(hmm.size(), -1);
	int lst = -1;
	int l = start;
	int cur = 0;
	while (true) {
		num[l] = ++cur;
		int i = 0;
		int v = hmm[l];
		while (i < (int)a[v].size()) {
			if (label[a[v][i]] == l || label[a[v][i]] == lst) {
				++i;
			} else {
				break;
			}
		}
		if (i == (int)a[v].size()) {
			break;
		}
		lst = l;
		l = label[a[v][i]];
	}

	for (int i = 0; i < (int)hmm.size(); ++i) {
		if (num[i] == -1) {
			panic();
		}
		int v = hmm[i];
		for (int w : a[v]) {
			if (num[label[w]] < num[i] - 1 || num[label[w]] > num[i] + 1) {
				panic();
			}
		}
	}

	puts("YES");
	for (int i = 0; i < n; ++i) {
		printf("%d ", num[label[i]]);
	}
	printf("\n");

	return 0;
}