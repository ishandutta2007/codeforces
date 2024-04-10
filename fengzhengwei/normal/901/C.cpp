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
const int xx=3e5+5;
struct node{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
vector<int>bel[xx],v[xx];
int size[xx],dfn[xx],low[xx],stk[xx],num[xx],top,cst,scc;
void tj(int x)
{
	dfn[x]=low[x]=++cst;stk[++top]=x;
	for(int i=h[x];i;i=e[i].next)
	{
		if(!dfn[e[i].to])
		{
			tj(e[i].to),low[x]=min(low[x],low[e[i].to]);
			if(low[e[i].to]>=dfn[x])
			{
				scc++;
				v[scc].push_back(x);
				bel[x].push_back(scc);
				int sz=1;
				while(stk[top]!=e[i].to)
					sz++,bel[stk[top]].push_back(scc),v[scc].push_back(stk[top--]);
				sz++,bel[stk[top]].push_back(scc),v[scc].push_back(stk[top--]);
				size[scc]=sz;
			}
		}
		else low[x]=min(low[x],dfn[e[i].to]);
	}
}
int n,m,q,vis[xx],to[xx];
void ban(int x,int op){for(auto it:v[x])vis[it]+=op;}
void ad(int x)
{
	for(auto it:bel[x])
	{
		num[it]++;
		if(num[it]==size[it]-1&&size[it]!=2)ban(it,1);
	}
}
void er(int x)
{
	for(auto it:bel[x])
	{
		if(num[it]==size[it]-1&&size[it]!=2)ban(it,-1);// 
		num[it]--;
	}
}
ll sum[xx<<2],sz[xx<<2],adt[xx<<2];
void ad(int x,int z){sum[x]+=sz[x]*z,adt[x]+=z;}
void pd(int k){if(adt[k])ad(k<<1,adt[k]),ad(k<<1|1,adt[k]),adt[k]=0;}
void upd(int k){sum[k]=sum[k<<1]+sum[k<<1|1],sz[k]=sz[k<<1]+sz[k<<1|1];}
void build(int k,int l,int r)
{
	if(l==r)return sum[k]=to[l]-l+1,sz[k]=1,void();
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	upd(k);
}
void cg(int k,int l,int r,int x,int y,int z)
{
	if(x>y)return;
	if(x<=l&&r<=y)return ad(k,z);
	pd(k);
	int mid=l+r>>1;
	if(x<=mid)cg(k<<1,l,mid,x,y,z);
	if(mid<y)cg(k<<1|1,mid+1,r,x,y,z);
	upd(k);
}
ll ask(int k,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)return sum[k];
	pd(k);
	int mid=l+r>>1;
	ll ans=0;
	if(x<=mid)ans+=ask(k<<1,l,mid,x,y);
	if(mid<y)ans+=ask(k<<1|1,mid+1,r,x,y);
	return ans;
}
ll ans[xx];
struct qu{int l,r,id;bool operator<(const qu&w)const{return r>w.r;};}Q[xx];
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	for(int i=1;i<=n;i++)if(!dfn[i])tj(i);
	int nr=0;
	for(int i=1;i<=n;i++)
	{
		while(nr<n&&!vis[nr+1])ad(++nr);
		to[i]=nr;er(i);
	}
//	for(int i=1;i<=n;i++)cout<<i<<" "<<to[i]<<"\n";
	build(1,1,n);
	q=read();
	for(int i=1;i<=q;i++)Q[i].l=read(),Q[i].r=read(),Q[i].id=i;
	sort(Q+1,Q+q+1);
	nr=n;int R=n+1;
	for(int i=1;i<=q;i++)
	{
		while(nr>Q[i].r)
		{
			while(to[R-1]>=nr)R--;
//			cout<<R<<" "<<n<<"\n";
			cg(1,1,n,R,n,-1);
			nr--;
		}
		ans[Q[i].id]=ask(1,1,n,Q[i].l,Q[i].r);
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
	pc('1',1);
	return 0;
}