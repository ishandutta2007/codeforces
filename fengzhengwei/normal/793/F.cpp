#pragma GCC optimize(2) 
#pragma GCC target("avx,sse2,sse3,sse4,mmx") 
#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
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
void wts(int x,char c)
{
	if(x<0)x=-x,pc('-',0);
	wt(x);pc(c,0);
}
const int B=1500,xx=1e5+5;
int n,m,q;
int mx[xx<<2];
void ins(int k,int l,int r,int x,int y)
{
	mx[k]=max(mx[k],y);
	if(l==r)return;
	int mid=l+r>>1;
	if(x<=mid)ins(k<<1,l,mid,x,y);
	else ins(k<<1|1,mid+1,r,x,y);
}
int ask(int k,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)return mx[k];
	int mid=l+r>>1;
	if(y<=mid)return ask(k<<1,l,mid,x,y);
	if(mid<x)return ask(k<<1|1,mid+1,r,x,y);
	return max(ask(k<<1,l,mid,x,y),ask(k<<1|1,mid+1,r,x,y));
}
vector<int>v[xx];
vector<int>p[xx];
struct nod{int x,y,id;};
vector<nod>Q[xx];
int bel[xx],ans[xx];
void bd(){memset(mx,0,sizeof(mx));}
int f[xx];
int run(int a)
{
	bd();
	for(int i=n;i>=1;i--)
	{
		f[i]=i;
		for(auto it:v[i])
		{
			if(bel[it]>a)break;
			f[i]=max(f[i],ask(1,1,n,i,it));
		}
		ins(1,1,n,i,f[i]);
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		v[a].push_back(b),p[b].push_back(a);
	}
	for(int i=1;i<=n;i++)bel[i]=(i-1)/B+1;
	for(int i=1;i<=n;i++)sort(v[i].begin(),v[i].end());
	q=read();
	for(int i=1;i<=q;i++)
	{
		int x=read(),y=read();
		Q[bel[y]].push_back({x,y,i});	
	}
	for(int i=bel[n];i>=1;i--)
	{
		run(i-1);
		for(auto it:Q[i])
		{
			int x=it.x,to=f[x];
//			cout<<to<<"!!'\n";
			for(int j=max(to,(bel[it.y]-1)*B+1);j<=it.y;j++)
				for(auto it:p[j])if(to>=it&&it>=x)to=j;
			ans[it.id]=to;
		}
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
	pc('1',1);
	return 0;
}