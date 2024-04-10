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
char s[4000005],ret[4000005];
int m,n,x[5005],y[5005];
int seg[(1<<23)+5];
int par[4000005];
void update(int k,int l,int r)
{
	seg[k]=r-l+1;
	if(l!=r)
	{
		update(k*2,l,(l+r)/2);
		update(k*2+1,(l+r)/2+1,r);
	}
}
int make(int k,int l,int r,int v)
{
	seg[k]--;
	if(l==r) return l;
	if(seg[k*2]>=v) return make(k*2,l,(l+r)/2,v);
	else return make(k*2+1,(l+r)/2+1,r,v-seg[k*2]);
}
int get(int k,int l,int r,int v)
{
	if(l==r) return l;
	if(seg[k*2]>=v) return get(k*2,l,(l+r)/2,v);
	else return get(k*2+1,(l+r)/2+1,r,v-seg[k*2]);
}
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%s %d %d",s+1,&m,&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	update(1,1,m);
	for(int i=n;i>=1;i--)
	{
		if(y[i]>seg[1]) continue;
		int cur=x[i]+1>y[i]?x[i]:x[i]+1;
		int len=y[i]-x[i]+1;
		for(int j=1;j<=len && 1+y[i]<=seg[1];j++)
		{
			int point=make(1,1,m,1+y[i]);
			par[point]=get(1,1,m,cur);
			cur+=2; if(cur>y[i]) cur=x[i];
		}
	}
	for(int i=1,cnt=1;i<=m;i++)
	{
		if(par[i]) ret[i]=ret[par[i]];
		else ret[i]=s[cnt++];
	}
	printf("%s\n",ret+1);
}