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

int get(int x,int dx,int maxX)
{
	if (!dx) return oo;
	if (dx<0) return (1-x)/dx;
	return (maxX-x)/dx;
}

int main()
{
	int n,m,x,y,k,dx,dy;
	long long ans=0;
	cin >> m >> n >> x >> y >> k;
	while (k--)
	{
		cin >> dx >> dy;
		int X=get(x,dx,m),Y=get(y,dy,n);
		ans+=min(X,Y);
		x+=dx*min(X,Y); y+=dy*min(X,Y);
	}
	cout << ans << endl;
}