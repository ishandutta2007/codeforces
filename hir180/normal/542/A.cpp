#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int seg1[(1<<21)],id1[(1<<21)];
vector<int>zx;
void update1(int k,int a,int x)
{
	k+=(1<<20)-1;
	if(seg1[k]<a)
	{
		seg1[k]=a;
		id1[k] = x;
	}
	while(k>0)
	{
		k=(k-1)/2;
		if(seg1[k*2+1] < seg1[k*2+2])
		{
			seg1[k]=seg1[k*2+2];
			id1[k]=id1[k*2+2];
		}
		else
		{
			seg1[k]=seg1[k*2+1];
			id1[k]=id1[k*2+1];
		}
	}
}
P query1(int a,int b,int k,int l,int r)
{
	if(r<a || b<l) return mp(0,0);
	if(a<=l && r<=b) return mp(seg1[k],id1[k]);
	else
	{
		P vl=query1(a,b,k*2+1,l,(l+r)/2);
		P vr=query1(a,b,k*2+2,(l+r)/2+1,r);
		if(vl.fi >= vr.fi) return vl;
		else return vr;
	}
}
int seg2[(1<<21)],id2[(1<<21)];
void update2(int k,int a,int x)
{
	k+=(1<<20)-1;
	if(seg2[k]>a)
	{
		seg2[k]=a;
		id2[k] = x;
	}
	while(k>0)
	{
		k=(k-1)/2;
		if(seg2[k*2+1] > seg2[k*2+2])
		{
			seg2[k]=seg2[k*2+2];
			id2[k]=id2[k*2+2];
		}
		else
		{
			seg2[k]=seg2[k*2+1];
			id2[k]=id2[k*2+1];
		}
	}
}
P query2(int a,int b,int k,int l,int r)
{
	if(r<a || b<l) return mp(INF,0);
	if(a<=l && r<=b) return mp(seg2[k],id2[k]);
	else
	{
		P vl=query2(a,b,k*2+1,l,(l+r)/2);
		P vr=query2(a,b,k*2+2,(l+r)/2+1,r);
		if(vl.fi <= vr.fi) return vl;
		else return vr;
	}
}
vector<int>seg[(1<<21)];
vector<P>val[(1<<21)];
void update(int k,int a,int x)
{
	int kk=k;
	k += (1<<20)-1;
	seg[k].pb(a);
	val[k].pb(mp(zx[a]-zx[kk],x));
}
vector<int>s[(1<<21)];
void all()
{
	for(int i=(1<<20)-1;i<(1<<21);i++)
	{
		if(seg[i].empty()) continue;
		sort(seg[i].begin(),seg[i].end());
		sort(val[i].begin(),val[i].end());
	}
	for(int i=(1<<20)-2;i>=0;i--)
	{
		int le = 0,ri = 0;
		while(le != seg[i*2+1].size() || ri != seg[i*2+2].size())
		{
			if(le == seg[i*2+1].size() || (le!=seg[i*2+1].size()&&ri!=seg[i*2+2].size()&&seg[i*2+1][le]>seg[i*2+2][ri]))
			{
				seg[i].pb(seg[i*2+2][ri]);
				if(val[i].empty() || val[i].back().fi < val[i*2+2][ri].fi)
				{
					val[i].pb(val[i*2+2][ri]);
				}
				else
				{
					val[i].pb(val[i].back());
				}
				ri++;
			}
			else
			{
				seg[i].pb(seg[i*2+1][le]);
				if(val[i].empty() || val[i].back().fi < val[i*2+1][le].fi)
				{
					val[i].pb(val[i*2+1][le]);
				}
				else
				{
					val[i].pb(val[i].back());
				}
				le++;
			}
		}
	}
}
P query(int a,int b,int k,int l,int r,int lim)
{
	if(r<a || b<l) return mp(0,0);
	if(a<=l && r<=b)
	{
		int e = upper_bound(seg[k].begin(),seg[k].end(),lim)-seg[k].begin();
		e--;
		if(e < 0) return mp(0,0);
		return val[k][e];
	}
	P lk = query(a,b,k*2+1,l,(l+r)/2,lim);
	P rk = query(a,b,k*2+2,(l+r)/2+1,r,lim);
	if(lk.fi > rk.fi) return lk;
	else return rk;
}
int n,m;
int a[200005],b[200005];
int c[200005],d[200005],e[200005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		zx.pb(a[i]); zx.pb(b[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&c[i],&d[i],&e[i]);
		zx.pb(c[i]); zx.pb(d[i]);
	}
	sort(zx.begin(),zx.end()); zx.erase(unique(zx.begin(),zx.end()),zx.end());
	for(int i=1;i<=n;i++)
	{
		a[i] = lower_bound(zx.begin(),zx.end(),a[i])-zx.begin();
		b[i] = lower_bound(zx.begin(),zx.end(),b[i])-zx.begin();
	}
	for(int i=1;i<=m;i++)
	{
		c[i] = lower_bound(zx.begin(),zx.end(),c[i])-zx.begin();
		d[i] = lower_bound(zx.begin(),zx.end(),d[i])-zx.begin();
	}
	fill(seg2,seg2+(1<<21),INF);
	for(int i=1;i<=n;i++)
	{
		update(a[i],b[i],i);
		update1(a[i],b[i],i);
		update2(b[i],a[i],i);
	}
	all();
	ll res = 0; int atx,aty;
	for(int i=1;i<=m;i++)
	{
		P p = query1(0,c[i],0,0,(1<<20)-1);
		int x = p.fi,y = p.sc; ll val;
		if(x<=c[i]) goto nxt;
		val = 1LL * max(0,zx[min(d[i],x)]-zx[c[i]]) * e[i];
		if(res < val)
		{
			res = val;
			atx = y;
			aty = i;
		}
		nxt:;
		p = query2(d[i],(1<<20)-1,0,0,(1<<20)-1);
		x = p.fi; y = p.sc;
		if(x>=d[i]) goto nxt2;
		val = 1LL * max(0,zx[d[i]]-zx[max(x,c[i])]) * e[i];
		if(res < val)
		{
			res = val;
			atx = y;
			aty = i;
		}
		nxt2:;
		p = query(c[i],d[i],0,0,(1<<20)-1,d[i]);
		x = p.fi; y = p.sc;
		val = 1LL * x * e[i];
		if(res < val)
		{
			res = val;
			atx = y;
			aty = i;
		}
	}
	cout << res << endl;
	if(res)
	{
		cout << atx << " " << aty << endl;
	}
}