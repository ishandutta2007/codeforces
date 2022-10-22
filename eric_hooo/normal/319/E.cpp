#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, int> ppp;

const int INF = 0x3f3f3f3f;

vector <int> all;
int OP[100010], X[100010], Y[100010], fa[100010], L[100010], R[100010];
int n;

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	fa[x] = y, L[y] = min(L[y], L[x]), R[y] = max(R[x], R[y]);
}

struct Segment_tree {
	vector <int> T[1600010];
	void Update(int now, int l, int r, int L, int R, int id) {
		if (l == L && r == R) {
			T[now].push_back(id);
			return ;
		}
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R, id);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R, id);
		else Update(now << 1, l, mid, L, mid, id), Update(now << 1 | 1, mid + 1, r, mid + 1, R, id);
	}
	void Query(int now, int l, int r, int pos, int id) {
		for (int i = 0; i < T[now].size(); i++) {
			int x = T[now][i];
			merge(find(x), find(id));
		}
		if (T[now].size()) T[now].clear(), T[now].push_back(id);
		if (l == r) return ;
		int mid = l + r >> 1;
		if (pos <= mid) Query(now << 1, l, mid, pos, id);
		else Query(now << 1 | 1, mid + 1, r, pos, id);
	}
}seg;

int main () {
	int T; scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d%d%d", &OP[i], &X[i], &Y[i]);
		if (OP[i] == 1) {
			all.push_back(X[i] + 1), all.push_back(Y[i]), all.push_back(X[i]), all.push_back(Y[i] - 1);
		}
	}
	sort(all.begin(), all.end()), all.resize(unique(all.begin(), all.end()) - all.begin());
	n = all.size();
	for (int i = 0; i < T; i++) {
		if (OP[i] == 2) continue;
		X[i] = lower_bound(all.begin(), all.end(), X[i]) - all.begin() + 1;
		Y[i] = lower_bound(all.begin(), all.end(), Y[i]) - all.begin() + 1;
	}
	int tot = 1;
	for (int i = 0; i < T; i++) {
		if (OP[i] == 1) {
			L[tot] = X[i], R[tot] = Y[i], fa[tot] = tot;
			seg.Query(1, 1, n, X[i], tot), seg.Query(1, 1, n, Y[i], tot);
			seg.Update(1, 1, n, X[i] + 1, Y[i] - 1, tot);
			tot++;
		} else {
			int x = find(X[i]), y = find(Y[i]);
			if (x == y) printf("YES\n");
			else {
				if (L[y] < L[x] && R[y] > L[x]) printf("YES\n");
				else if (L[y] < R[x] && R[y] > R[x]) printf("YES\n");
				else printf("NO\n");
			}
		}
	}
	return 0;
}