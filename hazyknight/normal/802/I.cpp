#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAXN = 100005;

struct Edge
{
	int to, next;
	Edge() {}
}e[MAXN << 1];
int head[MAXN << 1], te = 0;

inline void insertE(int u, int v)
{
	e[++te].to = v;
	e[te].next = head[u];
	head[u] = te;
}

struct Node
{
	int l, p, trans[26];
	Node() {}
	Node(int a, int b) : l(a), p(b) { memset(trans, 0, sizeof(trans)); }
}node[MAXN << 1];
int r[MAXN << 1], root = 1, last = 1, cnt = 1;

long long res = 0;

inline void insert(int x, int len)
{
	int p = last, np = ++cnt;
	node[np] = Node(len, 0), r[np] = 1;
	for ( ; p && node[p].trans[x] == 0; p = node[p].p)
		node[p].trans[x] = np;
	if (!p)
		node[np].p = root;
	else
	{
		int q = node[p].trans[x];
		if (node[q].l == node[p].l + 1)
			node[np].p = q;
		else
		{
			int nq = ++cnt;
			node[nq] = Node(node[p].l + 1, node[q].p);
			for (int i = 0; i < 26; i++)
				node[nq].trans[i] = node[q].trans[i];
			node[q].p = nq;
			node[np].p = nq;
			for ( ; p && node[p].trans[x] == q; p = node[p].p)
				node[p].trans[x] = nq;
		}
	}
	last = np;
}

void dfs(int u)
{
	for (int j = head[u]; j != 0; j = e[j].next)
	{
		int v = e[j].to;
		dfs(v);
		r[u] += r[v];
	}
}

void init(string &now)
{
	memset(r, 0, sizeof(r));
	root = 1, last = 1, cnt = 1;
	node[root] = Node(0, 0);
	for (int i = 0; i < now.size(); i++)
		insert(now[i] - 'a', i + 1);
	memset(head, 0, sizeof(head));
	te = 0;
	for (int i = 2; i <= cnt; i++)
		insertE(node[i].p, i);
	dfs(1);
}

int n;

string s;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		init(s);
		res = 0;
		for (int i = 2; i <= cnt; i++)
		{
			int len = node[i].l - node[node[i].p].l;
			res += (long long)(r[i]) * r[i] * len;
		}
		cout << res << endl;
	}
	return 0;
}