#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=5e5+5;
int n,m,c[xx];
struct nod{int next,to,v;}e[xx<<1];
int cnt=1,h[xx];
void add(int x,int y,int z){cnt++,e[cnt]={h[x],y,z},h[x]=cnt;}
int rt=1,cr=0,C[xx];
void col(int x)
{
	if(cr)return;
	for(int i=h[x];i;i=e[i].next)
	{
		if(!C[e[i].to])C[e[i].to]=(3-C[x]),col(e[i].to);
		else 
		{
			// 
			if(C[e[i].to]!=(3-C[x]))rt=e[i].to,cr=1;
		}
		if(cr)return;
	}
}
int f[xx],fid[xx],dep[xx];
int dfx[xx],vis[xx],TT;
void dfs(int x,int y)
{
	vis[x]=1;
	dfx[++TT]=x;
	f[x]=y,dep[x]=dep[y]+1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		if(vis[e[i].to])continue;
		dfs(e[i].to,x),fid[e[i].to]=e[i].v;
	}
}
ll ans[xx],val[xx];
int uu[xx],vv[xx];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		uu[i]=a,vv[i]=b;
		if(uu[i]>vv[i])swap(uu[i],vv[i]);
		add(a,b,i),add(b,a,i);
	}
	C[1]=1,col(1);
	dfs(rt,0);
	for(int i=n;i>=1;i--)
	{
		int x=dfx[i];
		if(x!=rt)
		{
			ans[fid[x]]+=c[x]-val[x];
			val[f[x]]+=c[x]-val[x];
			val[x]+=c[x]-val[x];
		}
	}
	if(val[rt]==c[rt])
	{
		puts("YES");
		for(int i=1;i<=m;i++)cout<<ans[i]<<"\n";
		exit(0);
	}
	if(!cr)
	{
		puts("NO");
		exit(0);
	}
//	puts("ASDASD");
//	cout<<rt<<" "<<val[rt]<<" "<<c[rt]<<"\n";
	for(int i=1;i<=m;i++)
	{
//		cerr<<rt<<" qqq "<<uu[i]<<" "<<vv[i]<<"!!\n";
		if(vv[i]==rt)swap(uu[i],vv[i]);// 
		if(uu[i]==rt&&(dep[vv[i]]-dep[uu[i]])%2==0)
		{
//			cout<<c[rt]<<" "<<val[rt]<<"!!\n";
			ans[i]+=(c[rt]-val[rt])/2;// 
			val[rt]+=ans[i],val[vv[i]]+=ans[i];
			int x=vv[i];
			while(x!=rt)
			{
				ans[fid[x]]+=c[x]-val[x];
				val[f[x]]+=c[x]-val[x];
				val[x]+=c[x]-val[x];
				x=f[x];
			}
			break;
		}
	}
//	for(int i=1;i<=n;i++)cout<<i<<" "<<val[i]<<"!!\n";
	puts("YES");
	for(int i=1;i<=m;i++)cout<<ans[i]<<"\n";
	exit(0);
	pc('1',1);
	return 0;
}