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
#define sqr(x) ((x)*(x))
using namespace std;

int n;
vector < pii > a;
vector < pair<double,int> > angle;

double calcAngle(int x,int y,double mx,double my)
{
	return acos((1.0*x-mx)/sqrt(sqr(mx-x)+sqr(my-y)))*(y<my?-1:1);
}

int inside(int x,int y,double mx,double my)
{
	double theta=calcAngle(x,y,mx,my);
	int z=lower_bound(angle.begin(),angle.end(),mp(theta,-1))-angle.begin();
	if (z==n) z=0;
	int i=angle[z].se,j=angle[(z+n-1)%n].se;
	long long A=a[j].se-a[i].se,B=a[i].fi-a[j].fi,C=-A*a[i].fi-B*a[i].se;
	if (A*x+B*y+C==0) return 0;
	return (mx*A+my*B+C)*(1.0*A*x+1.0*B*y+C)>0;
}

int main()
{
	int m,x,y;
	long long sx=0,sy=0;
	cin >> n;
	rep(i,n) cin >> x >> y, a.pb(mp(x,y)), sx+=x, sy+=y;
	
	double mx=1.0*sx/n,my=1.0*sy/n;
	rep(i,n) angle.pb(mp(calcAngle(a[i].fi,a[i].se,mx,my),i));
	
	sort(all(angle));
	
	cin >> m;
	while (m--)
	{
		cin >> x >> y;
		if (!inside(x,y,mx,my))
		{
			puts("NO"); return 0;
		}
	}
	puts("YES");
}