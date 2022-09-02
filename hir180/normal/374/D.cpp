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
bool ex[1000005]={};
int num[1000005],val[1000005];
int bit[(1<<20)+1];
void add(int i,int x)
{
	while(i<=(1<<20))
	{
		bit[i]+=x; i += i&-i;
	}
}
int sum(int i)
{
	int res=0;
	while(i>=1)
	{
		res+=bit[i]; i -= i&-i;
	}
	return res;
}
int main()
{
	srand((unsigned int)time(NULL));
	int n,m; scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&num[i]);
	}
	int id=1;
	for(int i=0;i<n;i++)
	{
		int x; scanf("%d",&x);
		if(x!=-1)
		{
			add(id,1);
			ex[id]=true;
			val[id++]=x;
		}
		else
		{
			vector<int>l;
			for(int j=0;j<m;j++)
			{
				int lb=0;
				int ub=n;
				//(lb,ub]
				while(ub-lb>1)
				{
					int mid=(lb+ub)/2;
					int x=sum(mid);
					if(x>=num[j]) ub=mid;
					else lb=mid;
				}
				if(!ex[ub]) break; l.pb(ub);
			}
			for(int j=0;j<l.size();j++) { ex[l[j]]=false; add(l[j],-1);}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(ex[i]) { cnt++; printf("%d",val[i]);}
	}
	if(!cnt)printf("Poor stack!");
	puts("");
}