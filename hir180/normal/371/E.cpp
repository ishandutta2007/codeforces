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
ll rui[300005]={};
ll dp[300005]={};
ll za[300005];
int id[300005];
int n,k;
bool comp(int a,int b)
{
	return za[a]<za[b];
}
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&za[i]);
		id[i]=i;
	}
	sort(id+1,id+n+1,comp);
	sort(za+1,za+n+1);
	for(int i=1;i<=n;i++)
	{
		rui[i]=rui[i-1]+za[i];
	}
	scanf("%d",&k);
	dp[1]=0;
	ll ret=0;
	int beg=1;
	for(int i=2;i<=n-k+1;i++)
	{
		ll v=rui[i+k-2]-rui[i-1];
		v-=za[i-1]*(k-1);
		ll v2=rui[i+k-2]-rui[i-1];
		v2=za[i+k-1]*(k-1)-v2;
		dp[i]=v2-v+dp[i-1];
		if(ret>dp[i])
		{
			ret=dp[i]; beg=i;
		}
	}
	for(int i=beg;i<beg+k;i++)
	{
		printf("%d%c",id[i],i==beg+k-1?'\n':' ');
	}
}