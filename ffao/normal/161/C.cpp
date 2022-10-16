#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> pii;

template <typename T> void sortv(std::vector<T> &v) {
	sort(v.begin(), v.end());
}


int disaresta(vector<pii> &inter1, vector<pii>& inter2) {
	sortv(inter1);
	sortv(inter2);

	int c1 = 0, c2 = 0;
	int mc1 = 0, mc2 = 0;
	int ret = 0;
	while (c1 < (int)inter1.size() || c2 < (int)inter2.size()) {
		if (c2 == (int)inter2.size() || (c1 < (int)inter1.size() && inter1[c1].first < inter2[c2].first)) {
			mc1 = max(mc1, inter1[c1].second);
			ret = max(ret, min(mc1,mc2) - inter1[c1].first + 1);
			c1++;
		}
		else {
			mc2 = max(mc2, inter2[c2].second);
			ret = max(ret, min(mc1,mc2) - inter2[c2].first + 1);
			c2++;
		}
	}

	return ret;
}

void split(vector<pii>& inter, int split_pos) {
	vector<pii> nw;
	for (pii p : inter) {
		if (split_pos <= p.second) {
			if (p.first < split_pos) nw.emplace_back(p.first, split_pos-1);
			if (p.second > split_pos) nw.emplace_back(max(1, p.first - split_pos), p.second - split_pos);
		}
		else {
			nw.push_back(p);
		}
	}

	inter.clear();
	sortv(nw);
	for (int i = 0; i < (int)nw.size(); i++) {
		while (!inter.empty() && inter.back().first == nw[i].first ) inter.pop_back();
		if (inter.empty() || inter.back().second < nw[i].second) inter.push_back(nw[i]);
	}
}

void solve() {
	int l1,r1,l2,r2;
	scanf("%d %d %d %d", &l1, &r1, &l2, &r2);

	vector< pii > inter1, inter2;
	inter1.emplace_back(l1,r1);
	inter2.emplace_back(l2,r2);

	int ans = 0;
	for (int let = 30; let >= 1; let--) {
		ans = max(ans, disaresta(inter1, inter2));
		int pos = (1<<(let-1));
		split(inter1,pos);
		split(inter2,pos);
	}

	printf("%d\n", ans);	
}


int main() {
    solve();
}