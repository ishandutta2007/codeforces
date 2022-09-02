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
int gr[100005];
bool out[(1<<20)]={};
int cnt[21];
int main()
{
	srand((unsigned int)time(NULL));
	int n,m,d; scanf("%d%d%d",&n,&m,&d);
	for(int i=0;i<m;i++)
	{
		int cnt; scanf("%d",&cnt);
		for(int j=0;j<cnt;j++)
		{
			int x; scanf("%d",&x);
			gr[x]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cnt[gr[i]]++;
		if(i>=d+1)
		{
			cnt[gr[i-d]]--;
		}
		if(i>=d)
		{
			int mask=0;
			for(int j=0;j<m;j++) if(cnt[j]) mask^=(1<<j);
			out[mask]=true;
		}
	}
	//
	for(int i=0;i<(1<<m);i++) if(out[i]) for(int j=0;j<m;j++) out[i|(1<<j)]=true;
	int ret=0;
	for(int i=0;i<(1<<m);i++)
	{
		if(!out[i])
		{
			ret=max(ret,__builtin_popcount(i));
		}
	}
	printf("%d\n",m-ret);
}