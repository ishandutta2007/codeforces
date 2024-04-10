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
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc(x%10+'0',0);
}
void wts(ll x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=505;
int n,m,k;
struct nod{dd a[605];}e[xx];
int is[xx],d[xx],id[xx],To[xx],vis[xx];
vector<int>v[xx];
dd f[xx][xx];
struct mat
{
	dd a[105][105];
	mat operator*(const mat&w)const
	{
		mat s;memset(s.a,0,sizeof(s.a));
		for(int i=1;i<=100;i++)
		{
			for(int k=1;k<=100;k++)
			{
				dd Y=a[i][k];
//				if(Y)cerr<<Y<<"ASD\n";
				for(int j=1;j<=100;j++)s.a[i][j]+=Y*w.a[k][j];
			}
		}
		return s;
	}
	mat operator+(const mat&w)const
	{
		mat s;memset(s.a,0,sizeof(s.a));
		for(int i=1;i<=1;i++)
		{
			for(int k=1;k<=100;k++)
			{
				dd Y=a[i][k];
				for(int j=1;j<=100;j++)s.a[i][j]+=Y*w.a[k][j];
			}
		}
		return s;
	}
}ans,zy;
int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++)is[i]=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		v[a].push_back(b),v[b].push_back(a);
		d[a]++,d[b]++;
	}
	int tt=0;
	for(int i=1;i<=n;i++)
	{
		if(is[i])e[i].a[i]=1,e[i].a[n+(id[i]=(++tt))]=1,To[tt]=i;
		else 
		{
			e[i].a[i]=1;
			for(auto it:v[i])e[i].a[it]+=(-1.0/d[i]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		int j=1;
		while(j<=n&&(!e[j].a[i]||vis[j]))j++;
		if(j>n)continue;
		swap(e[j],e[i]);
		vis[i]=1;dd T=e[i].a[i];
		for(int j=1;j<=n+tt;j++)e[i].a[j]/=T;
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			if(!e[j].a[i])continue;
			dd xs=e[j].a[i]/e[i].a[i];
			for(int k=1;k<=n+tt;k++)e[j].a[k]-=e[i].a[k]*xs;
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n+tt;j++)
//			cout<<fixed<<setprecision(4)<<e[i].a[j]<<"  ";
//		puts("");
//	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=tt;j++)
			f[i][j]=e[i].a[j+n];
	// 
	for(int j=1;j<=tt;j++)ans.a[1][j]=f[1][j];
//	,cerr<<f[1][j]<<"ADS\n";
	//n 
	for(int i=1;i<=tt;i++)
	{
		for(int j=1;j<=tt;j++)
		{
			dd gl=0;
			for(auto it:v[To[i]])
				gl+=f[it][j]*(1.0/d[To[i]]);
			zy.a[i][j]=gl;
//			cout<<i<<" "<<j<<" "<<gl<<"!!\n";
		}
	}
//	zy.a[tt][tt]=1;
	k-=2;
	while(k)
	{
		if(k&1)ans=ans*zy;
		zy=zy*zy,k>>=1;
	}
	cout<<fixed<<setprecision(4)<<ans.a[1][tt]<<"\n";
	pc('1',1);
	return 0;
}