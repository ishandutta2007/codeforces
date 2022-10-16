#include<bits/stdc++.h>
#define ll long long
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
	(op||((*s++=c)&&s==t))&&((fwrite(buf,1,s-buf,stdout)),s=buf);
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
const int xx=2e5+5;
int fa[xx],sum[xx];//01 
int find(int x)// 
{
	if(fa[x]==x)return x;
	int a=find(fa[x]);
	sum[x]=sum[x]^sum[fa[x]];
	fa[x]=fa[fa[x]];
	return fa[x];
}
struct nod{int next,to,v;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y,int z)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
	e[cnt].v=z;
}
int d[xx],f[xx],fv[xx];
int dep[xx];
//0 
void dfs(int x,int y)
{
	dep[x]=dep[y]+1;
	f[x]=y;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		fv[e[i].to]=e[i].v;
		if(e[i].v==-1)
			d[e[i].to]=d[x];
		else d[e[i].to]=d[x]^e[i].v;
		dfs(e[i].to,x);
		
	}
}
struct No
{
	int a,b,c;
};
int op=1;
void AD(int x,int y,int z)
{
	if(!op)return;
	if(find(x)==find(y))
	{
		if((sum[x]^sum[y])!=z)op=0;
		return;
	}
	int o=find(y); 
	sum[o]=sum[y]^z;
	//sum find 
	fa[o]=x;
//	if(x==3&&y==4)
//	{
//		cout<<find(y)<<" "<<sum[y]<<"!!\n";
//	}
}
int ans[xx];
int main(){
	int T=read();
	while(T--)
	{
		op=1;
		int n=read(),m=read();
		memset(e,0,sizeof(e[0])*(cnt+1));
		memset(h,0,sizeof(h[0])*(n+1));
		cnt=0;
		for(int i=1;i<=n;i++)fa[i]=i,sum[i]=0;
		vector<No>v;
		for(int i=1;i<n;i++)
		{
			int a=read(),b=read(),c=read();
			add(a,b,c),add(b,a,c);
			v.push_back({a,b,c});
		}
		dfs(1,0);
		for(int i=1;i<=m;i++)
		{
			int a=read(),b=read(),c=read();
			int now=d[a]^d[b];
			int num=__builtin_popcount(now);
			num&=1,c^=num;
//			cout<<c<<"QQQ\n";
			AD(a,b,c);
//		for(int i=1;i<=n;i++)find(i),cout<<i<<" "<<ans[i]<<" "<<sum[i]<<" "<<fa[i]<<"\n";
		}
		//0 
		for(int i=2;i<=n;i++)
		{
			if(fv[i]!=-1)
			{
				int a=i,b=f[i],c=0;
				AD(a,b,c);// 
			}
		}
		if(!op)
		{
			puts("No");
			continue;
		}
		for(int i=1;i<=n;i++)ans[i]=0;
		for(int i=1;i<=n;i++)
			if(find(i)==i)ans[i]=0;
		for(int i=1;i<=n;i++)
			if(find(i)!=i)ans[i]=sum[i];
		puts("Yes");
		for(auto it:v)
		{
			if(it.c!=-1)
				cout<<it.a<<" "<<it.b<<" "<<it.c<<"\n";
			else 
				cout<<it.a<<" "<<it.b<<" "<<(ans[it.a]^ans[it.b])<<"\n";
		}
	}
	pc('1',1);
	return 0;
}