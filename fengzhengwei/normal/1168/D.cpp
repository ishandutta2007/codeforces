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
const int xx=2e5+5;
int n,m,f[xx];
char g()
{
	char c;
	while((c=getchar())!='?'&&c>'z'&&c<'a');
	return c;
}
char to[xx];
int t[xx][26],tf[xx][26],dep[xx],cr[xx],son[xx],F[xx],T[xx],num[xx];
int c[xx][2],tt[xx],is[xx],id[xx],iv,lst;
void dfs(int x)
{
	if(!x)return;
	dfs(c[x][0]),dfs(c[x][1]);
	assert((c[x][0]!=0)^(c[x][1]==0));// 
	if(c[x][0])
	{
		for(int i=0;i<26;i++)t[x][i]=max(t[x][i],t[c[x][0]][i]);
		for(int i=0;i<26;i++)t[x][i]=max(t[x][i],t[c[x][1]][i]);
	}
	int re=0;
	for(int i=0;i<26;i++)re+=t[x][i];
	iv+=(is[x]=(re>(lst-dep[x])));
	for(int i=0;i<26;i++)t[x][i]+=tf[x][i];
}
void upd(int x)
{
	if(!x)return;
	iv-=is[x];
	for(int i=0;i<26;i++)t[x][i]=0;
	if(c[x][0])
	{
		for(int i=0;i<26;i++)t[x][i]=max(t[x][i],t[c[x][0]][i]);
		for(int i=0;i<26;i++)t[x][i]=max(t[x][i],t[c[x][1]][i]);
	}
	int re=0;
	for(int i=0;i<26;i++)re+=t[x][i];
//	cerr<<re<<" "<<lst<<"!!\n";
	iv+=(is[x]=(re>(lst-dep[x])));
	for(int i=0;i<26;i++)t[x][i]+=tf[x][i];
	upd(f[x]);
}
int main(){
	n=read(),m=read();
	for(int i=2;i<=n;i++)f[i]=read(),to[i]=g(),dep[i]=dep[f[i]]+1;
	for(int i=2;i<=n;i++)cr[f[i]]=1,num[f[i]]++;
	to[1]='?',lst=-1;
	for(int i=1;i<=n;i++)
	{
		if(!cr[i])
		{
			if(lst==-1)lst=dep[i];
			else if(dep[i]!=lst)lst=-1000;
		}
	}
	for(int i=1;i<=n;i++)T[dep[i]]++;
	for(int i=1;i<=n;i++)T[i]+=T[i-1];
	for(int i=1;i<=n;i++)id[T[dep[i]]--]=i;
	for(int i=n;i>=1;i--)// 
	{
		int x=id[i];
		if(son[x])continue;
		son[x]=x;if(to[x]!='?')tf[x][to[x]-'a']++;
		while(f[x]&&num[f[x]]==1)
		{
			son[f[x]]=x;
			if(to[f[x]]!='?')tf[x][to[f[x]]-'a']++;
			f[x]=f[f[x]];// 
		}
		c[f[x]][tt[f[x]]++]=x;
	}
	if(lst==-1000){while(m--)puts("Fou");return 0;}
	dfs(son[1]);
	for(int i=1;i<=m;i++)
	{
		int x=read();char c=g();
		if(to[x]!='?')tf[son[x]][to[x]-'a']--;
		to[x]=c;
		if(to[x]!='?')tf[son[x]][to[x]-'a']++;
		upd(son[x]);
		if(iv)puts("Fou");
		else 
		{
			cout<<"Shi ";
//			puts("Shi");
			int re=0,an=0;
			for(int i=0;i<26;i++)re+=t[son[1]][i],an+=(i+1)*t[son[1]][i];
			cout<<an+351*(lst-re)<<"\n";
		}
	}
	pc('1',1);
	return 0;
}