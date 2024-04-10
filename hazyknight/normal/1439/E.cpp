#include <bits/stdc++.h>

using namespace std;

const int MAXN = 400005;

struct Node
{
	int x,y;
	
	Node(int X = 0,int Y = 0)
	{
		x = X;
		y = Y;
	}
	
	Node top()
	{
		if (!x)
			return Node(-1,-1);
		if (!y)
			return Node(0,0);
		int lx = x & -x,ly = y & -y;
		return lx > ly ? Node(x,y ^ (y & (lx - 1))) : Node(x ^ (x & (ly - 1)),y);
	}
	
	bool operator == (const Node &p)const
	{
		return x == p.x && y == p.y;
	}
	
	bool operator < (const Node &p)const
	{
		return x == p.x ? y < p.y : x < p.x;
	}
	
	int len()
	{
		return x + y;
	}
	
	void print()
	{
		cout << '(' << x << ',' << y << ')' << endl;
	}
}p[MAXN],t[MAXN],a[MAXN];

int n,id,top,m,tot,ans;
int w[MAXN];
int S[MAXN];
int l[MAXN << 1];
int r[MAXN << 1];
int fa[MAXN];
int sum[MAXN << 2];
int val[MAXN << 2];

bool vis[MAXN];

vector<int> e[MAXN];
map<Node,int> match;
map<int,int> mt;

Node getlca(Node a,Node b)
{
	while (1)
	{
		Node ta = a.top(),tb = b.top();
		if (ta == tb)
			return a.len() < b.len() ? a : b;
		if (ta.len() < tb.len())
			b = tb;
		else
			a = ta;
	}
}

bool cmp(const Node &a,const Node &b)
{
	if (a == b)
		return 0;
	Node lca = getlca(a,b),tmp = lca;
	if (a == lca || b == lca)
		return a == lca;
	tmp.x++;
	return getlca(a,tmp) == tmp;
}

int dfs(int u)
{
	int res = w[u];
	for (int i = 0;i < e[u].size();i++)
	{
		int ret = dfs(e[u][i]);
		if (ret > 0)
		{
			m++;
			l[m] = t[u].len() + 1;
			r[m] = t[e[u][i]].len();
		}
		else if (vis[e[u][i]])
		{
			m++;
			l[m] = r[m] = t[e[u][i]].len();
		}
		res += ret;
	}
	return res;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d%d%d%d",&p[2 * i - 1].x,&p[2 * i - 1].y,&p[2 * i].x,&p[2 * i].y);
	for (int i = 1;i <= 2 * n;i++)
		a[i] = p[i];
	sort(a + 1,a + 2 * n + 1,cmp);
	int N = 2 * n;
	for (int i = 1;i < 2 * n;i++)
		a[++N] = getlca(a[i],a[i + 1]);
	sort(a + 1,a + N + 1,cmp);
	t[match[Node(0,0)] = ++id] = Node(0,0);
	S[++top] = id;
	for (int i = 1;i <= N;i++)
	{
		while (top >= 1 && !(getlca(a[i],t[S[top]]) == t[S[top]]))
		{
			fa[S[top]] = S[top - 1];
			top--;
		}
		if (a[i] == t[S[top]])
			continue;
		t[match[a[i]] = ++id] = a[i];
		S[++top] = id;
	}
	while (top > 1)
	{
		fa[S[top]] = S[top - 1];
		top--;
	}
	for (int i = 1;i <= n;i++)
	{
		Node L = getlca(p[2 * i - 1],p[2 * i]);
		int u = match[p[2 * i - 1]],v = match[p[2 * i]],lca = match[L];
		w[u]++;
		w[v]++;
		w[lca] -= 2;
		vis[lca] = 1;
	}
	for (int i = 2;i <= id;i++)
		e[fa[i]].push_back(i);
	dfs(1);
	if (vis[1])
	{
		m++;
		l[m] = r[m] = 0;
	}
	for (int i = 1;i <= m;i++)
	{
		r[i]++;
		val[++tot] = l[i];
		val[++tot] = r[i];
	}
	sort(val + 1,val + tot + 1);
	tot = unique(val + 1,val + tot + 1) - val - 1;
	for (int i = 1;i <= tot;i++)
		mt[val[i]] = i;
	for (int i = 1;i <= m;i++)
	{
		l[i] = mt[l[i]];
		r[i] = mt[r[i]];
		sum[l[i]] ^= 1;
		sum[r[i]] ^= 1;
	}
	int S = 0,pre = -1;
	for (int i = 1;i <= tot;i++)
	{
		S ^= sum[i];
		if (~pre && S != pre)
			ans++;
		pre = S;
	}
	printf("%d\n",ans);
	return 0;
}