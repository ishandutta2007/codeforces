#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

pii operator - (const pii &a, const pii &b) {return mp(a.fi - b.fi, a.se - b.se);}

long long operator ^ (const pii &a, const pii &b) {return 1ll * a.fi * b.se - 1ll * a.se * b.fi;}

int Q;
long long M;
set <pii> S;

void Insert(int x, int y) {
	auto it = S.insert(mp(x, y)).fi;
	auto Chk = [&](auto it) -> bool {
		if (it == S.begin() || ++it == S.end()) return 0;
		pii suc = *it, cur = *--it, pre = *--it;
		return (cur - pre ^ suc - pre) <= 0;
	};
	if (Chk(it)) {
		S.erase(it);
		return ;
	}
	auto ChkLef = [&](auto it) -> bool {return it != S.begin() && Chk(--it);};
	auto ChkRig = [&](auto it) -> bool {return ++it != S.end() && Chk(it);};
	while (ChkLef(it)) it--, it = S.erase(it);
	while (ChkRig(it)) it++, it = S.erase(it), it--;
}

string Query(int T, int H) {
	int need = (H + T - 1) / T;
	auto it = S.lower_bound(mp(need, 0));
	if (it == S.end()) return "NO";
	pii q = *it, p = *--it;
	if (1ll * (q.se - p.se) * (H - p.fi * T) + 1ll * p.se * T * (q.fi - p.fi) <= M * (q.fi - p.fi)) return "YES";
	return "NO";
}

int main() {
	S.insert(mp(0, 0));
	scanf("%d%lld", &Q, &M);
	int lst = 0;
	for (int turn = 1; turn <= Q; turn++) {
		int op, x, y; scanf("%d%d%d", &op, &x, &y);
		x = (x + lst) % 1000000 + 1, y = (y + lst) % 1000000 + 1;
		if (op == 1) Insert(x, y);
		else {
			string ans = Query(x, y);
			if (ans == "YES") lst = turn;
			printf("%s\n", ans.c_str());
		}
	}
	return 0;
}