//IOI2014
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
int n,m;
struct BIT
{
	int bit[(1<<20)+5];
	int f(int x)
	{
		return x&-x;
	}
	void add(int i,int x)
	{
		for(int s=i;s<=(1<<20);s+=f(s)) bit[s]+=x;
	}
	int sum(int i)
	{
		int res=0;
		for(int s=i;s>0;s-=f(s)) res+=bit[s];
		return res;
	}
}bit,bitpre;
int num[1000005],zip[1000005];
bool used[1000005];
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d %d",&n,&m);
	int pre=0;
	for(int i=1;i<=n;i++) bit.add(i,1);
	memset(num,-1,sizeof(num));
	bool ok=true;
	int id=1;
	for(int i=0;i<m;i++)
	{
		int x,y; scanf("%d %d",&x,&y);
		if(y<=pre)
		{
			int lb=0,ub=n;
			//(lb,ub]
			while(ub-lb > 1)
			{
				int mid=(lb+ub)>>1;
				if(bitpre.sum(mid) >= pre-y+1) ub=mid;
				else lb=mid;
			}
			if(zip[ub]!=x)
			{
				ok=false; break;
			}
			zip[id++]=x;
			bitpre.add(ub,-1);
			bitpre.add(id-1,1); continue;
		}
		int lb=0,ub=n;
		//(lb,ub]
		while(ub-lb > 1)
		{
			int mid=(lb+ub)>>1;
			if(bit.sum(mid) >= y-pre) ub=mid;
			else lb=mid;
		}
		if(num[ub]!=-1 && num[ub]!=x)
		{
			ok=false; break;
		}
		if(used[x])
		{
			ok=false; break;
		}
		num[ub]=x;
		used[x]=true;
		bit.add(ub,-1);
		pre++;
		zip[id++]=x;
		bitpre.add(id-1,1);
	}
	if(!ok)
	{
		puts("-1");
	}
	else
	{
		vector<int>rem;
		for(int i=1;i<=n;i++) if(!used[i]) rem.pb(i);
		int id=0;
		for(int i=1;i<=n;i++) if(num[i] == -1) num[i]=rem[id++];
		for(int i=1;i<=n;i++) printf("%d ",num[i]); puts("");
	}
}