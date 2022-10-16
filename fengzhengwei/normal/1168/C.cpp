#include<bits/stdc++.h>
#define ll long long
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
const int xx=3e5+5;//218 
int a[xx];
vector<pair<int,int> >v[xx];
int f[xx][19];// 
int to[19];
int main(){
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	memset(f,0x3f,sizeof(f));
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<19;j++)
		{
			for(int k=0;k<19;k++)
			if(a[i]&(1<<k))f[i][j]=min(f[i][j],f[to[k]][j]),f[i][k]=i;
		}
		for(int k=0;k<19;k++)
		if(a[i]&(1<<k))to[k]=i;
	}
	while(m--)
	{
		int l,r;
		l=read();
		r=read();
		int vis=0;
		for(int j=0;j<19;j++)
		{
			if(a[r]&(1<<j))
			{
				if(f[l][j]<=r){vis=1;break;}
			}
		}
		if(vis)puts("Shi");
		else puts("Fou");
	}
	return 0;
}