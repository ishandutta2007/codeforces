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
const int xx=3e5+5;
struct node{int p,s,b;}c[xx];
struct nod{int inc,pre;}r[xx];
int lsh[xx],sum[xx],n,m,tt;
int lb(int x){return x&-x;}
void add(int x,int y){assert(x!=0);for(;x<=tt;x+=lb(x))sum[x]+=y;}
int ask(int x){int ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}
struct no{int id,op;}e[xx],w[xx];//op=0op=1(w) 
#define g(x,y,z) (x.op==0?c[x.id].y:r[x.id].z)
bool cmp0(const no&a,const no&b)//b i>=pre j 
{
	int x=g(a,b,pre),y=g(b,b,pre);
	if(x==y)return a.op<b.op;// 
	return x>y;
}
bool cmp1(const no&a,const no&b)//b i<pre j 
{
	int x=g(a,b,pre),y=g(b,b,pre);
	if(x==y)return a.op>b.op;// 
	return x<y;
}
int ans[xx],opt;
bool cmp2(const no&a,const no&b)
{
	if(opt==0)//bi+pi<=incj+prej 
	{
		int x=g(a,b,pre)+lsh[g(a,p,inc)],y=g(b,b,pre)+lsh[g(b,p,inc)];
		return x<=y;
	}
	else //bi-pi>=prej-incj
	{
		int x=g(a,b,pre)-lsh[g(a,p,inc)],y=g(b,b,pre)-lsh[g(b,p,inc)];
		return x>=y;
	}
}
void cdq(int l,int R)
{
//	cout<<l<<" "<<R<<"\n";
	if(l==R)return;
	int mid=l+R>>1;
	cdq(l,mid),cdq(mid+1,R);//cmp 
	int lps=l,rps=mid+1,gtt=l;
	while(lps<=mid&&rps<=R)
	{
		if(cmp2(e[lps],e[rps]))
		{
//			puts("SSSs");
			w[gtt++]=e[lps];
//			cout<<c[e[lps].id].p<<" "<<e[lps].id<<" "<<e[lps].op<<"\n";
			if(e[lps].op==0)add(c[e[lps].id].p,1),add(c[e[lps].id].s+1,-1);
			lps++;
		}
		else 
		{
			w[gtt++]=e[rps];
			if(e[rps].op==1)ans[e[rps].id]+=ask(r[e[rps].id].inc);
			rps++;
		}
	}
	while(lps<=mid)
	{
		w[gtt++]=e[lps];
//			assert(e[lps].id!=0);
		if(e[lps].op==0)add(c[e[lps].id].p,1),add(c[e[lps].id].s+1,-1);
		lps++;
	}
	while(rps<=R)
	{
		w[gtt++]=e[rps];
		if(e[rps].op==1)ans[e[rps].id]+=ask(r[e[rps].id].inc);
		rps++;
	}
	for(int i=l;i<=mid;i++)if(e[i].op==0)add(c[e[i].id].p,-1),add(c[e[i].id].s+1,1);
	for(int i=l;i<=R;i++)e[i]=w[i];
}
signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)c[i].p=read(),lsh[++tt]=c[i].p;
	for(int i=1;i<=n;i++)c[i].s=read(),lsh[++tt]=c[i].s;
	for(int i=1;i<=n;i++)c[i].b=read();
	for(int i=1;i<=m;i++)r[i].inc=read(),lsh[++tt]=r[i].inc;
	for(int i=1;i<=m;i++)r[i].pre=read();
	sort(lsh+1,lsh+tt+1);
	tt=unique(lsh+1,lsh+tt+1)-lsh-1;
	for(int i=1;i<=n;i++)c[i].p=lower_bound(lsh+1,lsh+tt+1,c[i].p)-lsh;
//	for(int i=1;i<=n;i++)cout<<c[i].p<<" ";puts("");
	for(int i=1;i<=n;i++)c[i].s=lower_bound(lsh+1,lsh+tt+1,c[i].s)-lsh;
	for(int i=1;i<=m;i++)r[i].inc=lower_bound(lsh+1,lsh+tt+1,r[i].inc)-lsh;
	for(int i=1;i<=n;i++)e[i].id=i,e[i].op=0;
//	,cerr<<e[i].id<<'\n';
	for(int i=1;i<=m;i++)e[i+n].id=i,e[i+n].op=1;
	sort(e+1,e+n+m+1,cmp0);
	cdq(1,n+m);
	opt=1;
//	return 0;
//	cout<<ask(tt)<<"\n";
	sort(e+1,e+n+m+1,cmp1);
	cdq(1,n+m);
	for(int i=1;i<=m;i++)cout<<ans[i]<<" \n"[i==m];
	return 0;
}