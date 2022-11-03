#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int mod=1e9+7;
int n,m,a[5555],b[5555],c[5555],x,y,cr,mx,ans,xx,yy,zz,crt;
vector<pair<int,int> > v[5555];
int eval(int xp)//[0,xp],[xp+1,n]
{
	int res=0;
	for (int i=1;i<=n;i++)
	{
		xx=yy=zz=0;
		for (int j=0;j<v[i].size();j++)
		{
			x=v[i][j].first;y=v[i][j].second;
			if (x<=xp) xx++;
			if (y>xp) yy++;
			if (x<=xp && y>xp) zz++;
		}
		if (xx==1 && yy==1 && zz==1)
		{
			res++;
		}
		else if (xx && yy) res+=2;
		else if (xx || yy) res++;
	}
	return res;
}
int calc1(int xp)//[0,xp],[xp+1,n]
{
	int r1=0,r2=1;
	for (int i=1;i<=n;i++)
	{
		xx=yy=zz=0;
		for (int j=0;j<v[i].size();j++)
		{
			x=v[i][j].first;y=v[i][j].second;
			if (x<=xp) xx++;
			if (y>xp) yy++;
			if (x<=xp && y>xp) zz++;
		}
		if (xx==1 && yy==1 && zz==1)
		{
			r1++;r2=(r2+r2)%mod;
		}
		else if (xx && yy) 
		{
			r1+=2;r2=1ll*r2*(xx*yy-zz)%mod;
		}
		else if (xx || yy)
		{
			r1++;r2=1ll*r2*(xx^yy)%mod;
		}
	}
	if (r1==mx) return r2;
	return 0;
}
int calc2(int xp)//[0,xp-1],[xp+1,n]
{
	int r1=0,r2=1;
	for (int i=1;i<=n;i++)
	{
		xx=yy=zz=0;
		for (int j=0;j<v[i].size();j++)
		{
			x=v[i][j].first;y=v[i][j].second;
			if (x<xp) xx++;
			if (y>xp) yy++;
			if (x<xp && y>xp) zz++;
		}
		if (xx==1 && yy==1 && zz==1)
		{
			r1++;r2=(r2+r2)%mod;
		}
		else if (xx && yy) 
		{
			r1+=2;r2=1ll*r2*(xx*yy-zz)%mod;
		}
		else if (xx || yy)
		{
			r1++;r2=1ll*r2*(xx^yy)%mod;
		}
	}
	if (r1==mx) return r2;
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&b[i],&c[i]);
	}
	for (int i=1;i<=m;i++)
	{
		cr=c[i];x=n+1;y=0;
		for (int j=1;j<=n;j++)
		{
			if (a[j]==b[i]) 
			{
				cr--;
				if (!cr) 
				{
					x=j;
					break;
				}
			}
		}
		cr=c[i];
		for (int j=n;j>=1;j--)
		{
			if (a[j]==b[i]) 
			{
				cr--;
				if (!cr) 
				{
					y=j;
					break;
				}
			}
		}
		v[b[i]].push_back(make_pair(x,y));
	}
	for (int i=0;i<=n;i++)
	{
		mx=max(mx,eval(i));
	}
	for (int i=0;i<=n;i++)
	{
		ans=(ans+calc1(i))%mod;
	}
	for (int i=1;i<=n;i++)
	{
		ans=(ans-calc2(i))%mod;
	}
	printf("%d %d\n",mx,(ans+mod)%mod);
	return Accepted;
}