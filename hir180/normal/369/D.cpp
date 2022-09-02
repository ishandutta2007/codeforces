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
int n,k;  int num[3005],cnt=0;
int rui[3005]={},rui2[3005]={};
bool used[3005][3005]={};
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d%d",&n,&k);
	num[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
	}
	for(int i=1;i<=n;i++)
	{
		rui[i]=rui[i-1]+(num[i]==100);
		rui2[i]=rui2[i-1]+!num[i];
	}
	queue<P>que; que.push(mp(0,1));
	for(int i=0;i<=k;i++)
	{
		int s=que.size();
	while(s--)
	{
		P p=que.front(); que.pop();
		if(used[p.f][p.s]) continue; //cout << p.f << " " << p.s << endl;
		cnt++;
		used[p.f][p.s]=true;
		if(p.s==n+1||!p.f&&p.s==n) continue;
		if(!p.f)
		{
			int x=rui[n]-rui[p.s];
			int y=rui2[n]-rui2[p.s];
			if(num[p.s] && y!=n-p.s)
			{
				que.push(mp(0,p.s+2));
			}
			if(num[p.s] && !x)
			{
				que.push(mp(p.s,p.s+2));
			}
			if(num[p.s]!=100 && y!=n-p.s)
			{
				que.push(mp(0,p.s+1));
			}
		}
		else
		{
			int x=rui[n]-rui[p.s-1];
			int y=rui2[n]-rui2[p.s-1];
			if(num[p.f] && y!=n-p.s+1)
			{
				que.push(mp(0,p.s+1));
			}
			if(num[p.f] && !x)
			{
				que.push(mp(p.f,p.s+1));
			}
			if(num[p.f]!=100 && y!=n-p.s+1)
			{
				que.push(mp(0,p.s));
			}
		}
	}
	}
	printf("%d\n",cnt);
}