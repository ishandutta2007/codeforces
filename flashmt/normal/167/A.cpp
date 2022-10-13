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
using namespace std;

int main()
{
	int n,a,d;
	double last=-1;
	cin >> n >> a >> d;
	rep(i,n)
	{
		int t,v;
		cin >> t >> v;
		double u=1.0*v/a,dist=0.5*a*u*u;
		if (dist>=d) u=sqrt(2.0*d/a);
		else u+=(1.0*d-dist)/v;
		u=max(u+t,last);
		printf("%.9lf\n",u);
		last=u;
	}
}