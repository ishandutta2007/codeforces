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
#define INF 2000000000
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
int bit[(1<<20)+1];
int f(int x){ return x&-x;}
void  add(int i,int x)
{
	for(;i<=(1<<20);i+=f(i)) bit[i]+=x;
}
int  sum(int i)
{
	int res=0;
	for(;i>=1;i-=f(i)) res+=bit[i];
	return res;
}
int ret[300005];
vector<int>seg[1000005];
vector<P>query[1000005];
int main()
{
	srand((unsigned int)time(NULL));
	int n,m; scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int x,y; scanf("%d %d",&x,&y);
		seg[y].pb(x);
	}
	for(int i=0;i<m;i++)
	{
		int cnt,x; scanf("%d",&cnt);
		vector<int>hoz;
		hoz.pb(0);
		for(int j=0;j<cnt;j++)
		{
			scanf("%d",&x);
			hoz.pb(x);
		}
		hoz.pb(1000001);
		for(int j=1;j<hoz.size();j++)
		{
			int lb=hoz[j-1]+1;
			int ub=hoz[j]-1;
			query[ub].pb(mp(lb,i));
		}
	}
	for(int i=1;i<=1000000;i++)
	{
		for(int j=0;j<seg[i].size();j++) add(seg[i][j],1);
		for(int j=0;j<query[i].size();j++)
		{
			ret[query[i][j].s]+=(sum((1<<20))-sum(query[i][j].f-1));
		}
	}
	for(int i=0;i<m;i++) printf("%d\n",n-ret[i]);
}