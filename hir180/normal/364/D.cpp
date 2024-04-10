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
ll v[1000005];
ll a[50005];
int b[50005];ll ret=0;
double beg;
ll gcd(ll a,ll b) { if(a%b==0) return b; else return gcd(b,a%b);}
int main()
{
	beg=clock();
	srand((unsigned int)time(NULL));
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&v[i]);
	}
	while(clock()-beg<=3.5*CLOCKS_PER_SEC)
	{
		ll x=v[rand()*rand()%n];
		int id=0;
		for(ll i=1;i*i<=x;i++)
		{
			if(x%i==0)
			{
				a[id++]=i;
				if(i*i!=x)
				{
					a[id++]=x/i;
				}
			}
		}
		sort(a,a+id); memset(b,0,sizeof(b));
		if(id>20000) assert(0);
		for(int i=0;i<n;i++)
		{
			ll w=gcd(min(v[i],x),max(v[i],x));
			b[lower_bound(a,a+id,w)-a]++;
		}
		for(int i=0;i<id;i++)
		{
			int v=0;
			for(int j=i;j<id;j++)
			{
				if(a[j]%a[i]==0) v+=b[j];
			}
			if(v>=(n+1)/2) ret=max(ret,a[i]);
		}
	}
	printf("%lld\n",ret);
}