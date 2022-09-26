#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

typedef long long ll;

inline char gc()
{
	static char buf[524288],*p1 = buf,*p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,524288,stdin),p1 == p2) ? EOF : *p1++;
}

inline void read(int &v)
{
	v = 0;
	char c = gc();
	while (c < '0' || c > '9')
		c = gc();
	while (c >= '0' && c <= '9')
	{
		v = v * 10 + c - '0';
		c = gc();
	}
}

inline void read(ll &v)
{
	v = 0;
	char c = gc();
	while (c < '0' || c > '9')
		c = gc();
	while (c >= '0' && c <= '9')
	{
		v = v * 10 + c - '0';
		c = gc();
	}
}

const int MAXN = 500005;

struct Node
{
    int ch[2];
    int hpv,size;
}node[MAXN];

int n,m,q;
int cnt[MAXN];
int root[MAXN];
int ans[MAXN];

pair<ll,int> qr[MAXN];

void update(int u)
{
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
    	node[v].ch[0] = node[v].ch[1] = 0;
    	node[v].size = 1;
        return v;
    }
    bool dir = u < v;
    node[u].ch[dir] = insert(node[u].ch[dir],v);
    u = node[node[u].ch[dir]].hpv > node[u].hpv ? rotate(u,dir) : u;
    update(u);
    return u;
}

int findKth(int u,int k)
{
	if (k <= node[node[u].ch[0]].size)
		return findKth(node[u].ch[0],k);
	k -= node[node[u].ch[0]].size;
	if (k == 1)
		return u;
	k--;
	return findKth(node[u].ch[1],k);
}

void go(int u,int id)
{
	if (!u)
		return;
	int tmp = node[u].ch[1];
	go(node[u].ch[0],id);
	root[id] = insert(root[id],u);
	go(tmp,id);
}

int main()
{
	srand(20030506);
	read(n),read(m),read(q);
	for (int a,i = 1;i <= n;i++)
	{
		read(a);
		cnt[a]++;
	}
	for (int i = 1;i <= m;i++)
	{
		node[i].hpv = rand() << 15 | rand();
		root[cnt[i]] = insert(root[cnt[i]],i);
	}
	for (int i = 1;i <= q;i++)
	{
		ll Q;
		read(Q);
		Q -= n;
		qr[i] = make_pair(Q,i);
	}
	sort(qr + 1,qr + q + 1);
	ll tot = 0,j = 1;
	for (int i = 0;j <= q && i < n;i++)
	{
		while (j <= q && qr[j].first - tot <= node[root[i]].size)
		{
			ans[qr[j].second] = findKth(root[i],qr[j].first - tot);
			j++;
		}
		tot += node[root[i]].size;
		if (node[root[i]].size > node[root[i + 1]].size)
			swap(root[i],root[i + 1]);
		go(root[i],i + 1);
	}
	while (j <= q)
	{
		ans[qr[j].second] = (qr[j].first - tot) % m;
		if (!ans[qr[j].second])
			ans[qr[j].second] = m;
		j++;
	}
	for (int i = 1;i <= q;i++)
		printf("%d\n",ans[i]);
	return 0;
}