#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
/*
ifstream qin("input.txt");
ofstream cout("output.txt");
*/
const int arl = 10;

int getInt() { int n; scanf("%d", &n); return n; }

int n = getInt(), m = getInt(), q = getInt(), l;
vector< vector<int> > g(n);
vector< vector<int> > pp(n);
vector<int> tin(n), tout(n);
int timer;
vector< vector<int> > up(n);
vector< vector< vector<int> > > lst(n);

vector<int> merge(const vector<int> &a, const vector<int> &b)
{
    int ai = 0, bi = 0, as = a.size(), bs = b.size();
    vector<int> res;
    while (ai < as || bi < bs)
    {
        bool pa;
        if (ai == as) pa = false;
            else if (bi == bs) pa = true;
                else pa = min(a[ai], b[bi]) == a[ai];
        if (pa) res.push_back(a[ai]), ai++;
            else res.push_back(b[bi]), bi++;
        if (res.size() == arl) return res;
    }
    return res;
}

void dfs(int v, int p = 0)
{
	tin[v] = ++timer;
	up[v][0] = p;
	lst[v][0] = pp[v];
	for (int i = 1; i <= l; i++)
    {
        up[v][i] = up[up[v][i - 1]][i - 1];
        lst[v][i] = merge(lst[v][i - 1], lst[up[v][i - 1]][i - 1]);
	}
	for (int i = 0; i < g[v].size(); i++)
    {
		int to = g[v][i];
		if (to != p) dfs(to, v);
	}
	tout[v] = ++timer;
}

bool upper(int a, int b) { return tin[a] <= tin[b] && tout[a] >= tout[b]; }

int lca(int a, int b)
{
	if (upper(a, b))  return a;
	if (upper(b, a))  return b;
	for (int i = l; i >= 0; i--)
		if (!upper(up[a][i], b)) a = up[a][i];
	return up[a][0];
}

vector<int> pathfull(int f, int t, int mv)
{
    if (f == t) return vector<int>();
    vector<int> res;
    for (int i = mv; i >= 0; i--)
		if (!upper(up[f][i], t))
            return merge(res, merge(lst[f][i], pathfull(up[f][i], t, i)));
    return merge(res, pp[f]);
}

vector<int> query(int x, int y, int a)
{
    int q = lca(x, y);
    vector<int> vv = merge(pp[q], merge(pathfull(x, q, l), pathfull(y, q, l)));
    if (vv.size() > a) vv.resize(a);
    return vv;
}

int main()
{
    for (int i = 1; i < n; i++)
    {
        int a, b; scanf("%d%d", &a, &b);
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < m; i++)
    {
        int a; scanf("%d", &a); a--;
        pp[a].push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        sort(pp[i].begin(), pp[i].end());
        if (pp[i].size() > arl) pp[i].resize(arl);
    }
	l = 1;
	while ((1 << l) <= n) l++;
	for (int i = 0; i < n; i++) up[i].resize(l + 1);
	for (int i = 0; i < n; i++) lst[i].resize(l + 1);
	dfs(0);
    for (int i = 0; i < q; i++)
    {
        int x, y, a;
        scanf("%d%d%d", &x, &y, &a);
        x--, y--;
        vector<int> q = query(x, y, a);
        printf("%d", q.size());
        for (int i = 0; i < q.size(); i++) printf(" %d", q[i] + 1);
        printf("\n");
    }
}