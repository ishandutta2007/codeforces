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
#include <bitset>
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
#define rng 30
int val[70005],must;
bitset<70005>dp[2405];
int sub=-1;
bitset<70005>dp2[rng+5];
bool make(int x,int rem)
{
	if(sub!=x/rng*rng)
	{
		sub=x/rng*rng;
		dp2[0]=dp[sub/rng];
		for(int j=0;j<rng-1;j++)
		{
			int v=sub+j;
			if(v==must)
			{
				//we must use it
				dp2[j+1]=(dp2[j]<<val[v]);
			}
			else
			{
				//we can use it
				dp2[j+1]=((dp2[j]<<val[v])|dp2[j]);
			}
		}
	}
	return dp2[x-sub][rem];

}
bool up[70005]={};
// we'll construct chain, so child node must be at most 1
int down[70005];
int main()
{
	srand((unsigned int)time(NULL));
	int n,s;
	scanf("%d %d",&n,&s);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&val[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(val[i]>val[must])
		{
			must=i;
		}
	}
	bitset<70005>bse;
	bse[0]=true;
	for(int i=0;i<=n;i++)
	{
		if(i%rng==0)
		{
			dp[i/rng]=bse;
		}
		if(i==n) break;
		if(i==must)
		{
			//we must use it
			bse<<=val[i];
		}
		else
		{
			//we can use it
			bse= ((bse<<val[i]) | bse);
		}
	}
	if(!make(n,s)) return puts("-1");
	up[must]=true;
	for(int i=n-1;i>=0;i--)
	{
		if(s<val[i]) continue;
		if(make(i,s-val[i]))
		{
			up[i]=true;
			s-=val[i];
		}
	}
	memset(down,-1,sizeof(down));
	vector<P>vec;
	for(int i=0;i<n;i++)
	{
		if(!up[i])
		{
			vec.pb(mp(val[i],i));
		}
	}
	sort(vec.begin(),vec.end());
	for(int i=1;i<vec.size();i++)
	{
		down[vec[i].s]=vec[i-1].s;
	}
	if(!vec.empty()) down[must]=vec[vec.size()-1].s;
	for(int i=0;i<n;i++)
	{
		if(down[i]==-1)
		{
			//no child node
			printf("%d %d\n",val[i],0);
		}
		else
		{
			printf("%d %d %d\n",val[i]-val[down[i]],1,down[i]+1);
		}
	}
}