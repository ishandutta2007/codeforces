//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//HIR180
//IOI2014dN
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
int v[100005];
bool ex[100005][20];
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&v[i]);
	}
	ll ret=0LL;
	for(int bit=0;bit<20;bit++)
	{
		ll len=0;
		for(int i=0;i<n;i++)
		{
			if(((v[i]>>bit)&1))
			{
				ex[i][bit]=true; len++;
			}
			else
			{
				ret+=len*(len+1LL)/2LL*(1LL<<bit);
				len=0;
			}
		}
		ret+=len*(len+1LL)/2LL*(1LL<<bit);
		len=0;
	}
	for(int i=0;i<q;i++)
	{
		int pos,val; scanf("%d %d",&pos,&val); --pos;
		for(int bit=0;bit<20;bit++)
		{
			if( ex[pos][bit] == ((val>>bit)&1) ) continue;
			ex[pos][bit] = ((val>>bit)&1);
			int prev=pos-1;
			int nxt=pos+1;
			ll zen=0,go=0;
			while(prev>=0 && ex[prev][bit]) prev--,zen++;
			while(nxt<n && ex[nxt][bit]) nxt++,go++;
			if(ex[pos][bit])
			{
				ret+=((zen+go+1)*(zen+go+2)-(zen)*(zen+1)-(go)*(go+1))/2LL*(1LL<<bit);
			}
			else
			{
				ret-=((zen+go+1)*(zen+go+2)-(zen)*(zen+1)-(go)*(go+1))/2LL*(1LL<<bit);
			}
		}
		cout << ret << endl;
	}
}