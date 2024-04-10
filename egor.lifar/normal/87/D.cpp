#include <iostream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <cassert>
#include <bitset>
#include <string.h>


using namespace std;


const int MaxN = 200005;
int n, m;
pair<pair<int, int>, pair<int, int>> e[MaxN];
int father[MaxN],cnt[MaxN];
long long resultc;
vector<int> result;
map<int, int> M;
vector<pair<int, int>> g[MaxN];
int size[MaxN], sum[MaxN];
bool used[MaxN];


int findSet(int p) {
	return (father[p] < 0) ? p: (father[p] = findSet(father[p]));
}


int getSetID(int p) {
	p = findSet(p);
	if (M.find(p) != M.end()) {
		return M[p];
	}
	int id = (int)M.size();
	size[id] = cnt[p];
	return M[p] = id;
}


void setUnion(int a, int b) {
	a = findSet(a);
	b = findSet(b);
	if (a == b) {
		return;
	}
	if (cnt[a] > cnt[b]) {
		swap(a, b);
	}
	father[a] = b;
	cnt[b] += cnt[a];
}


void dfs(int p) {
	if (used[p]) {
		return;
	}
	used[p] = true;
	sum[p] = size[p];
	for (int i = 0; i < (int)g[p].size(); i++) {
		int other = g[p][i].first;
		if (!used[other])  {
			dfs(other);
			sum[p] += sum[other];
		}
	}
}


void dfs2(int p, int prev, int all) {
	for (int i = 0; i < (int)g[p].size(); i++) {
		int other = g[p][i].first;
		if (other == prev) {
			continue;
		}
		long long c = (long long)sum[other] * (all - sum[other]);
		if (c > resultc) {
			resultc = c;
			result.clear();
		}
		if (c == resultc) {
			result.push_back(g[p][i].second);
		}
		dfs2(other, p, all);
	}
}


int main() {
	scanf("%d",&n);
	m = n - 1;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		e[i] = make_pair(make_pair(c, i + 1), make_pair(a - 1, b - 1));
	}
	sort(e, e + m);
	resultc = -1;
	for (int i = 0; i < n; i++) {
		father[i] = -1;
		cnt[i] = 1;
	}
	for (int i = 0; i < m; i++)  {
		if (i == 0 || e[i].first.first != e[i - 1].first.first) {
			M.clear();
			int j = i;
			for (; j < m && e[j].first.first == e[i].first.first; j++);
			for (int k = i; k < j; k++) {
				getSetID(e[k].second.first);
				getSetID(e[k].second.second);
			}
			for (int k = 0; k < (int)M.size(); k++) {
				g[k].clear();
			}
			for (int k = i; k < j; k++) {
				int v1 = getSetID(e[k].second.first);
				int v2 = getSetID(e[k].second.second);
				g[v1].push_back(make_pair(v2, e[k].first.second));
				g[v2].push_back(make_pair(v1, e[k].first.second));
			}
			for (int k = 0; k < (int)M.size(); k++) {
				used[k] = false;
			}
			for (int k = 0; k < (int)M.size(); k++) {
				if (!used[k]) {
					dfs(k);
					dfs2(k, -1, sum[k]);
				}
			}
			for (int k = i; k < j; k++) {
				setUnion(e[k].second.first, e[k].second.second);
			}
		}
	}
	cout << resultc * 2 << " " << (int)result.size() << endl;
	sort(result.begin(), result.end());
	for (int i = 0; i < (int)result.size(); i++) {
		printf("%d ", result[i]);
	}
	printf("\n");
	return 0;
}