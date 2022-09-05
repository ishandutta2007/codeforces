/*
	Author  : JZdavid
	From    : CF
	Problem : 454C
	Time    : 2014/8/2
	Verdict : Accepting
*/
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
typedef long long ll;
const int INF=1<<28;
const long long LINF=1ll<<61;
double kissme(double x,int y)
{
	double base=x,ans=1.0;
	while(y>0)
	{
		if(y&1)ans*=1.0*base;
		y=y/2;
		base=1.0*base*base;
	}
	return ans;
}
int n,m;
double dp[100111];
int main()
{
	scanf("%d%d",&n,&m);
	double sum=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=kissme(1.0*i/n,m)-sum;
		sum+=dp[i];
	}
	double ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=1.0*dp[i]*double(i);
	}
	printf("%.10lf",ans);
// 	system("pause");
	return 0;
}