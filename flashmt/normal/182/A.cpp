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
#define reset(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
#define sqr(x) ((x)*(x))
using namespace std;

struct trench
{
	int x,y,xx,yy;
	void edit()
	{
		if (x==xx) 
		{
			if (y>yy) swap(y,yy);
		}
		else
		{
			if (x>xx) swap(x,xx);
		}
	}
	
	int dist(const trench &u)
	{
		return sqr(max(0,max(u.x,x)-min(u.xx,xx)))+sqr(max(0,max(u.y,y)-min(u.yy,yy)));
	}
} a[1010];

int A,B,n,d[1010];
double f[1010];

int main()
{
	cin >> A >> B;
	cin >> a[1].x >> a[1].y; a[1].xx=a[1].x; a[1].yy=a[1].y;
	cin >> a[2].x >> a[2].y; a[2].xx=a[2].x; a[2].yy=a[2].y;
	cin >> n;
	n+=2;
	fr(i,3,n) cin >> a[i].x >> a[i].y >> a[i].xx >> a[i].yy;
	fr(i,1,n) a[i].edit();
	
	fr(i,1,n) f[i]=1e15;
	int x=1;
	f[1]=0;
	while (1)
	{
		d[x]=1;
		if (x==2) break;
		fr(i,1,n)
			if (!d[i] && a[x].dist(a[i])<=A*A)
			{
				long long t=(long long)(f[x]/(A+B))+1;
				if (x==1) t=0;
				f[i]=min(f[i],sqrt(a[x].dist(a[i]))+1.0*t*(A+B));
			}
		int y=0;
		double best=1e14;
		fr(i,1,n)
			if (!d[i] && f[i]<best)
				best=f[i], y=i;
		if (!y) break;
		x=y;
	}
	if (!d[2]) puts("-1");
	else printf("%.9lf\n",f[2]);
}