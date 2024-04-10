#include<bits/stdc++.h>
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m;
int cnt;
int vis[1000005];
int to[500005][20];//17 
int jl[500005][20];
int Log2[500005];
int tmax[500005];
int main(){
//	freopen("a.out","w",stdout);
	n=read();m=read();
	Log2[1]=0;
	for(int i=2;i<=n;i++)Log2[i]=Log2[i-1]+((i&(-i))==i);
	for(int i=1;i<=n;i++)
	{
		int a,b;
		a=read();
		b=read();
		tmax[a]=max(tmax[a],b);
	}
	to[0][0]=tmax[0];
//	cout<<"qweqe"<<endl;
	for(int i=1;i<=500000;i++)
	{
		tmax[i]=max(tmax[i],tmax[i-1]);
		to[i][0]=tmax[i];
	}
	for(int i=1;i<=19;i++)
	{
		for(int j=0;j<=500000;j++)
		{
			to[j][i]=to[to[j][i-1]][i-1];
		}
	}
	while(m--)
	{
		int l,r;
		l=read();
		r=read();
		int ans=0;
		for(int j=19;j>=0;j--)
		{
			if(to[l][j]<r)
			{
				l=to[l][j];
				ans+=(1<<j);
			}
		}
		if(to[l][0]<r)
		{
			puts("-1");
			continue;
		}
		cout<<ans+1<<endl;
	}
	return 0;
}