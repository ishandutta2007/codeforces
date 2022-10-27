// LUOGU_RID: 91576616
#include<bits/stdc++.h>
namespace ifzw{
#define ll long long 
#define dd double
#define LL __int128
#define ld long double
#define ull unsigned ll 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
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
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=1e6+5;
int n;
struct nod
{
	int next,to;
}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++;e[cnt]={h[x],y},h[x]=cnt;}
int dep[xx],md[xx],d[xx],son[xx];
void pre(int x,int y)
{
	dep[x]=dep[y]+1,md[x]=dep[x];
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		pre(e[i].to,x);
		if(md[x]<md[e[i].to])md[x]=md[e[i].to],son[x]=e[i].to;
	}
}
int lin[xx<<1],*p;
//0 ~ md-dep
int *f[xx];
int ans=1,X;
void cp(int x,int y)
{
	f[x][0]=d[x];
	if(son[x])
	{
		f[son[x]]=f[x]+1,cp(son[x],x),f[x][0]=max(f[x][0],f[x][1]);
		while(ans<md[x]-dep[x]&&d[x]+f[x][ans+1]+X>ans)++ans;
	}
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==son[x]||e[i].to==y)continue;
		f[e[i].to]=p,p+=(md[e[i].to]-dep[e[i].to]+1);
		cp(e[i].to,x);
		for(int j=0;j<=md[e[i].to]-dep[e[i].to];j++)
		{
			if(ans<j)break;
			while(ans-j-1<md[x]-dep[x]&&f[e[i].to][j]+f[x][ans-j]+X>ans)++ans;
		}
		for(int j=0;j<=md[e[i].to]-dep[e[i].to];j++)
		{
			f[x][j+1]=max(f[x][j+1],f[e[i].to][j]);
			f[x][j]=max(f[x][j],f[x][j+1]);
		}
	}
}
int solve(int x)
{
	ans=1,f[1]=p,p+=(md[1]-dep[1]+1);X=x,cp(1,0);
	while(p!=lin)*p--=0;
	*p=0;
	return ans;
}
int main(){
//	freopen("a.in","r",stdin);
	n=read();
	for(int i=2,x;i<=n;i++)x=read(),add(x,i),add(i,x),d[i]++,d[x]++;
	pre(1,0);p=lin;
	queue<int>Q;
	for(int i=1;i<=n;i++)
		if(d[i]==1)Q.push(i),d[i]=0;
	for(int i=1;i<=n;i++)if(d[i])d[i]=1e9;
	while(!Q.empty())
	{
		int x=Q.front();Q.pop();
		for(int i=h[x];i;i=e[i].next)
			if(d[e[i].to]>d[x]+1)d[e[i].to]=d[x]+1,Q.push(e[i].to);
	}
	int q=read();
	while(q--)
		cout<<solve(read())<<" ";
	pc('1',1);
	return 0;
}



}signed main(){return ifzw::main();}