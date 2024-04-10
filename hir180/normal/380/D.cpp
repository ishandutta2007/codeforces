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
#define mod 1000000007
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
int know[100005]={};
ll k[100005];
int num[100005];
int n;
long long modpow(long long x,long long n)
{
	long long res=1;
	while(n>0)
	{
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll calc(int l,int r)
{
//cout<<l << " " << r << endl;
	//elements in [l,r] are all unknown
	if(know[l-1]==know[r])
	{
		return modpow(2LL,(ll)(r-l));
	}
	int beg=l;
	int en=r;
	while(!num[beg]) beg++;
	while(!num[en]) en--;
	if(beg==en && num[beg]==1)
	{
		ll up=k[r-l];
		ll down=k[beg-l]*k[r-beg]%mod;
		return (up*modpow(down,mod-2LL)%mod);
	}
	ll res=0LL;
	if(num[beg]>=num[en])
	{
		if(beg+num[beg]-1>=en && beg+num[beg]-1<=r)
		{
			ll up=k[r-l+1-num[beg]];
			ll down=k[beg-l]*k[r+1-beg-num[beg]]%mod;
			res+=((calc(beg+1,beg+num[beg]-1))*(up*modpow(down,mod-2LL)%mod))%mod;
			res%=mod;
		}
	}
	if(num[beg]<=num[en])
	{
		if(en-num[en]+1<=beg && en-num[en]+1>=l)
		{
			ll up=k[r-l+1-num[en]];
			ll down=k[r-en]*k[en-l+1-num[en]]%mod;
			res+=((calc(en-num[en]+1,en-1))*(up*modpow(down,mod-2LL)%mod))%mod;
			res%=mod;
		}
	}
	return res;
}
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
	}
	for(int i=1;i<=n;i++)
	{
		know[i]=know[i-1]+min(1,num[i]);
	}
	k[0]=1LL;
	for(int i=1;i<=n;i++)
	{
		k[i]=k[i-1]*1LL*i%mod;
	}
	printf("%lld\n",calc(1,n));
}