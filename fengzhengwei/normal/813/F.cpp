#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
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
const int xx=1e5+5;
int n,m;
map<pair<int,int> ,int>M;
#define mp make_pair
int uu[xx],vv[xx],L[xx],R[xx],fa[xx],sum[xx],size[xx],cst;
pair<int,int> find(int x)
{
	if(fa[x]==x)return make_pair(x,0);
	pair<int,int> p=find(fa[x]);p.second^=sum[x];
	return p;
}
void init(){for(int i=1;i<=n;i++)fa[i]=i,sum[i]=0,size[i]=1;}
int nans=1,top;
struct nod
{
	int dlt,id;
	//dlt 
};
#define fi first
#define se second
nod stk[xx];
void merge(int x,int y)
{
	pair<int,int> a=find(x),b=find(y);
	if(a.fi==b.fi)
	{
		if(!(a.se^b.se))nans+=-1,stk[++top]=(nod){-1};
		return;
	}
	if(size[a.fi]<size[b.fi])swap(a,b);
	size[a.fi]+=size[b.fi];
	sum[b.fi]=1^a.se^b.se,fa[b.fi]=a.fi;
	stk[++top]=(nod){0,b.fi};
}
vector<pair<int,int> >v[xx<<2];
void cover(int k,int l,int r,int x,int y,int a,int b)
{
	if(x<=l&&r<=y)return v[k].push_back(mp(a,b)),void();
	int mid=l+r>>1;
	if(x<=mid)cover(k<<1,l,mid,x,y,a,b);
	if(mid<y)cover(k<<1|1,mid+1,r,x,y,a,b);
}
void hy()
{
	if(stk[top].dlt==-1)nans++;
	else 
	{
		int x=stk[top].id;
		size[fa[x]]-=size[x];
		sum[x]=0;fa[x]=x;
	}
	top--;
}
void ask(int k,int l,int r)
{
	int now=top;
	for(auto it:v[k])merge(it.first,it.second);
	if(l==r)
	{
		if(nans==1)puts("YES");
		else puts("NO");
		while(top!=now)hy();
		return;
	}
	int mid=l+r>>1;
	ask(k<<1,l,mid);
	ask(k<<1|1,mid+1,r);
	while(top!=now)hy();
}
signed main(){
	n=read(),m=read();init();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		if(a>b)swap(a,b);
		if(M[mp(a,b)])R[M[mp(a,b)]]=i-1,M[mp(a,b)]=0;
		else M[mp(a,b)]=++cst,uu[cst]=a,vv[cst]=b,L[cst]=i;
	}
	for(int i=1;i<=cst;i++)
	{
		if(!R[i])R[i]=m;
		cover(1,1,m,L[i],R[i],uu[i],vv[i]);
	}
	ask(1,1,m);
	return 0;
}