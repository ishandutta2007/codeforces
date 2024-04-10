#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

long long GetDist(pii a, pii b) {
	return abs(a.fi - b.fi) + abs(a.se - b.se);
}

int n, a, b, c;
long long t;
pii p[4];
long long val[4], old_val[4];
pii cur, old_cur;
int PRT;

void Calc(int x, int y, int coef) {
	for (int i = 0; i < 4; i++) {
		val[i] += GetDist(p[i], mp(x, y)) * coef;
	}
}

long long GetSum(int x, int y) {
	if (x == y) return 0;
	if (x < y) x++;
	else x--;
	return 1ll * (x + y) * (abs(x - y) + 1) / 2;
}

long long GetNeed(pii cur, pii p) {
	int x = cur.fi - p.fi, y = cur.se - p.se;
	int tx = n - 1 - p.fi, ty = n - 1 - p.se;
	long long ans = 0;
	{
		int bg = abs(x) + abs(y), ed = max(0, x) + max(0, y);
		ans += GetSum(bg, ed);
		x = max(0, x), y = max(0, y);
	}
	{
		int bg = abs(x) + abs(y), ed = tx + ty;
		ans += GetSum(bg, ed);
	}
	return ans;
}

void MoveTo(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int bg = GetDist(p[i], cur), ed = GetDist(p[i], mp(x, y));
		val[i] -= GetSum(bg, ed);
	}
	cur = mp(x, y);
}

bool Ok() {
	PRT = cur == mp(14, 0);
	PRT = 0;
	goto BEG;
	BAD:;
	memcpy(val, old_val, sizeof(val)), cur = old_cur;
	return 0;
	BEG:;
	int x = cur.fi, y = cur.se;
	if (x >= a + c - 1 || y >= b + c - 1) {
		for (int i = 0; i < 4; i++) {
			if (val[i] < GetNeed(mp(x, y), p[i])) return 0;
		}
		return 1;
	}
	if (PRT) cerr << "                           Need:" << GetNeed(mp(x, y), p[3]) << endl;
	if (val[3] < GetNeed(mp(x, y), p[3])) return 0;
	if (val[0] < GetNeed(mp(x, y), p[0])) return 0;
	memcpy(old_val, val, sizeof(old_val)), old_cur = cur;
	MoveTo(max(x, a), max(y, b));
	x = cur.fi, y = cur.se;
	int ls = GetDist(cur, p[1]), rs = GetDist(cur, p[2]);
	if (PRT) cerr << "          QWQ" << endl;
	if (PRT) cerr << "        ls:" << ls << " " << rs << " : " << cur.fi << " " << cur.se << endl;
	if (PRT) cerr << "                            p1:" << p[1].fi << " " << p[1].se << endl;
	if (PRT) cerr << "                            p2:" << p[2].fi << " " << p[2].se << endl;
	val[1] -= GetNeed(p[3], p[1]);
	val[2] -= GetNeed(p[3], p[2]);
	if (val[1] + val[2] < (ls + rs) * GetDist(cur, p[3])) goto BAD;
	if (GetSum(ls, abs(cur.fi - p[1].fi)) + GetSum(abs(cur.fi - p[1].fi), c - 1) > val[1]) goto BAD;
	if (GetSum(rs, abs(cur.se - p[2].se)) + GetSum(abs(cur.se - p[2].se), c - 1) > val[2]) goto BAD;
	memcpy(val, old_val, sizeof(val)), cur = old_cur;
	return 1;
}

string ans;

int main() {
	scanf("%d%lld%d%d%d", &n, &t, &a, &b, &c), a--, b--;
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
		p[i << 1 | j] = mp(a + (i ? c - 1 : 0), b + (j ? c - 1 : 0));
	}
	for (int i = 0; i < 4; i++) {
		val[i] = t;
	}
	// return 0;
	while (cur.fi + 1 < n || cur.se + 1 < n) {
		if (cur.fi + 1 < n) {
			cur.fi++, Calc(cur.fi, cur.se, -1);
			if (Ok()) {
				ans.push_back('R');
				goto END;
			}
			Calc(cur.fi, cur.se, 1), cur.fi--;
		}
		if (cur.se + 1 < n) {
			cur.se++, Calc(cur.fi, cur.se, -1);
			if (Ok()) {
				ans.push_back('U');
				goto END;
			}
			Calc(cur.fi, cur.se, 1), cur.se--;
		}
		printf("Impossible\n");
		return 0;
		END:;
	}
	printf("%s\n", ans.c_str());
	return 0;
}