#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <bitset>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

const int MAXN = 200005;

struct Node
{
	int ch[2];
	int key,hpv,sum,size;
}node[MAXN];
 
int n,m,root;
 
void update(int u)
{
	node[u].sum = node[node[u].ch[0]].sum + node[u].key + node[node[u].ch[1]].sum;
	node[u].size = node[node[u].ch[0]].size + 1 + node[node[u].ch[1]].size;
}
 
int rotate(int u,bool dir)
{
	int ch = node[u].ch[dir];
	node[u].ch[dir] = node[ch].ch[!dir];
	update(u);
	node[ch].ch[!dir] = u;
	return ch;
}
 
int insert(int u,int v)
{
	if (!u)
	{
		update(v);
		return v;
	}
	bool dir = node[u].key < node[v].key;
	node[u].ch[dir] = insert(node[u].ch[dir],v);
	u = node[node[u].ch[dir]].hpv > node[u].hpv ? rotate(u,dir) : u;
	update(u);
	return u;
}

int getans(int u,int v)
{
	if (!u)
		return 0;
	if (node[node[u].ch[0]].sum >= v)
		return getans(node[u].ch[0],v);
	int res = node[node[u].ch[0]].size;
	v -= node[node[u].ch[0]].sum;
	if (v <= node[u].key)
		return res + (v == node[u].key);
	v -= node[u].key;
	res++;
	return res + getans(node[u].ch[1],v);
}

int main()
{
	srand(time(0));
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		scanf("%d",&node[i].key);
	for (int i = 1;i <= n;i++)
	{
		printf("%d ",i - 1 - getans(root,m - node[i].key));
		node[i].hpv = rand() << 15 | rand();
		root = insert(root,i);
	}
	puts("");
	return 0;
}