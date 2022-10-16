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
//a5e6 
namespace shai
{
	const int xx=5e6+1e5+5;
	int mn[xx],prim[xx/10];
	void pre()
	{
		int cnt=0;
		for(int i=2;i<xx;i++)
		{
			if(!mn[i])mn[i]=i,prim[++cnt]=i;
			for(int j=1;j<=cnt;j++)
			{
				if(i*prim[j]>=xx)break;
				mn[i*prim[j]]=prim[j];
				if(i%prim[j]==0)break;
			}
		}
	}
}using shai::mn;
const int xx=2e5+5;
int n,m,ans[1100005],a[xx];
struct nod
{
	int l,r,id;
	bool operator<(const nod&w)const{return r<w.r;}
}q[1100005];
struct szsz
{
	int sum[xx];
	//min- 
	//min 
	int lb(int x){return x&-x;}
	void add(int x,int y){/*cout<<x<<" "<<y<<"ED\n";*/x=xx-1-x+1;for(;x<xx;x+=lb(x))sum[x]=min(sum[x],y);}
	int ask(int x){int ans=1e9;x=xx-1-x+1;for(;x;x-=lb(x))ans=min(ans,sum[x]);return ans;}
}An;
//struct seg
//{
//	//vectorlog 
//	
//}s;
int lst[shai::xx][8];
//id 
int main(){
//	cout<<sizeof(lst)/1024/1024<<"\n";
	memset(An.sum,0x3f,sizeof(An.sum));
	shai::pre();
	n=read(),m=read();
//	n=200000,m=1049658;
	for(int i=1;i<=n;i++)a[i]=read();
//	for(int i=1;i<=n;i++)a[i]=510510+rand();
	for(int i=1;i<=m;i++)q[i].l=read(),q[i].r=read(),q[i].id=i;
//	for(int i=1;i<=m;i++)q[i].l=1,q[i].r=n,q[i].id=i;
	sort(q+1,q+m+1);
	int tt=1;
	for(int i=1;i<=n;i++)
	{
		//r=i 
		// 
		vector<int>v;
		int X=a[i];
		while(X!=1)
		{
			int t=mn[X],TT=0;
			while(X%t==0)X/=t,TT++;
			if(TT&1)v.push_back(t);
		}
		int sz=v.size();
		for(int j=0;j<(1<<sz);j++)
		{
			int re=1,ct=0;
			for(int k=0;k<sz;k++)if(j>>k&1)re*=v[k],ct++;
//			assert(re<=shai::xx);
			int mx=0;
			for(int k=ct;k<8;k++)
			{
				if(lst[re][k]<=mx)continue;
				mx=lst[re][k];
//				cout<<i<<" "<<re<<" "<<k<<" "<<sz<<" "<<ct<<"ST\n";
				An.add(mx,k+sz-ct-ct);
			}
			lst[re][sz]=i;
		}
		while(tt<=m&&q[tt].r<=i)ans[q[tt].id]=An.ask(q[tt].l),tt++;
//	if(i%1000==0)cerr<<m<<" "<<i<<" "<<n<<"!!\n";
	}
//	cerr<<m<<" "<<tt<<"\n";
	for(int i=1;i<=m;i++)cout<<ans[i]<<"\n";
	pc('1',1);
	return 0;
}