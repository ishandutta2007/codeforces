#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int A[30][30];
int ban[30][30];
int n, m;
int pw[10];
vector <vector <int> > op, po;

bool IN(int x, int y) {return x >= 1 && x <= n && y >= 1 && y <= m;}

bool Check(int a, int b, int c, int d) {return abs(a - c) + abs(b - d) == 1;}

bool AddOp(int a, int b, int c, int d, int e, int f, int g, int h) {
	if (!IN(a, b) || !IN(c, d) || !IN(e, f) || !IN(g, h)) return 0;
	if (ban[a][b] || ban[c][d] || ban[e][f] || ban[g][h]) return 0;
	assert(Check(a, b, c, d) && Check(c, d, e, f) && Check(e, f, g, h) && Check(g, h, a, b));
	op.push_back({A[a][b], A[c][d], A[e][f], A[g][h]});
	int tmp = A[a][b]; A[a][b] = A[g][h], A[g][h] = A[e][f], A[e][f] = A[c][d], A[c][d] = tmp;
	return 1;
}

void Move(int x, int y, int xx, int yy) {
	assert(Check(x, y, xx, yy));
	if (x == xx) {
		if (AddOp(x, y, xx, yy, xx - 1, yy, x - 1, y)) return ;
		if (AddOp(x, y, xx, yy, xx + 1, yy, x + 1, y)) return ;
		assert(0);
	} else {
		if (AddOp(x, y, xx, yy, xx, yy + 1, x, y + 1)) return ;
		if (AddOp(x, y, xx, yy, xx, yy - 1, x, y - 1)) return ;
		assert(0);
	}
}

void Calc(int x, int y, int i, int j) {
	if (x == i && y == j) return ;
	while (y < j) Move(x, y, x, y + 1), y++;
	while (y > j) Move(x, y, x, y - 1), y--;
	while (x > i) Move(x, y, x - 1, y), x--;
	while (x < i) Move(x, y, x + 1, y), x++;
}

pii GetPos(int x) {
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (A[i][j] == x) return mp(i, j);
}

void Print() {
	cerr << "   A:" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cerr << " " << A[i][j];
		}
		cerr << endl;
	}
}

const int Target = 12345678;

map <int, vector <int> > lst;

int GetMask(int A[][3]) {
	int mask = 0;
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) mask += A[i][j] * pw[i * 3 + j];
	return mask;
}

queue <int> q;

void AddMask(int x, int v, vector <int> path) {
	if (lst.count(v)) return ;
	path.push_back(x);
	lst[v] = path, q.push(v);
}

void GetNxt(int mask) {
	int A[3][3];
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) A[i][j] = mask / pw[i * 3 + j] % 10;
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
		swap(A[i][j], A[i + 1][j]), swap(A[i][j], A[i + 1][j + 1]), swap(A[i][j], A[i][j + 1]);
		AddMask(mask, GetMask(A), {n - i, m - j, n - i - 1, m - j, n - i - 1, m - j - 1, n - i, m - j - 1});
		swap(A[i][j], A[i + 1][j]), swap(A[i][j], A[i + 1][j + 1]), swap(A[i][j], A[i][j + 1]);
		swap(A[i][j], A[i + 1][j]), swap(A[i][j], A[i + 1][j + 1]), swap(A[i][j], A[i][j + 1]);
		AddMask(mask, GetMask(A), {n - i, m - j, n - i, m - j - 1, n - i - 1, m - j - 1, n - i - 1, m - j});
		swap(A[i][j], A[i + 1][j]), swap(A[i][j], A[i + 1][j + 1]), swap(A[i][j], A[i][j + 1]);
	}
}

int main() {
	pw[0] = 1; for (int i = 1; i < 9; i++) pw[i] = pw[i - 1] * 10;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> A[i][j];
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= m - 1; j++) {
			pii tmp = GetPos((i - 1) * m + j);
			Calc(tmp.fi, tmp.se, i, j);
			ban[i][j] = 1;
		}
		pii tmp = GetPos((i - 1) * m + m);
		if (tmp == mp(i, m)) {
			ban[i][m] = 1;
			continue;
		}
		Calc(tmp.fi, tmp.se, i + 2, m);
		ban[i][m - 1] = 0, assert(AddOp(i, m - 1, i, m, i + 1, m, i + 1, m - 1));
		Calc(i + 2, m, i + 1, m);
		AddOp(i, m, i, m - 1, i + 1, m - 1, i + 1, m);
		ban[i][m - 1] = ban[i][m] = 1;
	}
	for (int j = 1; j <= m - 2; j++) {
		pii tmp = GetPos((n - 2) * m + j);
		Calc(tmp.fi, tmp.se, n - 1, j);
		if (A[n][j] == (n - 1) * m + j) {
			ban[n][j] = ban[n - 1][j] = 1;
			continue;
		}
		tmp = GetPos((n - 1) * m + j);
		ban[n][j] = ban[n - 1][j] = 1, Calc(tmp.fi, tmp.se, n, j + 2), ban[n][j] = ban[n - 1][j] = 0;
		ban[n][j] = ban[n - 1][j] = 0;
		assert(AddOp(n - 1, j, n, j, n, j + 1, n - 1, j + 1));
		Calc(n, j + 2, n, j + 1), AddOp(n, j, n - 1, j, n - 1, j + 1, n, j + 1);
		ban[n][j] = ban[n - 1][j] = 1;
	}
	vector <int> all;
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) all.push_back(A[n - i][m - j]);
	sort(all.begin(), all.end());
	int mask = 0;
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
		mask += pw[i * 3 + j] * (lower_bound(all.begin(), all.end(), A[n - i][m - j]) - all.begin());
	}
	AddMask(mask, mask, {});
	while (!lst.count(Target)) {
		int x = q.front(); q.pop();
		GetNxt(x);
	}
	int cur = Target;
	while (cur != mask) po.push_back(lst[cur]), cur = po.back().back(), po.back().pop_back();
	memset(ban, 0, sizeof(ban));
	reverse(po.begin(), po.end());
	for (auto it : po) AddOp(it[0], it[1], it[2], it[3], it[4], it[5], it[6], it[7]);
//	Print();
	printf("%d\n", (int)op.size());
	for (auto it : op) {
		printf("%d", (int)it.size()); for (auto x : it) printf(" %d", x); printf("\n");
	}
	return 0;
}