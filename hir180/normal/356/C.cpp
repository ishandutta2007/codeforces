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
int num[5],n,sum=0,x,ret=INF;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		sum+=x;
		num[x]++;
	}
	for(int i=0;i<=sum/3;i++)
	{
		if((sum-i*3)%4!=0) continue;
		int val[5]={};
		val[3]=i;
		val[4]=(sum-i*3)/4;
		val[0]=n-val[3]-val[4];
		int res=0;
		P x[5]; P y[5];
		x[0]=mp(0,val[0]-1);
		x[1]=x[2]=mp(1,-1);
		x[3]=mp(val[0],val[0]+val[3]-1);
		x[4]=mp(val[0]+val[3],val[0]+val[3]+val[4]-1);
		y[0]=mp(0,num[0]-1);
		y[1]=mp(num[0],num[0]+num[1]-1);
		y[2]=mp(num[0]+num[1],num[0]+num[1]+num[2]-1);
		y[3]=mp(num[0]+num[1]+num[2],num[0]+num[1]+num[2]+num[3]-1);
		y[4]=mp(num[0]+num[1]+num[2]+num[3],num[0]+num[1]+num[2]+num[3]+num[4]-1);

		for(int j=0;j<=4;j++)
		{
			for(int k=0;k<=4;k++)
			{
				res+=abs(j-k)*max(0,min(x[j].s,y[k].s)-max(x[j].f,y[k].f)+1);
			}
		}
		ret=min(ret,res);
	}
	printf("%d\n",ret/2>n?-1:ret/2);
}