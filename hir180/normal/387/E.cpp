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
int pos[1000005],pos2[1000005],x;
int bit[(1<<20)+1]={};
void add(int i,int x)
{
	while(i<=(1<<20)) bit[i]+=x,i+=i&-i;
}
int sum(int i)
{
	int res=0;
	while(i>0) res+=bit[i],i-=i&-i;
	return res;
}
int calc(int lb,int ub) { return sum(ub)-sum(lb-1);}
int main()
{
	srand((unsigned int)time(NULL));
	int n,k; scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x); pos[x]=i;
	}
	for(int j=1;j<=k;j++)
	{
		scanf("%d",&x); pos2[x]=-1;
	}
	//small element to big element
	set<int>se; se.insert(0); se.insert(n+1);
	ll ret=0LL;
	for(int i=1;i<=n;i++)
	{
		if(pos2[i]==-1)
		{
			se.insert(pos[i]);
		}
		else
		{
			__typeof__(se.begin()) x=(se.upper_bound(pos[i]));
			__typeof__(x) y=--x; x++; //cout << *x << " " << *y << endl;
			ret+=(*x)-(*y)-1-calc((*y)+1,(*x)-1);
			add(pos[i],1);
		}
	}
	printf("%lld%c",ret,10);
}