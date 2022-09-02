//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//HIR180
//IOI2014N
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
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int num[1005][1005];
ll tate[1005];
ll yoko[1005];
int main()
{
	srand((unsigned int)time(NULL));
	int n,m; cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin >> num[i][j] ;
			tate[j]+=1LL*num[i][j];
			yoko[i]+=1LL*num[i][j];
		}
	}
	int x,y;
	ll minx=1e18;
	ll miny=1e18;
	for(int i=0;i<=m;i++)
	{
		ll sum=0LL;
		for(int j=1;j<=m;j++)
		{
			int f=j*2-1;
			f=abs(f-i*2);
			f*=2;
			sum+=1LL*f*f*tate[j];
		}
		if(minx>sum)
		{
			minx=sum;
			x=i;
		}
	}
	for(int i=0;i<=n;i++)
	{
		ll sum=0LL;
		for(int j=1;j<=n;j++)
		{
			int f=j*2-1;
			f=abs(f-i*2);
			f*=2;
			sum+=1LL*f*f*yoko[j];
		}
		if(miny>sum)
		{
			miny=sum;
			y=i;
		}
	}
	cout << minx+miny << endl << y << " " << x << endl;
}