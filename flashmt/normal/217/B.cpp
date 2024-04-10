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

int calc(int n,int X,int x)
{
	if (!n) return X==1 && !x?0:oo;
	if (x==1) return X==n?max(0,n-2):oo;
	if (!x) return oo;
	return calc(n-X/x,x,X%x)+X/x-1;
}

void trace(int n,int X,int x,int &z)
{
	if (!n) return;
	if (x==1)
	{
		z=0;
		printf("T");
		if (n>1)
		{
			z=1;
			rep(i,n-1) printf("B");
		}
	}
	else
	{
		int zz;
		trace(n-X/x,x,X%x,zz);
		z=1-zz;
		rep(i,X/x) printf((z?"B":"T"));
	}
}

int main()
{
	int n,r,ans=oo,y;
	cin >> n >> r;
	
	if (n==1 && r==1)
	{
		cout << 0 << endl << "T" << endl;
		return 0;
	}
	
	fr(i,1,r-1) 
	{
		int x=calc(n,r,i);
		if (x<ans) ans=x, y=i;
	}
	
	if (ans==oo) puts("IMPOSSIBLE");
	else
	{
		cout << ans << endl;
		int z;
		trace(n,r,y,z);
	}
}