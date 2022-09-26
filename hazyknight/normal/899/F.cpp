#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>

using namespace std;

struct Node
{
	int ch[2],fa;
	int val;
	int size;
	int cnt[62];
	bool ok;
	bool mark[62];
	Node(){}
	Node(int v)
	{
		ch[0] = ch[1] = fa = 0;
		val = v;
		ok = size = 1;
		memset(mark,0,sizeof(mark));
		memset(cnt,0,sizeof(cnt));
		cnt[val] = 1;
	}
}node[200005];

int ctod(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c - 'A';
	if (c >= 'a' && c <= 'z')
		return c - 'a' + 26;
	return c - '0' + 52;
}

char dtoc(int c)
{
	if (c >= 0 && c < 26)
		return char(c + 'A');
	if (c >= 26 && c < 52)
		return char(c - 26 + 'a');
	return char(c - 52 + '0');
}

int n,m,id,root;
int L,R;

char x;

stack<int> S;

void Update(int u)
{
	node[u].size = node[u].ok;
	if (node[u].ch[0])
		node[u].size += node[node[u].ch[0]].size;
	if (node[u].ch[1])
		node[u].size += node[node[u].ch[1]].size;
	for (int i = 0;i < 62;i++)
	{
		node[u].cnt[i] = 0;
		if (node[u].ch[0])
			node[u].cnt[i] += node[node[u].ch[0]].cnt[i];
		if (node[u].ch[1])
			node[u].cnt[i] += node[node[u].ch[1]].cnt[i];
	}
	if (node[u].ok)
		node[u].cnt[node[u].val]++;
}

void Link(int fa,int ch,bool dir)
{
	node[fa].ch[dir] = ch;
	if (ch)
		node[ch].fa = fa;
	Update(fa);
}

bool is_root(int u)
{
	return !node[u].fa || (node[node[u].fa].ch[0] != u && node[node[u].fa].ch[1] != u);
}

void Rotate(int u,bool dir)
{
	int ch = node[u].ch[dir],fa = node[u].fa;
	bool ok = is_root(u);
	Link(u,node[ch].ch[!dir],dir);
	Link(ch,u,!dir);
	node[ch].fa = fa;
	if (!ok)
		node[fa].ch[node[fa].ch[1] == u] = ch;
}

void Mark(int u,int idx)
{
	if (!u)
		return;
	node[u].mark[idx] = true;
	if (node[u].val == idx)
		node[u].ok = false;
	node[u].size -= node[u].cnt[idx];
	node[u].cnt[idx] = 0;
}

void Push_down(int u)
{
	for (int i = 0;i < 62;i++)
		if (node[u].mark[i])
		{
			Mark(node[u].ch[0],i),Mark(node[u].ch[1],i);
			node[u].mark[i] = false;
		}
}

int Splay(int u)
{
	S.push(u);
	for (int i = u;!is_root(i);i = node[i].fa)
		S.push(node[i].fa);
	while (!S.empty())
	{
		Push_down(S.top());
		S.pop();
	}
	while (!is_root(u))
	{
		int fa = node[u].fa;
		bool dir1 = (node[fa].ch[1] == u);
		if (is_root(fa))
		{
			Rotate(fa,dir1);
			break;
		}
		int ffa = node[fa].fa;
		bool dir2 = (node[ffa].ch[1] == fa);
		if (dir1 ^ dir2)
		{
			Rotate(fa,dir1);
			Rotate(ffa,dir2);
		}
		else
		{
			Rotate(ffa,dir2);
			Rotate(fa,dir1);
		}
	}
	return u;
}

int Insert(int u,int v)
{
	if (!u)
	{
		node[u = ++id] = Node(v);
		return u;
	}
	Link(u,Insert(node[u].ch[1],v),1);
	return u;
}

int get_size(int u)
{
	return u ? node[u].size : 0;
}

int findKth(int u,int x)
{
	Push_down(u);
	if (x <= get_size(node[u].ch[0]))
		return findKth(node[u].ch[0],x);
	x -= get_size(node[u].ch[0]);
	if (x == node[u].ok)
		return u;
	x -= node[u].ok;
	return findKth(node[u].ch[1],x);
}

void print(int u)
{
	if (!u)
		return;
	Push_down(u);
	print(node[u].ch[0]);
	if (node[u].ok)
		cout << dtoc(node[u].val);
	print(node[u].ch[1]);
}

int Access(int l,int r)
{
	if (l != 1 && r != node[root].size)
	{
		root = Splay(findKth(root,l - 1));
		node[node[root].ch[1]].fa = 0;
		node[root].ch[1] = Splay(findKth(root,r + 1));
		node[node[root].ch[1]].fa = root;
		return node[node[root].ch[1]].ch[0];
	}
	else if (r != node[root].size)
	{
		root = Splay(findKth(root,r + 1));
		return node[root].ch[0];
	}
	else if (l != 1)
	{
		root = Splay(findKth(root,l - 1));
		return node[root].ch[1];
	}
	return root;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	string ss;
	cin >> ss;
	for (int i = 0;i < n;i++)
	{
		root = Insert(root,ctod(ss[i]));
		root = Splay(i + 1);
	}
	for (int i = 1;i <= m;i++)
	{
		cin >> L >> R >> x;
		int region = Access(L,R);
		Mark(region,ctod(x));
		for (int j = region;!is_root(j);j = node[j].fa)
			Update(node[j].fa);
	}
	print(root);
	cout << endl;
	return 0;
}