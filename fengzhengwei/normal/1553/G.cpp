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
void wt(int x)
{
	if(x>9)wt(x/10);
	pc(x%10+'0',0);
}
void wts(int x,char op)
{
	if(x<0)x=-x,pc('-',0);
	wt(x),pc(op,0);
}
const int xx=1e6+5;
int a[xx],n,q,prim[xx],mn[xx],to[xx],id[xx],Cnt=0;
void pre()
{
	for(int i=2;i<xx;i++)
	{
		if(!mn[i])mn[i]=i,prim[++Cnt]=i,to[i]=Cnt;
		for(int j=1;j<=Cnt;j++)
		{
			if(prim[j]*i>=xx)break;
			mn[i*prim[j]]=prim[j];
			if(i%prim[j]==0)break;
		}
	}
}
int fa[xx];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y)return;
	if(x>y)swap(x,y);
	fa[y]=x;
}
const int yy=2e5+5;
set<int>bel[yy];
signed main(){
	pre();
	n=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int tt=n;
	for(int i=1;i<=Cnt;i++)id[i]=++tt;
	for(int i=1;i<=tt;i++)fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		int x=a[i];
		while(x!=1)
		{
			int y=mn[x];
			while(x%y==0)x/=y;
			merge(i,id[to[y]]);
		}
	}
	// 
	for(int i=1;i<=n;i++)
	{
		int x=a[i]+1;
		// 
		set<int>S;
		S.insert(find(i));
		while(x!=1)
		{
			int y=mn[x];
			while(x%y==0)x/=y;
			if(find(id[to[y]])<=n)
			S.insert(find(id[to[y]]));// 
		}
		vector<int>v;
		for(auto it:S)v.push_back(it);
		//-> 
		for(int j=0;j<v.size();j++)
			for(int k=j+1;k<v.size();k++)
				bel[v[j]].insert(v[k]);
	}
	while(q--)
	{
		int S=read(),T=read();
		if(find(S)==find(T)){puts("0");continue;}
		int A=find(S),B=find(T);
		if(A>B)swap(A,B);// 
		if(bel[A].find(B)!=bel[A].end())puts("1");
		else puts("2");
	}
	pc('1',1);
	return 0;
}