#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define oo 1LL << 60
using namespace std;
struct ramp
{
	int l,r,t,d;
};

int n,L,ans,M;
pair <long long,int> f[100100],fl[1000100],fr[1000100];
ramp a[100100];
vector < pii > X;

bool cmp(ramp i,ramp j)
{
	return i.l<j.l;
}

void edit(int y,int M)
{
	if (y&1) a[y/2].r=M;
	else a[y/2].l=M;
}

void Unique()
{
	sort(all(X));
	M=0; edit(X[0].se,M);
	fr(i,1,sz(X)-1)
	{
		if (X[i].fi>X[M].fi) X[++M]=X[i];
		edit(X[i].se,M);
	}
}

void init(int nd,int l,int r)
{
	fl[nd]=fr[nd]=mp(oo,1);
	if (l==r) return;
	int m=(l+r)>>1;
	init(nd<<1,l,m);
	init((nd<<1)+1,m+1,r);
}

pair<long long,int> get(pair<long long,int> f[],int nd,int l,int r,int x,int y)
{
	//printf("GET nd = %d l = %d r = %d \n",nd,l,r);
	if (l==x && r==y) return f[nd];
	int m=(l+r)>>1;
	pair<long long,int> u=mp(oo,0),v=mp(oo,0);
	if (x<=m) u=get(f,nd<<1,l,m,x,min(y,m));
	if (m<y) v=get(f,(nd<<1)+1,m+1,r,max(x,m+1),y);
	return min(v,u);
}

void update(pair<long long,int> f[],int nd,int l,int r,int x,pair<long long,int> v)
{
	f[nd]=min(f[nd],v);
	if (l==r) return;
	int m=(l+r)>>1;
	if (x<=m) update(f,nd<<1,l,m,x,v);
	else update(f,(nd<<1)+1,m+1,r,x,v);
}

int main()
{
	cin >> n >> L;
	fr(i,1,n) 
	{
		int x,d,g;
		scanf("%d%d%d%d",&x,&d,&a[i].t,&g);
		a[i].l=x-g;	a[i].r=x+d; a[i].d=i; a[i].t+=g;
		X.pb(mp(a[i].l,i*2));
		X.pb(mp(a[i].r,i*2+1));
	}
	a[n+1].l=a[n+1].r=L; a[n+1].t=0; a[n+1].d=n+1; X.pb(mp(L,n*2+2));
	a[0].d=a[0].r=a[0].l=a[0].t=0; a[0].t=0; X.pb(mp(0,1));
	Unique();
	
	sort(a+1,a+n+1,cmp);
	init(1,0,M);
	fr(i,0,n+1)
	{
		if (i) f[i]=mp(oo,i);
		else f[i]=mp(0LL,0);
		if (i && X[a[i].l].fi<0) continue;
		if (i) 
		{
			pair <long long,int> u=mp(oo,0),v=mp(oo,0);
			u=get(fl,1,0,M,0,a[i].l);
			u.fi+=X[a[i].l].fi;
			v=get(fr,1,0,M,a[i].l,M);
			v.fi-=X[a[i].l].fi;
			f[i]=min(u,v);
		}
		f[i].fi+=a[i].t;
		if (i<=n)
		{
			pair <long long,int> u=f[i],v=f[i];
			u.fi-=X[a[i].r].fi; u.se=i;
			update(fl,1,0,M,a[i].r,u);
			v.fi+=X[a[i].r].fi; v.se=i;
			update(fr,1,0,M,a[i].r,v); 
		}
	}
	cout << f[n+1].fi << endl;
	vector <int> tr;
	int i=n+1;
	while (i)	tr.pb(i), i=f[i].se;
	reverse(all(tr));
	cout << sz(tr)-1 << endl;
	fr(i,0,sz(tr)-2) cout << a[tr[i]].d << endl;
}