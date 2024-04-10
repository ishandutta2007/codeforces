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
int n,ox,x;
struct candy
{
	int t,h,m;
}cd[2111];
bool vis[2111];
int solve(int tp)
{
	x=ox;
	int cnt=0;
	memset(vis,0,sizeof(vis));
	while(true)
	{
		bool ok=0;
		int mxn=0,mx=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]&&cd[i].h<=x&&tp^1==cd[i].t)
			{
				if(cd[i].m>mx)
				{
					mxn=i;mx=cd[i].m;
					ok=1;
				}

			}
		}
		if(mxn!=0)
		{
			vis[mxn]=1;
			x+=cd[mxn].m;cnt++;
			tp^=1;
		}
		if(ok==0)break;
	}
	return cnt;
}
int main()
{
	scanf("%d%d",&n,&ox);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&cd[i].t,&cd[i].h,&cd[i].m);
	}
	printf("%d",max(solve(1),solve(0)));
// 	system("pause");
	return 0;
}