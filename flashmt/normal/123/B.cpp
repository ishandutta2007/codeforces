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
#define maxN 1
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define oo 1000111222
using namespace std;

long long a,b,x,y,xx,yy,ans;

long long nextFrom(long long x,long long z)
{
	if (x>=0) return x+z-x%z;
	return x+(-x)%z;
}

long long lastFrom(long long x,long long z)
{
	if (x>=0) return x-x%z;
	return x-z+(-x)%z;
}

int main()
{
	cin >> a >> b >> x >> y >> xx >> yy;
	long long s=x+y, t=x-y, ss=xx+yy, tt=xx-yy;
	if (s>ss) swap(s,ss);
	ans=max(0LL,(lastFrom(ss,a*2)-nextFrom(s,a*2))/2/a+1);
	if (t>tt) swap(t,tt);
	ans=max(ans,max(0LL,(lastFrom(tt,b*2)-nextFrom(t,b*2))/2/b+1));
	cout << ans << endl;
}