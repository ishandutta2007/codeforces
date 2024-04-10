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
int par[21][1000005];
int depth[1000005];
int calclca(int u,int v)
{
	if(depth[u]>depth[v]) swap(u,v);
	for(int i=0;i<=20;i++)
	{
		if((((depth[v]-depth[u])>>i)&1))
		{
			v=par[i][v];
		}
	}
	if(u==v) return u;
	for(int i=20;i>=0;i--)
	{
		if(par[i][u]!=par[i][v])
		{
			u=par[i][u]; v=par[i][v];
		}
	}
	return par[0][v];
}
int main()
{
	srand((unsigned int)time(NULL));
	int n;
	scanf("%d",&n);
	//memset(par,-1,sizeof(par));
	depth[1]=0;
	depth[2]=depth[3]=depth[4]=1;
	par[0][1]=-1;
	par[0][2]=par[0][3]=par[0][4]=1;
	for(int k=1;k<=4;k++)
	{
		for(int j=1;j<=20;j++)
		{
			if(par[j-1][k]<0) par[j][k]=-1;
			else par[j][k]=par[j-1][par[j-1][k]];
		}
	}
	int a=2,b=3,cur=2;
	for(int i=0;i<n;i++)
	{
		int v; scanf("%d",&v);
		depth[i*2+5]=depth[i*2+6]=depth[v]+1;
		par[0][i*2+5]=par[0][i*2+6]=v;
		for(int j=1;j<=20;j++)
		{
			if(par[j-1][i*2+5]<0) par[j][i*2+5]=par[j][i*2+6]=-1;
			par[j][i*2+5]=par[j][i*2+6]=par[j-1][par[j-1][i*2+5]];
		}//cout << a << " " << b << endl;
		int x=calclca(a,i*2+5); //cout << x << endl;
		int y=depth[a]+depth[i*2+5]-depth[x]*2;
		int z=calclca(b,i*2+5); //cout << z << endl;
		int w=depth[b]+depth[i*2+5]-depth[z]*2;
		if(max(y,w)<=cur);
		else if(y<w)
		{
			cur=w; a=i*2+5;
		}
		else
		{
			cur=y; b=i*2+5;
		}
		printf("%d\n",cur);
	}
}