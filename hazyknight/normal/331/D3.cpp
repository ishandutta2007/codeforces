#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 400005;

struct Seg
{
	int l,r,tp;
	
	bool operator < (const Seg &p)const
	{
		return l < p.l;
	}
};

int n,L,q,cc,id;
int first[MAXN];
int xa[MAXN];
int ya[MAXN];
int xb[MAXN];
int yb[MAXN];
int X[MAXN];
int Y[MAXN];
int TP[MAXN];
int tp[MAXN];
int MINx[MAXN];
int MINy[MAXN];
int MAXx[MAXN];
int MAXy[MAXN];
int to[MAXN][50];
int laz[MAXN << 2];
int dr[4][2] = 
{
	1,0,
	0,1,
	-1,0,
	0,-1,
};

ll t[MAXN];
ll dis[MAXN][50];

bool gg[MAXN];

vector<int> ver[MAXN];
vector<int> ver1[MAXN];
vector<int> ver2[MAXN];
vector<int> hor[MAXN];
vector<int> hor1[MAXN];
vector<int> hor2[MAXN];
set<Seg> spjx[MAXN];
set<Seg> spjy[MAXN];
vector<pair<int,int> > ptx[MAXN];
vector<pair<int,int> > pty[MAXN];

map<int,int> match[4][MAXN];

int newnode(int x,int y,int &t,int fl = 0)
{
	if (!match[t][x][y])
	{
		match[t][x][y] = ++cc;
		if (fl == 1)
			gg[cc] = 1;
	}
	int cur = match[t][x][y];
	if (fl != 2)
	{
		ptx[x].push_back(make_pair(y,cur));
		pty[y].push_back(make_pair(x,cur));
	}
	X[cur] = x;
	Y[cur] = y;
	TP[cur] = t;
	return cur;
}

void pushdown(int o)
{
	if (laz[o])
	{
		laz[o << 1] = laz[o << 1 | 1] = laz[o];
		laz[o] = 0;
	}
}

void cover(int o,int l,int r,int x,int y,int v)
{
	if (l >= x && r <= y)
	{
		laz[o] = v;
		return;
	}
	pushdown(o);
	int mid = l + r >> 1;
	if (mid >= x)
		cover(o << 1,l,mid,x,y,v);
	if (mid + 1 <= y)
		cover(o << 1 | 1,mid + 1,r,x,y,v);
}

int query(int o,int l,int r,int p)
{
	if (laz[o] || l == r)
		return laz[o];
	int mid = l + r >> 1;
	if (mid >= p)
		return query(o << 1,l,mid,p);
	return query(o << 1 | 1,mid + 1,r,p);
}

void print(ll x,ll y,int p,ll t)
{
	x += dr[p][0] * t;
	y += dr[p][1] * t;
	x = max(x,0ll);
	x = min(x,(ll)L);
	y = max(y,0ll);
	y = min(y,(ll)L);
	printf("%lld %lld\n",x,y);
}

/*
R 0
U 1
L 2
D 3
*/

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%d%d",&n,&L);
	for (int i = 0;i <= L;i++)
		MINx[i] = MINy[i] = L;
	for (int i = 1;i <= n;i++)
	{
		scanf("%d%d%d%d",&xa[i],&ya[i],&xb[i],&yb[i]);
		if (xa[i] == xb[i])
		{
			ver[xa[i]].push_back(i);
			newnode(xa[i],yb[i],tp[i] = ya[i] < yb[i] ? 1 : 3);
			if (ya[i] < yb[i])
				hor1[yb[i]].push_back(i);
			else
				hor2[yb[i]].push_back(i);
			spjx[xa[i]].insert((Seg){min(ya[i],yb[i]),max(ya[i],yb[i]),tp[i]});
		}
		if (ya[i] == yb[i])
		{
			hor[ya[i]].push_back(i);
			newnode(xb[i],ya[i],tp[i] = xa[i] < xb[i] ? 0 : 2);
			if (xa[i] < xb[i])
				ver1[xb[i]].push_back(i);
			else
				ver2[xb[i]].push_back(i);
			spjy[ya[i]].insert((Seg){min(xa[i],xb[i]),max(xa[i],xb[i]),tp[i]});
		}
	}
	scanf("%d",&q);
	for (int x,y,i = 1;i <= q;i++)
	{
		char c;
		scanf("%d%d %c %lld",&x,&y,&c,&t[i]);
		xa[n + i] = xb[n + i] = x;
		ya[n + i] = yb[n + i] = y;
		int C = 0;
		if (c == 'U')
			C = 1;
		if (c == 'L')
			C = 2;
		if (c == 'D')
			C = 3;
		set<Seg>::iterator it = spjx[x].upper_bound((Seg){y,y,0});
		if (it != spjx[x].begin())
		{
			it--;
			if (it->r >= y)
				C = it->tp;
		}
		it = spjy[y].upper_bound((Seg){x,x,0});
		if (it != spjy[y].begin())
		{
			it--;
			if (it->r >= x)
				C = it->tp;
		}
		tp[n + i] = C;
		if (C == 0)
			ver1[xb[n + i]].push_back(n + i);
		if (C == 1)
			hor1[yb[n + i]].push_back(n + i);
		if (C == 2)
			ver2[xb[n + i]].push_back(n + i);
		if (C == 3)
			hor2[yb[n + i]].push_back(n + i);
	}
	memset(laz,0,sizeof(laz));
	for (int i = 0;i <= L;i++)
	{
		for (int j = 0;j < ver[i].size();j++)
		{
			int u = ver[i][j];
			cover(1,0,L,min(ya[u],yb[u]),max(ya[u],yb[u]),u);
		}
		for (int j = 0;j < ver2[i].size();j++)
		{
			int u = ver2[i][j],p = query(1,0,L,yb[u]);
			if (p)
				newnode(xa[p],yb[u],tp[p]);
		}
	}
	memset(laz,0,sizeof(laz));
	for (int i = 0;i <= L;i++)
	{
		for (int j = 0;j < hor[i].size();j++)
		{
			int u = hor[i][j];
			cover(1,0,L,min(xa[u],xb[u]),max(xa[u],xb[u]),u);
		}
		for (int j = 0;j < hor2[i].size();j++)
		{
			int u = hor2[i][j],p = query(1,0,L,xb[u]);
			if (p)
				newnode(xb[u],ya[p],tp[p]);
		}
	}
	memset(laz,0,sizeof(laz));
	for (int i = L;i >= 0;i--)
	{
		for (int j = 0;j < ver[i].size();j++)
		{
			int u = ver[i][j];
			cover(1,0,L,min(ya[u],yb[u]),max(ya[u],yb[u]),u);
		}
		for (int j = 0;j < ver1[i].size();j++)
		{
			int u = ver1[i][j],p = query(1,0,L,yb[u]);
			if (p)
				newnode(xa[p],yb[u],tp[p]);
		}
	}
	memset(laz,0,sizeof(laz));
	for (int i = L;i >= 0;i--)
	{
		for (int j = 0;j < hor[i].size();j++)
		{
			int u = hor[i][j];
			cover(1,0,L,min(xa[u],xb[u]),max(xa[u],xb[u]),u);
		}
		for (int j = 0;j < hor1[i].size();j++)
		{
			int u = hor1[i][j],p = query(1,0,L,xb[u]);
			if (p)
				newnode(xb[u],ya[p],tp[p]);
		}
	}
	for (int i = 0;i <= L;i++)
	{
		sort(ptx[i].begin(),ptx[i].end());
		sort(pty[i].begin(),pty[i].end());
		ptx[i].resize(unique(ptx[i].begin(),ptx[i].end()) - ptx[i].begin());
		pty[i].resize(unique(pty[i].begin(),pty[i].end()) - pty[i].begin());
		for (int j = 1;j < ptx[i].size();j++)
		{
			int c = ptx[i][j].second;
			if (TP[c] == 3)
			{
				to[c][0] = ptx[i][j - 1].second;
				dis[c][0] = ptx[i][j].first - ptx[i][j - 1].first;
			}
		}
		for (int j = (int)ptx[i].size() - 2;j >= 0;j--)
		{
			int c = ptx[i][j].second;
			if (TP[c] == 1)
			{
				to[c][0] = ptx[i][j + 1].second;
				dis[c][0] = ptx[i][j + 1].first - ptx[i][j].first;
			}
		}
		for (int j = 1;j < pty[i].size();j++)
		{
			int c = pty[i][j].second;
			if (TP[c] == 2)
			{
				to[c][0] = pty[i][j - 1].second;
				dis[c][0] = pty[i][j].first - pty[i][j - 1].first;
			}
		}
		for (int j = (int)pty[i].size() - 2;j >= 0;j--)
		{
			int c = pty[i][j].second;
			if (TP[c] == 0)
			{
				to[c][0] = pty[i][j + 1].second;
				dis[c][0] = pty[i][j + 1].first - pty[i][j].first;
			}
		}
	}
	for (int i = 1;i < 50;i++)
		for (int j = 1;j <= cc;j++)
		{
			to[j][i] = to[to[j][i - 1]][i - 1];
			dis[j][i] = dis[j][i - 1] + dis[to[j][i - 1]][i - 1];
			if (dis[j][i] >= 1e18)
				dis[j][i] = 1e18;
		}
//	for (int i = 1;i <= cc;i++)
//		cout << X[i] << ' ' << Y[i] << ' ' << TP[i] << ' ' << to[i][0] << ' ' << dis[i][0] << endl;
	for (int i = 1;i <= q;i++)
	{
		int x = xa[n + i],y = ya[n + i],cur = 0;
		if (tp[n + i] == 0)
		{
			vector<pair<int,int> >::iterator it = lower_bound(pty[y].begin(),pty[y].end(),make_pair(x,0));
			if (it == pty[y].end() || it->first - x >= t[i])
			{
				print(x,y,0,t[i]);
				continue;
			}
			t[i] -= it->first - x;
			cur = it->second;
		}
		if (tp[n + i] == 1)
		{
			vector<pair<int,int> >::iterator it = lower_bound(ptx[x].begin(),ptx[x].end(),make_pair(y,0));
			if (it == ptx[x].end() || it->first - y >= t[i])
			{
				print(x,y,1,t[i]);
				continue;
			}
			t[i] -= it->first - y;
			cur = it->second;
		}
		if (tp[n + i] == 2)
		{
			vector<pair<int,int> >::iterator it = upper_bound(pty[y].begin(),pty[y].end(),make_pair(x,1000000000));
			if (it == pty[y].begin() || x - (--it)->first >= t[i])
			{
				print(x,y,2,t[i]);
				continue;
			}
			t[i] -= x - it->first;
			cur = it->second;
		}
		if (tp[n + i] == 3)
		{
			vector<pair<int,int> >::iterator it = upper_bound(ptx[x].begin(),ptx[x].end(),make_pair(y,1000000000));
			if (it == ptx[x].begin() || y - (--it)->first >= t[i])
			{
				print(x,y,3,t[i]);
				continue;
			}
			t[i] -= y - it->first;
			cur = it->second;
		}
	//	for (int j = 49;j >= 0;j--)
	//		cout << dis[cur][j] << ' ';
	//	cout << endl;
		for (int j = 49;j >= 0;j--)
			if (to[cur][j] && t[i] >= dis[cur][j])
			{
				t[i] -= dis[cur][j];
				cur = to[cur][j];
			}
		print(X[cur],Y[cur],TP[cur],t[i]);
	}
	return 0;
}