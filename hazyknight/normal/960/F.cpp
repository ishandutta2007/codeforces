#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int MAXN = 100005;

struct Node
{
	int ch[2];
	int key,val,fix,MAX;
	Node()
	{
		ch[0] = ch[1] = 0;
		key = val = fix = MAX = 0;
	}
}node[MAXN];

int n,m,id,ans;
int u[MAXN];
int v[MAXN];
int c[MAXN];
int root[MAXN];

void update(int now)
{
	node[now].MAX = node[now].val;
	if (node[now].ch[0])
		node[now].MAX = max(node[now].MAX,node[node[now].ch[0]].MAX);
	if (node[now].ch[1])
		node[now].MAX = max(node[now].MAX,node[node[now].ch[1]].MAX);
}

int rotate(int now,bool dir)
{
	int ch = node[now].ch[dir];
	node[now].ch[dir] = node[ch].ch[!dir];
	update(now);
	node[ch].ch[!dir] = now;
	return ch;
}

int Insert(int now,int key,int val)
{
	if (!now)
	{
		now = ++id;
		node[now].key = key;
		node[now].MAX = node[now].val = val;
		node[now].fix = rand();
		return now;
	}
	bool dir = (key >= node[now].key);
	node[now].ch[dir] = Insert(node[now].ch[dir],key,val);
	if (node[node[now].ch[dir]].fix < node[now].fix)
		now = rotate(now,dir);
	update(now);
	return now;
}

int MAX(int now)
{
	if (!now)
		return 0;
	return node[now].MAX;
}

int GetMAX(int now,int key)
{
	if (!now)
		return 0;
	if (node[now].key < key)
		return max(node[now].val,max(MAX(node[now].ch[0]),GetMAX(node[now].ch[1],key)));
	return GetMAX(node[now].ch[0],key);
}

int main()
{
	srand((unsigned long long)new char);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1;i <= m;i++)
		cin >> u[i] >> v[i] >> c[i];
	for (int f,i = 1;i <= m;i++)
	{
		f = GetMAX(root[u[i]],c[i]) + 1;
		ans = max(ans,f);
		root[v[i]] = Insert(root[v[i]],c[i],f);
	}
	cout << ans << endl;
	return 0;
}