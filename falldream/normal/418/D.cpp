#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 100000
#define N 131072
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,head[MN+5],cnt=0,dep[MN+5],size[MN+5],mx[MN+5],dfn[MN+5],p[MN+5],dn=0,w[MN+5],W[MN+5];
int top[MN+5],fa[MN+5],Mx1[MN+5],from[MN+5],Mx2[MN+5],from2[MN+5],Mx3[MN+5],T1[N*2+5],T2[N*2+5];
struct edge{int to,next;}e[MN*2+5];

inline void ins(int f,int t)
{
	e[++cnt]=(edge){t,head[f]};head[f]=cnt;
	e[++cnt]=(edge){f,head[t]};head[t]=cnt;	
}

void Renew(int*T,int x,int v){for(T[x+=N]=v;x>>=1;)T[x]=max(T[x<<1],T[x<<1|1]);}
int Query(int*T,int l,int r)
{
//	cout<<"Query"<<l<<" "<<r<<endl;
	int res=-1e9;
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) res=max(res,T[l+1]);
		if( r&1) res=max(res,T[r-1]);
	}
//	cout<<"res="<<res<<endl;
	return res;
}

void Pre(int x,int f)
{
	size[x]=1;mx[x]=0;fa[x]=f;Mx1[x]=Mx2[x]=Mx3[x]=dep[x];from[x]=x;
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=f)
		{
			dep[e[i].to]=dep[x]+1;
			Pre(e[i].to,x);	
			size[x]+=size[e[i].to];
			if(size[e[i].to]>size[mx[x]]) mx[x]=e[i].to;
			if(Mx1[e[i].to]>Mx1[x]) Mx3[x]=Mx2[x],from2[x]=from[x],Mx2[x]=Mx1[x],Mx1[x]=Mx1[e[i].to],from[x]=e[i].to;
			else if(Mx1[e[i].to]>Mx2[x]) Mx3[x]=Mx2[x],Mx2[x]=Mx1[e[i].to],from2[x]=e[i].to;
			else if(Mx1[e[i].to]>Mx3[x]) Mx3[x]=Mx1[e[i].to];
		}
	for(int i=head[x];i;i=e[i].next) if(e[i].to!=f) W[e[i].to]=e[i].to==from[x]?Mx2[x]:Mx1[x];
}

void dfs(int x,int tp)
{
	top[x]=tp;p[dfn[x]=++dn]=x;w[x]=dep[x];
	if(mx[x]) dfs(mx[x],tp);
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa[x]&&e[i].to!=mx[x])
			dfs(e[i].to,e[i].to),w[x]=max(w[x],Mx1[e[i].to]);
	Renew(T1,dfn[x],w[x]);Renew(T2,dfn[x],w[x]-2*dep[x]);
//	cout<<x<<" w= "<<w[x]<<endl;
}

int Up(int x,int k)
{
	for(;;)
	{
		if(dep[x]-dep[top[x]]>=k) return p[dfn[x]-k]; 
		else k-=dep[x]-dep[top[x]]+1,x=fa[top[x]];
	}	
}

int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];	
	}
	return dfn[x]<dfn[y]?x:y;
}

int Solve(int*T,int x,int k,int y)
{
//	cout<<"Solve"<<x<<" "<<k<<" "<<y<<endl;
	int res=-1e9;
	for(;dep[x]>=k;y=x,x=fa[x])
	{
	//	cout<<"y="<<y<<" "<<W[y]<<endl;
		res=max(res,W[y]+(T==T1?0:-2)*dep[x]);if(dep[x]==k) return res;
		if(top[x]!=x) 
		{
			int to=max(dep[top[x]],k),nx=p[dfn[top[x]]+to-dep[top[x]]];
			res=max(res,Query(T,dfn[nx],dfn[x]-1));x=nx;
		}
	}
	return res;
}

int main()
{
	n=read();memset(T2,200,sizeof(T2));memset(T1,200,sizeof(T1));
	for(int i=1;i<n;++i) ins(read(),read());
	Pre(dep[1]=1,0);dfs(1,1);m=read();
	for(int i=1;i<=m;++i)
	{
		int x=read(),y=read(),z=lca(x,y);if(dep[x]<dep[y]) swap(x,y);	
		int up1=Up(x,dep[x]-dep[z]-1),up2=y==z?0:Up(y,dep[y]-dep[z]-1);
		int ans=max(Mx1[x]-dep[x],(((z==y&&from[y]==up1))?Mx2[y]:Mx1[y])-dep[y]);
	//	cout<<"Preans="<<ans<<endl;
	//	cout<<"mx1 x = "<<Mx1[x]<<endl;
		int len=(dep[x]+dep[y]-2*dep[z])>>1;
		if(y!=z)
		{
			if(from[z]!=up1&&from[z]!=up2) ans=max(ans,Mx1[z]+dep[y]-2*dep[z]);
			else if(from2[z]!=up1&&from2[z]!=up2) ans=max(ans,Mx2[z]+dep[y]-2*dep[z]);
			else ans=max(ans,Mx3[z]+dep[y]-2*dep[z]);	
	//		cout<<"ans2="<<ans<<endl;
		}
		if(dep[y]>dep[z]) ans=max(ans,Solve(T2,fa[y],dep[z]+1,y)+dep[y]);
		if(dep[x]>dep[z]&&len) ans=max(ans,Solve(T2,fa[x],max(dep[x]-len,dep[z]+1),x)+dep[x]);	
	//	cout<<"Check="<<ans<<endl;
		if(dep[x]-len-1>dep[z]) ans=max(ans,Solve(T1,Up(x,len+1),dep[z]+1,Up(x,len))-dep[z]+dep[y]-dep[z]);
		if(z>1) ans=max(ans,dep[y]+Solve(T2,fa[z],1,z));
		printf("%d\n",ans);
	}
	return 0;
}