#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <utility>
#define rep(a,b) for (int a=0;a<b;a++)
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
using namespace std;

int n,f[100100],X,Y,tree[100100];
long long A,B,C,D;
pair<pair <int,int>,int> a[100100];
pair <int,int> b[100100];

void add(int x,int v)
{
	for (int i=x+1;i<=Y;i+=i&-i) tree[i]=max(tree[i],v);
}

int get(int x)
{
	int r=0;
	for (int i=x+1;i;i-=i&-i) r=max(r,tree[i]);
	return r;
}

void conv(string s,long long &a,long long &b)
{
	a=b=0;
	rep(i,sz(s))
		if (s[i]=='/') 
		{
			s.erase(0,i+1); break;
		}
		else a=a*10+s[i]-'0';
	rep(i,sz(s)) b=b*10+s[i]-'0';
}

int cmpX(int x,int y,int xx,int yy)
{
	long long x0=C*x-D*(y-yy);
	if (x0==C*xx) return 0;
	if (x0>C*xx) return 1;
	return -1;
}

int cmpY(int x,int y,int xx,int yy)
{
	long long y0=B*y-A*(x-xx);
	if (y0==B*yy) return 0;
	if (y0>B*yy) return 1;
	return -1;
}

bool mycmp(pair<pair <int,int>,int> u,pair<pair <int,int>,int> v)
{
	int x=u.fi.fi,y=u.fi.se,xx=v.fi.fi,yy=v.fi.se;
	int X=cmpX(x,y,xx,yy), Y=cmpY(x,y,xx,yy);
	return X<0 || (!X && Y<0);
}


bool mycmp2(pair<pair <int,int>,int> u,pair<pair <int,int>,int> v)
{
	int x=u.fi.fi,y=u.fi.se,xx=v.fi.fi,yy=v.fi.se;
	return cmpY(x,y,xx,yy)<0;
}

int main()
{
	string s,t;
	int x,y;
	cin >> n;
	cin >> s >> t;
	conv(s,A,B);
	conv(t,C,D);
	
	int nn=0;
	rep(i,n) 
	{
		cin >> x >> y;
		if (A*x<B*y && C*x>D*y)
			a[nn++]=mp(mp(x,y),0);
	}
	
	if (!nn)
	{
		puts("0");
		return 0;
	}
	
	swap(n,nn);
	sort(a,a+n,mycmp);
	
	rep(i,n)
	{
		a[i].se=i;
		if (!i || cmpX(a[i].fi.fi,a[i].fi.se,a[i-1].fi.fi,a[i-1].fi.se)) X++;
		b[i].fi=X-1;
	}	
	
	sort(a,a+n,mycmp2);
	rep(i,n)
	{
		if (!i || cmpY(a[i].fi.fi,a[i].fi.se,a[i-1].fi.fi,a[i-1].fi.se)) Y++;
		b[a[i].se].se=Y-1;
	}
	
	int ans=0,j=0;
	rep(i,n)
	{
		int x=b[i].fi,y=b[i].se;
		while (j<n && x>b[j].fi) add(b[j].se,f[j]), j++;
		f[i]=get(y-1)+1;
		ans=max(ans,f[i]);
	}
	
	cout << ans << endl;
}