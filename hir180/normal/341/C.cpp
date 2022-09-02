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
#define mod 1000000007
//#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
int v[2005],n,dp[2005][2005];
bool pos[2005],num[2005];
int f(int x,int y)
{
	int &res=dp[x][y];
	if(res) return res;
	if(!x) return v[y];
	if(x>=2)
	{
		res=(res+(1LL*f(x-2,y+1)*(x-1))%mod)%mod;
	}
	res=(res+(1LL*f(x-1,y)*y)%mod)%mod;
	return res;
}
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)
	{
		scanf("%d",&x);
		if(x!=-1)
		{
			pos[i]=true;
			num[x]=true;
		}
	}
	int cnta=0,cntb=0;
	for(int i=1;i<=n;i++)
	{
		if(!pos[i]&&!num[i]) cnta++;
		else if(!pos[i]) cntb++;
	}
	v[0]=1;
	for(int i=1;i<=n;i++) v[i]=(int)(1LL*v[i-1]*i%mod);
	printf("%d\n",f(cnta,cntb));
}