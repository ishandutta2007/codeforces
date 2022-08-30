//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//HIR180
//IOI2014N
//O(min(N,M)^2log NM)
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
char f[2505][2505];
int v[2505][2505]={};
int rui[2505][2505]={};
int n,m,k;
int get(int a,int b,int c,int d)
{
	return (rui[b][d]-rui[b][c-1]-rui[a-1][d]+rui[a-1][c-1]);
}
ll calc(int l1,int r1,int l2,int r2)
{
	if(l1==r1 && l2==r2) return (v[l1][l2]==k);
	if(l1>r1 || l2>r2) return 0;
	ll ret=0LL;
	if(r1-l1>r2-l2)
	{
		int mid=(l1+r1)>>1;
		int a[7],b[7];
		for(int i=l2;i<=r2;i++)
		{
			for(int j=0;j<=k;j++)
			{
				a[j]=mid-l1+1;
				b[j]=r1-mid;
			}
			for(int j=i;j>=l2;j--)
			{
				for(int s=0;s<=k;s++) while(a[s] && get(mid-a[s]+1,mid,j,i)>s) a[s]--;
				for(int s=0;s<=k;s++) while(b[s] && get(mid+1,mid+b[s],j,i)>s) b[s]--;
				for(int s=0;s<=k;s++)
				{
					ret+=(1LL*(a[s]-(s?a[s-1]:0))*(b[k-s]-((k-s)?b[k-s-1]:0)));
				}
			}
		}
		ret+=calc(l1,mid,l2,r2);
		ret+=calc(mid+1,r1,l2,r2);
		return ret;
	}
	else
	{
		int mid=(l2+r2)>>1;
		int a[7],b[7];
		for(int i=l1;i<=r1;i++)
		{
			for(int j=0;j<=k;j++)
			{
				a[j]=mid-l2+1;
				b[j]=r2-mid;
			}
			for(int j=i;j>=l1;j--)
			{
				for(int s=0;s<=k;s++) while(a[s] && get(j,i,mid-a[s]+1,mid)>s) a[s]--;
				for(int s=0;s<=k;s++) while(b[s] && get(j,i,mid+1,mid+b[s])>s) b[s]--;
				for(int s=0;s<=k;s++)
				{
					ret+=(1LL*(a[s]-(s?a[s-1]:0))*(b[k-s]-((k-s)?b[k-s-1]:0)));
				}
			}
		}
		ret+=calc(l1,r1,l2,mid);
		ret+=calc(l1,r1,mid+1,r2);
		return ret;
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%s",&f[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			v[i+1][j+1]=f[i][j]-'0';
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			rui[i][j]=rui[i-1][j]+rui[i][j-1]-rui[i-1][j-1]+v[i][j];
		}
	}
	printf("%lld\n",calc(1,n,1,m));
}