#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <int, pii> pip;

pii operator + (const pii &a, const pii &b) {return mp(a.fi + b.fi, a.se + b.se);}

template <typename T>
void chmin(T &x, T y) {
	x = min(x, y);
}

template <typename T>
void chmax(T &x, T y) {
	x = max(x, y);
}

int n;
int a[200010];
unordered_map <int, int> ID;
unordered_map <int, unordered_set <int> > G;
int one[31];
pip ans = mp(-1, mp(0, 0));

int GetFa(int x) {
	return *lower_bound(one, one + 31, x) - x;
}

pii dfs(int x) {
	pii tmp = ID.count(x) ? mp(0, ID[x]) : mp(-0x3f3f3f3f, -1);
	for (auto v : G[x]) {
		pii qwq = dfs(v); qwq.fi++;
		chmax(ans, mp(tmp.fi + qwq.fi, mp(tmp.se, qwq.se)));
		chmax(tmp, qwq);
	}
	return tmp;
}

int main() {
	for (int i = 0; i < 31; i++) {
		one[i] = 1 << i;
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		int x = a[i];
		ID[x] = i;
		while (x) {
			int fa = GetFa(x);
			G[fa].insert(x);
			x = fa;
		}
	}
	dfs(0);
	printf("%d %d %d\n", ans.se.fi, ans.se.se, ans.fi);
	return 0;
}