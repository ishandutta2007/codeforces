#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

char s[200010], t[200010];
int n;
int fa[200010], pos[200010], ff[200010], LL[200010];
int T[200010];
set <pii> rng[26];
vector <pii> op;
int cnt[26];
int m;

void modify(int x, int v) {
	while (x <= n) T[x] += v, x += x & -x;
}

int query(int x) {
	int res = 0;
	while (x) res += T[x], x -= x & -x;
	return res;
}

int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}

int ffff(int x) {return ff[x] == x ? x : ff[x] = ffff(ff[x]);}

void Erase(int x) {
	int X = t[x] - 'a';
	set <pii> :: iterator it = rng[X].lower_bound(mp(x, -1));
	if (it == rng[X].end() || it->fi > x) it--;
	if (it->fi == it->se) {
		rng[X].erase(it);
		int pre = LL[x] - 1, suc = ffff(x + 1);
		if (pre != -1 && suc != m + 1 && t[pre] == t[suc]) {
			int Y = t[pre] - 'a';
			it = rng[Y].lower_bound(mp(suc, -1));
			int R = it->se;
			it--;
			int L = it->fi;
			it = rng[Y].erase(it), rng[Y].erase(it);
			rng[Y].insert(mp(L, R));
		}
		ff[x] = x + 1, LL[ffff(x)] = LL[x];
		return ;
	}
	if (it->fi == x) {
		int L = ffff(x + 1), R = it->se;
		rng[X].erase(it), rng[X].insert(mp(L, R));
		ff[x] = x + 1, LL[ffff(x)] = LL[x];
		return ;
	}
	int L = it->fi, R = LL[x] - 1;
	rng[X].erase(it), rng[X].insert(mp(L, R));
	ff[x] = x + 1, LL[ffff(x)] = LL[x];
}

void Erase(int x, int y) {
	if (x == y) {
		op.push_back(mp(query(pos[x]), query(pos[x])));
		modify(pos[x], -1);
		return ;
	}
	int X = t[x] - 'a', Y = t[y] - 'a'; 
	cnt[X]--, cnt[Y]--;
	int l = pos[x] + 1, r = pos[y], L = query(l), R = query(r);
	op.push_back(mp(L, R));
	while (l <= r) {
		modify(l, -1);
		fa[l] = l + 1, l = find(l);
	}
	Erase(x), Erase(y);
}

int main() {
	int Case; scanf("%d", &Case);
	while (Case--) {
		scanf("%s", s + 1), n = strlen(s + 1);
		for (int i = 1; i <= n; i++) {
			T[i] = i & -i;
		}
		for (int i = 1; i <= n + 1; i++) {
			fa[i] = i;
		}
		m = 0;
		for (int i = 2; i <= n; i++) {
			if (s[i - 1] == s[i]) t[++m] = s[i], pos[m] = i - 1;
		}
		for (int i = 1; i <= m + 1; i++) {
			ff[i] = i, LL[i] = i;
		}
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < 26; i++) {
			rng[i].clear();
		}
		for (int i = 1; i <= m; i++) {
			int j = i;
			while (j <= m && t[i] == t[j]) j++;
			rng[t[i] - 'a'].insert(mp(i, j - 1));
			cnt[t[i] - 'a'] += j - i;
			i = j - 1;
		}
		t[m + 1] = '\0';
		op.clear();
		while (1) {
			int tot = 0, p = 0;
			for (int i = 0; i < 26; i++) {
				if (cnt[i]) tot++;
				if (cnt[i] > cnt[p]) p = i;
			}
			if (tot == 0) break;
			if (tot == 1) {
				for (auto it : rng[p]) {
					int l = it.fi, r = it.se;
					while (l <= r) {
						Erase(l, l);
						l = ffff(l + 1);
					}
				}
				break;
			}
			int l = rng[p].begin()->fi, r = rng[p].begin()->se;
			if (LL[l] != 1) Erase(LL[l] - 1, l);
			else Erase(r, ffff(r + 1));
		}
		if (query(n)) op.push_back(mp(1, query(n)));
		printf("%d\n", (int)op.size());
		for (int i = 0; i < op.size(); i++) {
			int l = op[i].fi, r = op[i].se;
			printf("%d %d\n", l, r);
		}
	}
	return 0;
}