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
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
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
int n;
const int xx=1e5+5;
struct nod{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y)
{
	cnt++,e[cnt]={h[x],y},h[x]=cnt;
}
int D[xx];
struct pr
{
	int mx,se;
};
void upd(pr&a,int b)
{
	if(a.mx<b)a.se=a.mx,a.mx=b;
	else a.se=max(a.se,b);
}
pr md[xx];
int f[xx];
void dfs(int x,int y)
{
	f[x]=y,md[x]={0,-1};
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		//
		upd(md[x],md[e[i].to].mx+1);
		//md[x]=max(md[x],md[e[i].to]+1);
	}
}

void dfss(int x,int y)
{
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		D[e[i].to]=max(D[x]+1,md[x].mx==md[e[i].to].mx+1?md[x].se+1:md[x].mx+1);
		dfss(e[i].to,x);
	}
}
int res=0,id;
int stk[xx<<2],top;
void Dfs(int x,int y,int d)
{
	stk[++top]=x;
	if(x==id)res=d,top=(xx<<1);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		Dfs(e[i].to,x,d+1);
	}
	--top;
}
int dis(int x,int y)
{
	top=0,id=y,Dfs(x,0,0);
	return res;
}
int ct[xx],siz[xx],L,a,b,tt;
void get(int x,int y)
{
	siz[x]=(ct[x]>=3);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		get(e[i].to,x),siz[x]+=siz[e[i].to];
	}
}
int q[xx<<2],l,r;
int vis[xx];
bool check(int x,int y)
{
	if(f[x]==y)return siz[x];
	return tt-siz[y];
}
int F[xx],mxd,mid;
void find(int x,int y,int d)
{
	if(vis[x])return;
	if(d>mxd)mxd=d,mid=x;
	F[x]=y,vis[x]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y||vis[e[i].to])continue;
		find(e[i].to,x,d+1);
	}
	
}
int main(){/*
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);*/
	int T=read();
	while(T--)
	{
		//cout<<"T==!!!"<<T<<"\n";
		n=read(),a=read(),b=read();
		memset(h,0,sizeof(h[0])*(n+1));
		cnt=0;
		for(int i=1;i<=n;i++)vis[i]=ct[i]=0,D[i]=-1;
		for(int i=1;i<n;i++)
		{
			int a,b;
			a=read(),b=read();
			add(a,b),add(b,a);
		}
		for(int i=1;i<=n;i++)ct[i]=0;
		dfs(1,0),D[0]=-1,dfss(1,0);
		L=dis(a,b);
		for(int x=1;x<=n;x++)
		{
			for(int i=h[x];i;i=e[i].next)
			{
				if(e[i].to==f[x])
					ct[x]+=(D[x]>=L);
				else 
					ct[x]+=(md[e[i].to].mx+1>=L);
			}
		}
		tt=0;
		for(int i=1;i<=n;i++)tt+=(ct[i]>=3);/*
		cout<<L<<"%%%\n";
		for(int i=1;i<=n;i++)cout<<i<<" "<<D[i]<<" "<<f[i]<<"\n";
		for(int i=1;i<=n;i++)cout<<ct[i]<<" ";
		puts("");*/
		if(!tt){puts("NO");continue;}
		get(1,0);
		l=xx<<1,r=l-1;
		for(int i=1;i<=L+1;i++)q[++r]=stk[i];
		//for(int i=1;i<=n;i++)F[i]=0;
	/*	for(int i=l;i<=r;i++)cout<<q[i]<<" ";
		puts("");*/
		int cr=0,np=0;
		cr|=check(q[l],q[l+1]);
		cr|=check(q[r],q[r-1]);
	/*	for(int i=1;i<=n;i++)cout<<siz[i]<<" "<<f[i]<<"\n";
		cout<<"TT="<<tt<<"!!!\n";*/
		while(1)
		{
		/*	for(int i=l;i<=r;i++)cout<<q[i]<<" ";
			puts("Q");
			cout<<check(q[l],q[l+1])<<"\n";
			cout<<check(q[r],q[r-1])<<"\n";
			puts("two");*/
			mxd=-1,mid=0;
			if(np==0)
			{
				find(q[l],q[l+1],0);
//		cout<<l<<" "<<r<<" "<<q[l]<<" "<<q[r]<<" "<<np<<" "<<mid<<" "<<mxd<<" "<<vis[q[l]]<<"$%$%$\n";
				if(!mid)break;
				if(mxd>=L){cr=1;break;}
				for(int i=r-l+1;i>=mxd+1;i--)q[l+i-1]=q[l+i-mxd-1];
		/*		cout<<r-l+1<<" "<<(r-l+1-mxd)<<" "<<mxd<<" "<<mid<<"wowowow\n";
			for(int i=l;i<=r;i++)cout<<q[i]<<" ";
			puts("W");*/
				int x=mid,y=q[l];
				int il=l;
				while(x!=y)q[il++]=x,x=F[x];
				//,cerr<<x<<" "<<y<<"$$%$\n";
			}
			else 
			{
				find(q[r],q[r-1],0);
				if(mxd>=L){cr=1;break;}
				if(!mid)break;
				for(int i=r-l+1;i>=mxd+1;i--)q[r-i+1]=q[r-i+mxd+1];
		//		for(int i=r-l+1;i>=(r-l+1)-mxd+1;i--)q[r-i+1]=q[r-i+((r-l+1)-mxd)+1];
				int x=mid,y=q[r];
				int ir=r;
				while(x!=y)q[ir--]=x,x=F[x];
				//,cerr<<x<<"%^%^\n";
				
			}
			cr|=check(q[l],q[l+1]);
			cr|=check(q[r],q[r-1]);
			np^=1;
		}
		
		if(cr)puts("YES");
		else puts("NO");
	}
	pc('1',1);
	return 0;
}