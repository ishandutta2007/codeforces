#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <utility>
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
using namespace std;
struct tree
{
	int x,h,l,r;
};

int n,m;
tree a[100100];
vector < pii > mushroom;
double f[10100];

int main()
{
	pii u;
	cin >> n >> m;
	rep(i,n) scanf("%d%d%d%d",&a[i].x,&a[i].h,&a[i].l,&a[i].r);
	rep(i,m) scanf("%d%d",&u.fi,&u.se), mushroom.pb(u);
	sort(all(mushroom));
	rep(i,m) f[i]=1;
	rep(i,n)
	{
		// left
		int L=lower_bound(mushroom.begin(),mushroom.end(),mp(a[i].x-a[i].h,-1))-mushroom.begin();
		int R=lower_bound(mushroom.begin(),mushroom.end(),mp(a[i].x,-1))-mushroom.begin();
		if (L<R) f[L]*=(1.0-0.01*a[i].l), f[R]/=(1.0-0.01*a[i].l);
		// right
		R=lower_bound(mushroom.begin(),mushroom.end(),mp(a[i].x+a[i].h,10000))-mushroom.begin();
		L=lower_bound(mushroom.begin(),mushroom.end(),mp(a[i].x,10000))-mushroom.begin();
		if (L<R) f[L]*=(1.0-0.01*a[i].r), f[R]/=(1.0-0.01*a[i].r);
	}	
	double res=f[0]*mushroom[0].se;
	fr(i,1,m-1) f[i]*=f[i-1], res+=f[i]*mushroom[i].se;
	printf("%.9lf\n",res);
}