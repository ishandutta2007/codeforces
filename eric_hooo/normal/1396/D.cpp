#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, int> ppp;

const int mod = 1000000007;

ppp a[2010];
multiset <int> all[2010];
long long tot;
int L;
set <pii> S;

int get_pre(multiset <int> &s, int x) {
	multiset <int> :: iterator it = s.lower_bound(x);
	return it == s.begin() ? -1 : *(--it);
}

int get_suc(multiset <int> &s, int x) {
	multiset <int> :: iterator it = s.lower_bound(x);
	return it == s.end() ? L : *it;
}

void Clear() {tot = 0, S.clear();}

pii get_pre(set <pii> &s, set <pii> :: iterator it) {
	if (it == s.begin()) return mp(-1, 0);
	return *(--it);
}

pii get_suc(set <pii> &s, set <pii> :: iterator it) {
	++it;
	if (it == s.end()) return mp(-1, 0);
	return *it;
}

long long calc(int l, int r) {
	if (l >= r) return 0;
	return 1ll * (r - l) * (r - l + 1) / 2;
}

void Change(set <pii> :: iterator it, int flag) {
	pii pre = get_pre(S, it), suc = get_suc(S, it);
	tot -= calc(it->fi, -it->se) * flag;
	if (~pre.fi) tot += calc(it->fi, -pre.se) * flag;
	if (~suc.fi) tot += calc(suc.fi, -it->se) * flag;
	if (~pre.fi && ~suc.fi) tot -= calc(suc.fi, -pre.se) * flag;
}

void Add(int l, int r) {
	if (l >= r) return ;
	set <pii> :: iterator it = S.lower_bound(mp(l, -r));
	while (it != S.end() && -it->se <= r) Change(it, 1), it = S.erase(it);
	if (it == S.begin()) {
		S.insert(mp(l, -r));
		it = S.lower_bound(mp(l, -r));
		Change(it, -1);
		return ;
	}
	it--;
	if (-it->se >= r) return ;
	S.insert(mp(l, -r));
	it = S.lower_bound(mp(l, -r));
	Change(it, -1);
}

int main () {
	int n, k; scanf("%d%d%d", &n, &k, &L);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &a[i].fi.fi, &a[i].fi.se, &a[i].se);
	}
	sort(a, a + n);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (i && a[i].fi.fi == a[i - 1].fi.fi) continue;
		int M1 = a[i].fi.fi - (i ? a[i - 1].fi.fi : -1);
		for (int j = i; j < n; j++) {
			int y = a[j].fi.se, k = a[j].se;
			all[k].insert(y);
		}
		Clear();
		for (int j = 1; j <= k; j++) {
			int lst = -1;
			for (auto x : all[j]) {
				Add(lst + 1, x);
				lst = x;
			}
			Add(lst + 1, L);
		}
		for (int j = n - 1; j >= i; j--) {
			int y = a[j].fi.se, c = a[j].se;
			int M2 = (j + 1 == n ? L : a[j + 1].fi.fi) - a[j].fi.fi;
			long long delta = (1ll * L * (L + 1) / 2 - tot) % mod;
			delta = delta * M1 % mod * M2 % mod;
			ans = (ans + delta) % mod;
			all[c].erase(all[c].find(y));
			if (!all[c].count(y)) {
				int pre = get_pre(all[c], y), suc = get_suc(all[c], y);
				Add(pre + 1, suc);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}