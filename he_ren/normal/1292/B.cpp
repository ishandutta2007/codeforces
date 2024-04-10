#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fir first
#define sec second
#define Mp make_pair
const int MAXN = 200 + 5;
const ll mxpos = 1e17;

struct Node
{
	ll x,y;
}a[MAXN];
int n=0;

inline ll dist(Node p,Node q){ return abs(p.x-q.x)+abs(p.y-q.y);}

int ans=0;
void calc(int st,Node now,ll t)
{
	int res=0;
	for(int i=st; i>=1; --i)
	{
		t-=dist(now,a[i]);
		if(t<0) break;
		++res;
		now=a[i];
	}
	if(t>=0) for(int i=st+1; i<=n; ++i)
	{
		t-=dist(now,a[i]);
		if(t<0) break;
		++res;
		now=a[i];
	}
	if(ans<res) ans=res;
}

int main(void)
{
	ll x_0,y_0,ax,ay,bx,by,xs,ys,t;
	cin>>x_0>>y_0>>ax>>ay>>bx>>by>>xs>>ys>>t;
	
	Node beg=(Node){xs,ys};
	a[++n]=(Node){x_0,y_0};
	
	while(1)
	{
		ll x=a[n].x, y=a[n].y;
		if(ax>(mxpos-bx+x-1)/x || ay>(mxpos-by+y-1)/y) break;
		x = ax*x+bx;
		y = ay*y+by;
		if(x>mxpos || y>mxpos) break;
		a[++n]=(Node){x,y};
	}
	
	for(int i=1; i<=n; ++i)
		calc(i,beg,t);
	
	printf("%d",ans);
	return 0;
}