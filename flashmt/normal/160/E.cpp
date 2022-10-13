#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;

struct rec
{
	int x,y,z,d;
};

bool operator < (const rec &i, const rec &j)
{
	if (i.x!=j.x) return i.x<j.x;
	return i.d<j.d;
}

int m,n,p,f[1000200],id[1000200],ans[200200];
rec a[200020];
vector <int> X;

void add(int nd,int l,int r,int x,int v,int p)
{
	f[nd]=max(f[nd],v);
	if (l==r)	
	{
		id[nd]=p; return;
	}
	int m=(l+r)/2;
	if (x<=m) add(nd*2,l,m,x,v,p);
	else add(nd*2+1,m+1,r,x,v,p);
}

int get(int nd,int l,int r,int x,int y,int v)
{
	if (f[nd]<v) return -1;
	int m=(l+r)/2,res=-1;
	if (l==x && r==y) 
	{
		if (l==r) return id[nd];
		
		if (f[nd*2]>=v) return get(nd*2,l,m,l,m,v);
		return get(nd*2+1,m+1,r,m+1,r,v);
	}
	if (x<=m) res=get(nd*2,l,m,x,min(y,m),v);
	if (res>=0) return res;
	return get(nd*2+1,m+1,r,max(x,m+1),y,v);
}

int main()
{
	cin >> n >> m;
	fr(i,1,n) 
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		a[i].d=i; 
		X.pb(a[i].z);
	}
	fr(i,n+1,n+m) 
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		a[i].d=i; 
		X.pb(a[i].z);
	}
	sort(a+1,a+n+m+1);
	sort(all(X));
	X.resize(unique(X.begin(),X.end())-X.begin());
	p=sz(X);
	
	fr(i,1,n+m)
	{
		int z=lower_bound(X.begin(),X.end(),a[i].z)-X.begin();
		if (a[i].d>n) ans[a[i].d-n]=get(1,0,p-1,z,p-1,a[i].y);
		else add(1,0,p-1,z,a[i].y,a[i].d);
	}	
	fr(i,1,m) cout << ans[i] << ' ';
}