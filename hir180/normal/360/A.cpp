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
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
int least[5005];
int val[5005];
vector<P2>vec;
int main()
{
	srand((unsigned int)time(NULL));
	int n,m;scanf("%d%d",&n,&m);
	fill(least,least+5005,INF);
	for(int i=1;i<=m;i++)
	{
		int x; scanf("%d",&x);int l,r,v;
		if(x==1)
		{
			scanf("%d%d%d",&l,&r,&v);
			for(int j=l;j<=r;j++) val[j]+=v;
		}
		else
		{
			scanf("%d%d%d",&l,&r,&v);
			for(int j=l;j<=r;j++)
			{
				least[j]=min(least[j],v-val[j]);
			}
		}
		vec.pb(mp(mp(x,l),mp(r,v)));
	}//for(int i=1;i<=n;i++) printf("%d%c",least[i],i==n?'\n':' ');
	memset(val,0,sizeof(val));
	for(int i=0;i<m;i++)
	{
		int x=vec[i].f.f; int l=vec[i].f.s;
		int r=vec[i].s.f; int v=vec[i].s.s;
		if(x==1)
		{
			scanf("%d%d%d",&l,&r,&v);
			for(int j=l;j<=r;j++) val[j]+=v;
		}
		else
		{
			bool ok=false;
			for(int j=l;j<=r;j++)
			{
				if(val[j]+least[j]>v){ ok=0; break;}
				if(val[j]+least[j]==v) ok=1;
			}
			if(!ok)
			{
				puts("NO"); return 0;
			}
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++) printf("%d%c",least[i],i==n?'\n':' ');
}