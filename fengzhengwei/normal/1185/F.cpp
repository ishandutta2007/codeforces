#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e5+5;
int f[514][2],n,m,s[xx];
int g[514],num[514];
pair<int,int> t[514];
signed main(){
	for(int i=0;i<=513;i++)for(int j=0;j<=1;j++)f[i][j]=2147483647;
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		int t=read(),w=0;
		while(t--)w+=(1<<(read()-1));
		s[i]=w;
	}
	for(int i=1;i<=m;i++)
	{
		int val=read();
		int T=read(),w=0;
		while(T--)w+=(1<<(read()-1));
		for(int k=0;k<512;k++)
		{
			if(f[k][0]==2147483647)continue;
//			cout<<f[k][0]<<" "<<g[k]<<"\n";
			if(f[k|w][1]>f[k][0]+val)
			{
				f[k|w][1]=f[k][0]+val;
				t[k|w]=make_pair(g[k],i);
			}
		}
		if(f[w][0]>val)f[w][0]=val,g[w]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<512;j++)
			if((j&s[i])==s[i])num[j]++;
	}
	int mx=0;
	for(int j=0;j<512;j++)
		if(f[j][1]!=2147483647)mx=max(mx,num[j]);
	int mn=2147483647,id=0;
	for(int j=0;j<512;j++)
	{
		if(f[j][1]<mn&&num[j]==mx)
		{
			mn=f[j][1];
			id=j;
		}
	}
	cout<<t[id].first<<" "<<t[id].second<<"\n";
	
    return 0;
}