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
typedef pair<long long,long long> PL;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 200000000000000LL
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
ll dp[150005][2]={};
int n,m;ll d;
ll sum=0LL;
struct firework
{
	int time;
	int pos;
	firework(){}
	firework(int time,int pos):time(time),pos(pos){}
}iv[305];
PL deq[150005];
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d %d %lld",&n,&m,&d);
	for(int i=0;i<m;i++)
	{
		int a,b,t; scanf("%d %d %d",&a,&b,&t);
		iv[i]=firework(t,a);
		sum+=1LL*b;
	}
	int cur=0;int nxt=1;int prev=1;
	int s=0,t=0;
	for(int i=0;i<m;i++)
	{
		ll dis=iv[i].time-prev; dis*=d;
		prev=iv[i].time;
		for(int j=1;j<=n;j++) dp[j][nxt]=INF;
		//left to right
		//[s,t)
		s=0,t=0;
		for(int j=1;j<=n;j++)
		{
			while(s<t&&deq[t-1].f>=dp[j][cur]) t--;
			deq[t++]=mp(dp[j][cur],j);
			dp[j][nxt]=deq[s].f+abs(iv[i].pos-j);
			if(deq[s].s==j-dis) s++;
		}
		//right to left
		//[s,t)
		s=0,t=0;
		for(int j=n;j>=1;j--)
		{
			while(s<t&&deq[t-1].f>=dp[j][cur]) t--;
			deq[t++]=mp(dp[j][cur],j);
			dp[j][nxt]=min(dp[j][nxt],deq[s].f+abs(iv[i].pos-j));
			if(deq[s].s==j+dis) s++;
		} 
		swap(cur,nxt);
	}
	ll gen=INF;
	for(int i=1;i<=n;i++) gen=min(gen,dp[i][cur]);
	printf("%lld\n",sum-gen);
}