#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define ll long long
#define N 1010
using namespace std;
ll ox[N],oy[N];
inline ll dis(ll x0,ll y0,ll x1,ll y1){return abs(x1-x0)+abs(y1-y0);}
int main()
{
	ll ax,bx,ay,by;
	scanf("%lld%lld%lld%lld%lld%lld",&ox[0],&oy[0],&ax,&ay,&bx,&by);
	ll sx,sy,t;
	scanf("%lld%lld%lld",&sx,&sy,&t);
	int tot=0;
	for(tot=1;;tot++)
	{
		ox[tot]=ox[tot-1]*ax+bx,oy[tot]=oy[tot-1]*ay+by;
		if(ox[tot]>=4e16 || oy[tot]>=4e16) break;
	}
	int ans=0;
	for(int i=0;i<=tot;i++)
	{
		ll r=t-dis(ox[i],oy[i],sx,sy);
		if(r<0) continue;
		int res=1;
		for(int j=i+1;j<=tot;j++)
		{
			if(r>=dis(ox[j],oy[j],ox[j-1],oy[j-1]))
			{
				r-=dis(ox[j],oy[j],ox[j-1],oy[j-1]);
				res++;
			}
			else break;
		}
		ans=max(ans,res);
		r=t-dis(ox[i],oy[i],sx,sy),res=1;
		for(int j=i-1;j>=0;j--)
		{
			if(r>=dis(ox[j],oy[j],ox[j+1],oy[j+1]))
			{
				r-=dis(ox[j],oy[j],ox[j+1],oy[j+1]);
				res++;
			}
			else break;
		}
		ans=max(ans,res);
	}
	printf("%d\n",ans);
	return 0;
}