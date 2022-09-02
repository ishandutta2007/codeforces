//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
int find(int x,int y)
{
	return (x%2)*2+(y%2);
}
ll bit[1025][1025][4]={};

void xo(int i,int j,ll v)
{
	int bel=find(i,j);
	for(int x=i;x<=1024;x+=x&-x)
	{
		for(int y=j;y<=1024;y+=y&-y)
		{
			bit[x][y][bel]^=v;
		}
	}
}
ll calc(int i,int j)
{
	int bel=find(i,j);
	ll res=0LL;
	for(int x=i;x>=1;x-=x&-x)
	{
		for(int y=j;y>=1;y-=y&-y)
		{
			res^=bit[x][y][bel];
		}
	}
	return res;
}
int main()
{
	srand((unsigned int)time(NULL));
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int q;  scanf("%d",&q);
		if(q==2)
		{
			int x,y,w,z; ll v;
			scanf("%d%d%d%d%lld",&x,&y,&w,&z,&v);
			xo(x,y,v);
			xo(x,z+1,v);
			xo(w+1,y,v);
			xo(w+1,z+1,v);
		}
		else
		{
			int x,y,w,z;
			scanf("%d%d%d%d",&x,&y,&w,&z);
			ll ret=0LL;
			ret^=calc(w,z);
			ret^=calc(x-1,z);
			ret^=calc(w,y-1);
			ret^=calc(x-1,y-1);
			printf("%lld\n",ret);
		}
	}
}