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
int rui[10000005];
int rev[10000005];
int v[10000005];
int pl[10000005]={};
int s[1000005];
int n;
int max_v;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x; scanf("%d",&x);
		rev[x]=i;
		v[x]++;
		s[i]=x;
		max_v=max(max_v,x);
	}
	for(int i=2;i*i<=max_v;i++)
	{
		int beg=i;
		while(beg<=max_v)
		{
			if(v[beg] && s[rev[beg]]%i==0)
			{
				while(s[rev[beg]]%i==0)  s[rev[beg]]/=i;
				pl[i]+=v[beg];
			}
			beg+=i;
		}
	}
	for(int i=1;i<=max_v;i++)
	{
		if(!v[i]) continue;
		if(s[rev[i]]!=1)
		{
			pl[s[rev[i]]]+=v[i];
		}
	}
	for(int i=1;i<=max_v;i++)
	{
		pl[i]=pl[i]+pl[i-1];
		
	}
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int p,q; scanf("%d %d",&p,&q);
		if(p>max_v) puts("0");
		else
		{
			q=min(q,max_v);
			printf("%d\n",pl[q]-pl[p-1]);
		}
	}
}