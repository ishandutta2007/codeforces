#include <bits/stdc++.h>
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+5;
struct Q
{
	int x,y;
	int operator-(const Q &o) const {return abs(x-o.x)+abs(y-o.y);}
	bool operator==(const Q &o) const {return x==o.x&&y==o.y;}
};
Q o,p;
int dig(Q a)
{
	cout<<"DIG "<<a.x<<' '<<a.y<<endl;
	//return a==o||a==p;
	int x;
	cin>>x;
	return x;
}
int scan(Q a)
{
	cout<<"SCAN "<<a.x<<' '<<a.y<<endl;
	//return (a-o)+(a-p);
	int dis;
	cin>>dis;
	return dis;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n>>m;
		//cin>>o.x>>o.y>>p.x>>p.y;
		int sum=scan({1,1})+4;
		int dif=(scan({1,m})+2)-m*2;
		int sx=(sum+dif)/2,sy=(sum-dif)/2;
		int dx=scan({sx/2,1})-(sy-2);
		int dy=scan({1,sy/2})-(sx-2);
		int x1=(sx+dx)/2,x2=(sx-dx)/2,y1=(sy+dy)/2,y2=(sy-dy)/2;
		//dbgn(sum,dif,sx,dx,sy,dy);
		if (dig({x1,y1}))
		{
			dig({x2,y2});
		}
		else
		{
			dig({x1,y2});
			dig({x2,y1});
		}
	}
}