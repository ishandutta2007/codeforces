#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <iomanip>
typedef long long ll;
using namespace std;

const int maxa = 1 << 30, maxn = 2e5 + 5, maxnd = maxn * 2 * 18, mod = 998244353;
struct node
{
	int l, r, sum, ls, lm;
} tree[maxnd];
void upd(int& a, int b) { a = (a + b) % mod; }
int add(int a, int b) { return (a + b) % mod; }
int mul(int a, int b) { return (a * 1ll * b) % ((ll)mod); }
int nd = 0;
void mult(int u, int x)
{
	tree[u].sum = mul(tree[u].sum, x);
	tree[u].ls = mul(tree[u].ls, x);
	tree[u].lm = mul(tree[u].lm, x);
}
void addu(int u, int x, int len)
{
	upd(tree[u].sum, mul(x, len));
	upd(tree[u].ls, x);
}
void unlazy(int u, int len)
{
	mult(tree[u].l, tree[u].lm);
	addu(tree[u].l, tree[u].ls, len >> 1);
	mult(tree[u].r, tree[u].lm);
	addu(tree[u].r, tree[u].ls, len >> 1);
	tree[u].ls = 0, tree[u].lm = 1;
}
void nw()
{
	tree[nd].ls = tree[nd].sum = 0, tree[nd].lm = 1;
	tree[nd].l = tree[nd].r = -1;
}
void update(int l, int r, bool m, int x, int myl = 0, int myr = maxa - 1, int u = 0)
{
	if (myr < l || r < myl) return;
	if (l <= myl && myr <= r)
	{
		if (m) 
			mult(u, x);
		else 
			addu(u, x, myr - myl + 1);
		return;
	}
	if (tree[u].l == -1) tree[u].l = ++nd, nw();
	if (tree[u].r == -1) tree[u].r = ++nd, nw();
	unlazy(u, myr - myl + 1);
	update(l, r, m, x, myl, (myl + myr) >> 1, tree[u].l);
	update(l, r, m, x, ((myl + myr) >> 1) + 1, myr, tree[u].r);
	tree[u].sum = add(tree[tree[u].l].sum, tree[tree[u].r].sum);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	nw();
	update(maxa - 1, maxa - 1, false, 1);
	for (int i = 0, a; i < n; i++)
	{
		cin >> a;
		a--;
		int all = tree[0].sum;
		update(0, maxa - 1, true, mod - 1);
		update(a + 1, maxa - 1, true, 0);
		update(0, a, false, all);
	}
	cout << tree[0].sum << "\n";
	return 0;
}