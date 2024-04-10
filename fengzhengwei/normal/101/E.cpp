#include<bits/stdc++.h>
#define ll long long
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
char st;
int n,m,p;
int f[2][20005];//int 
int a[20005],b[20005];
bitset<20001>bit[10001];
vector<char>v;
int U,V;
void dg(int x,int y)
{
	if(x<10000)return U=x,V=y,void();
	if(bit[x-10000][y])
	{
		dg(x,y-1);
		v.push_back('S');
	}
	else 
	{
		dg(x-1,y);
		v.push_back('C');
	}
}
void dg2(int x,int y)
{
//	cout<<x<<" "<<y<<"\n";
	if(!x||!y)return ;
	if(bit[x][y])
	{
		dg2(x,y-1);
		if(y!=1)cout<<"S";
	}
	else 
	{
		dg2(x-1,y);
		if(x!=1)cout<<"C";
	}
}
char ed;
signed main(){
//	freopen("a.in","r",stdin);
//	cout<<(&st-&ed)/1024/1024<<'\n';
	n=read(),m=read(),p=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)b[i]=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int I=i&1;
			if(i>=10000)
			{
				if(f[I^1][j]>f[I][j-1]||(f[I^1][j]==f[I][j-1]&&i!=1))bit[i-10000][j]=0;
				else bit[i-10000][j]=1;
			}
			f[I][j]=max(f[I^1][j],f[I][j-1])+(a[i]+b[j])%p;
			f[I^1][j]=0;
//			cout<<i<<" "<<j<<" "<<f[I][j]<<'\n';
		}
	}
	cout<<f[n&1][m]<<"\n";
	dg(n,m);
//	puts("qweqe")
	memset(f,0,sizeof(f));
	for(int i=1;i<=min(n,10000-1);i++)
	{
		for(int j=1;j<=m;j++)
		{
			int I=i&1;
			if(f[I^1][j]>f[I][j-1]||(f[I^1][j]==f[I][j-1]&&i!=1))bit[i][j]=0;
			else bit[i][j]=1;
			f[I][j]=max(f[I^1][j],f[I][j-1])+(a[i]+b[j])%p;
			f[I^1][j]=0;
		}
	}
	dg2(U,V);
	for(auto it:v)cout<<it;
	return 0;
}