#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
#define MAXN 100013
#define MAX 200003
#define MAXLG 20
#define MAXSEG (4 * 2 * MAXN * MAXLG)

int N, M;
struct node {
	node *l, *r;
	LL x;
} vals[MAXSEG]; int t = 0;

node *ta[MAXN], *tb[MAXN];

node* build_tree(int lo=0, int hi=MAX) {
	node* cur = &vals[t++];
	if (lo != hi) {
		int mid = (lo + hi) / 2;
		cur->l = build_tree(lo, mid);
		cur->r = build_tree(mid + 1, hi);
	}
	return cur;
}

node* update(node* n, int i, int x, int lo=0, int hi=MAX) {
	if (hi < i || lo > i) return n;
	node* v = &vals[t++];
	if (lo == hi) { v->x = n->x + x; return v; }
	int mid = (lo + hi) / 2;
	v->l = update(n->l, i, x, lo, mid);
	v->r = update(n->r, i, x, mid + 1, hi);
	v->x = v->l->x + v->r->x;
	return v;
}

LL query(node* n, int s, int e, int lo=0, int hi=MAX) {
	if (hi < s || lo > e) return 0;
	if (lo >= s && hi <= e) return n->x;
	int mid = (lo + hi) / 2;
	return query(n->l, s, e, lo, mid) + 
			query(n->r, s, e, mid + 1, hi);
}

LL go(int r, int x) {
	LL ans = 0;
	ans += x * query(ta[r], 0, x);
	// error(ans);
	ans += query(tb[r], 0, x);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	ta[0] = build_tree();
	tb[0] = build_tree();
	for (int i = 0; i < N; i++) {
		LL x1, x2, y1, y2, a, b;
		cin >> x1 >> x2 >> y1 >> a >> b >> y2;
		ta[i + 1] = update(update(ta[i], x1 + 1, a), x2 + 1, -a);
		tb[i + 1] = update(update(update(update(update(tb[i], x1 + 1, b), x2 + 1, -b), 0, y1), x1 + 1, -y1), x2 + 1, y2);
	}

	cin >> M;
	LL last = 0;
	for (int i = 0; i < M; i++) {
		int l, r, x;
		cin >> l >> r >> x;
		x = (x + last) % 1000000000;
		x = min(x, MAX);
		LL ans = go(r, x) - go(l - 1, x);
		cout << ans << '\n';
		last = ans;
	}

	cout.flush();
	return 0;
}