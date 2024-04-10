#include<bits/stdc++.h>
#define ll long long
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
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
template <int nd,int eg>struct flow
{
	struct node{int next,to,v;}e[eg];
	int cnt,h[nd],tt,s,t;
	void add(int x,int y,int z){cnt++,e[cnt]={h[x],y,z},h[x]=cnt;}
	void init(int a,int b,int z){memset(h,0,sizeof(h[0])*(tt+1)),tt=z,s=a,t=b,cnt=1;}
	void init(int z){memset(h,0,sizeof(h[0])*(tt+1)),tt=z,cnt=1;}//st 
	void ad(int a,int b,int c){add(a,b,c),add(b,a,0);}
	int q[nd],gp[nd],d[nd],v[nd],cur[nd],l,r;
	void bfs()
	{
		for(int i=1;i<=tt;i++)cur[i]=h[i],d[i]=tt,gp[i]=v[i]=0;
		d[t]=0,l=1,r=0,q[++r]=t,v[t]=1;
		while(l<=r)
		{
			int x=q[l++];
			for(int i=h[x];i;i=e[i].next)
				if(!v[e[i].to]&&e[i^1].v)d[e[i].to]=d[x]+1,q[++r]=e[i].to,v[e[i].to]=1;
		}
		for(int i=1;i<=tt;i++)gp[d[i]]++;
	}
	int isap(int x,int mx)
	{
		if(x==t)return mx;
		int res=mx;
		for(int &i=cur[x];i;i=e[i].next)
		{
			if(e[i].v&&d[x]==d[e[i].to]+1)
			{
				int a=isap(e[i].to,min(res,e[i].v));
				e[i].v-=a,e[i^1].v+=a,res-=a;
				if(!res||d[s]>tt)return mx-res;
			}
		}
		if(!(--gp[d[x]]))d[s]=tt+1;
		++gp[++d[x]];cur[x]=h[x];
		return mx-res;
	}
	int i_go()
	{
		bfs();
		int res=0;
		while(d[s]<=tt)res+=isap(s,1e9);
		return res;
	}
	int nw(){return ++tt;}// 
	//dinic 
	int ck(int s,int t)
	{
		for(int i=1;i<=tt;i++)d[i]=0,cur[i]=h[i];
		l=1,r=0,d[s]=1,q[++r]=s;
		while(l<=r)
		{
			int x=q[l++];
			for(int i=h[x];i;i=e[i].next)
			{
				if(e[i].v&&!d[e[i].to])
				{
					d[e[i].to]=d[x]+1,q[++r]=e[i].to;
					if(e[i].to==t)return 1;
				}
			}
		}
		return 0;
	}
	// 
	int dinic(int x,int S,int T,int mx)
	{
		if(x==T)return mx;
		int res=mx;
		for(int i=cur[x];i;i=e[i].next)
		{
			if(e[i].v&&d[e[i].to]==d[x]+1)
			{
				int a=dinic(e[i].to,S,T,min(res,e[i].v));
				if(!a)d[e[i].to]=0;
				e[i].v-=a,e[i^1].v+=a,res-=a;
				if(!res)return mx-res;
			}
		}
		return mx-res;
	}
	int d_go()//dinic 
	{
		int res=0;
		while(ck(s,t))res+=dinic(s,s,t,1e9);
		return res;
	}
	void dfs(int x)
	{
		v[x]=1;
		for(int i=h[x];i;i=e[i].next)
			if(!v[e[i].to]&&e[i].v)dfs(e[i].to);
	}
	bool check(int a,int b)//ab 
	{
		for(int i=1;i<=tt;i++)v[i]=0;dfs(a);
		return v[b];
	}
	void re(int a,int b,int mx){while(ck(a,b)&&mx)mx-=dinic(a,a,b,mx);}//abv 
};
flow<(int)4e6+5,(int)8e6+5>mp;
int n,m;
const int xx=2e4+5;
struct node{int next,to,id;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y,int z)
{
	cnt++;
	e[cnt]={h[x],y,z};
	h[x]=cnt;
}
int dfx[xx],to[xx],f[xx],dep[xx],cst;
int top[xx],size[xx],son[xx],ID[xx];
void dfs(int x,int y)
{
	f[x]=y;dep[x]=dep[y]+1;size[x]=1;
	int mx=-1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		ID[e[i].to]=e[i].id;
		size[x]+=size[e[i].to];
		if(size[e[i].to]>mx)mx=size[e[i].to],son[x]=e[i].to;
	}
}
void dfss(int x,int y)
{
	top[x]=y;dfx[x]=++cst;
	if(!son[x])return;
	dfss(son[x],y);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==f[x]||e[i].to==son[x])continue;
		dfss(e[i].to,e[i].to);
	}
}
int id[xx<<2];
void build(int k,int l,int r)
{
	if(l==r)
	{
		id[k]=mp.nw();
		to[l]=id[k];//dfs 
		mp.ad(id[k],mp.t,1);
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	id[k]=mp.nw();
	mp.ad(id[k],id[k<<1],1e9);
	mp.ad(id[k],id[k<<1|1],1e9);
}
void cg(int k,int l,int r,int x,int y,int z)
{
	if(x>y)return;
//	cout<<x<<" "<<y<<" "<<z<<" "<<id[k]<<" "<<l<<" "<<r<<"!!\n";
	if(x<=l&&r<=y)return mp.ad(z,id[k],1e9);
	int mid=l+r>>1;
	if(x<=mid)cg(k<<1,l,mid,x,y,z);
	if(mid<y)cg(k<<1|1,mid+1,r,x,y,z);
}
void jump(int x,int y,int z)
{
//	cout<<z<<"!!\n";
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
//		cout<<dfx[top[x]]<<" "<<dfx[x]<<"!!\n";
		cg(1,1,n,dfx[top[x]],dfx[x],z);
		x=f[top[x]];
	}
	if(dep[x]<dep[y])swap(x,y);
//		cout<<dfx[y]+1<<" "<<dfx[x]<<"!!\n";
	cg(1,1,n,dfx[y]+1,dfx[x],z);//lca 
}
int Id[xx];
int main(){
	n=read(),m=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b,i),add(b,a,i);
	}
	mp.init(1,2,2);
	dfs(1,0),dfss(1,1);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		int I=mp.nw();
		Id[i]=I;
		mp.ad(mp.s,I,1);
		jump(a,b,I);
	}
	cout<<mp.i_go()<<"\n";
	mp.check(mp.s,mp.t);
	vector<int>v;
	for(int i=1;i<=m;i++)
		if(mp.v[Id[i]]!=mp.v[mp.s])v.push_back(i);
	sort(v.begin(),v.end());
	cout<<v.size()<<" ";
	for(auto it:v)cout<<it<<" ";puts("");
	v.clear();
	for(int i=1;i<=n;i++)
		if(mp.v[to[dfx[i]]]!=mp.v[mp.t])v.push_back(ID[i]);
	cout<<v.size()<<" ";
	sort(v.begin(),v.end());
	for(auto it:v)cout<<it<<" ";puts("");
	
	pc('1',1);
	return 0;
}