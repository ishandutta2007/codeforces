#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
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
const int xx=55;
int f[xx][xx];
ll g[xx][xx][xx];
// iabmaxcmindc,d 
int cr[xx][xx][xx];//imxcmnd 
int Mx[xx],Mn[xx],n,m;
struct pr{int x,y;pr(int a,int b):x(a),y(b){}pr(){}};//id 
bool operator <(pr a,pr b){return a.y==b.y?a.x<b.x:a.y<b.y;}
int main(){
	n=read(),m=read();
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read(),c=read();
		f[a][b]=min(f[a][b],c);
		f[b][a]=min(f[b][a],c);
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	}
	int g1=read(),g2=read(),s1=read(),s2=read();
	for(int i=1;i<=n;i++)
	{
		Mx[i]=-1e9,Mn[i]=1e9;
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			Mx[i]=max(Mx[i],f[i][j]);
			Mn[i]=min(Mn[i],f[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(j==k||i==j||i==k)continue;
				for(int s=1;s<=n;s++)
				{
					if(s==i)continue;
					if(pr(i,f[i][s])<pr(k,Mx[k])&&pr(j,Mn[j])<pr(i,f[i][s])){cr[i][j][k]=1;break;}
				}
			}
		}
	}
	ll ans=0;
	for(int j=1;j<=n;j++)
	{
		for(int k=1;k<=n;k++)
		{
			if(j==k)continue;
			// 
			memset(g,0,sizeof(g));
			g[0][0][0]=1;
			for(int i=0;i<n;i++)
			{
				for(int a=0;a<=i;a++)
				{
					for(int b=0;b<=i-a;b++)
					{
						if(i+1==j)
						{
							g[i+1][a+1][b]+=g[i][a][b];
							continue;
						}
						if(i+1==k)
						{
							g[i+1][a][b+1]+=g[i][a][b];
							continue;
						}
						if(cr[i+1][j][k])g[i+1][a][b]+=g[i][a][b];
						if(pr(i+1,Mn[i+1])<pr(j,Mn[j]))g[i+1][a+1][b]+=g[i][a][b];
						if(pr(k,Mx[k])<pr(i+1,Mx[i+1]))g[i+1][a][b+1]+=g[i][a][b];
					}
				}
			}
			for(int a=g1;a<=g2;a++)
				for(int b=n-a-s2;b<=n-a-s1;b++)
					ans+=g[n][a][b];
		}
	}
	cout<<ans<<"\n";
	return 0;
}