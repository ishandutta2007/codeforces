#include<bits/stdc++.h>
#define ll long long
using namespace std;
//char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m,q;
const int xx=4e5+5;
map<pair<int,int> ,int>mp;
int val[xx],uu[xx],vv[xx],s[xx],t[xx],qx[xx],qy[xx],fa[xx],sum[xx],size[xx];
void pre(){for(int i=1;i<=n;i++)fa[i]=i,sum[i]=0,size[i]=1;}
int find(int x){return fa[x]==x?x:find(fa[x]);}
int get(int x){return fa[x]==x?0:(get(fa[x])^sum[x]);}
int stk[xx],top;
bool merge(int x,int y,int z)
{
	if(find(x)==find(y))return 0;
	int t=find(y),p=find(x);
	if(size[p]<size[t])swap(x,y);
	t=find(y),p=find(x);
	stk[++top]=t;
	sum[t]=z^get(y)^get(x);
	fa[t]=p;size[p]+=size[t];
	return 1;
}
void erase()
{
	int x=stk[top--];
	sum[x]=0;size[fa[x]]-=size[x];fa[x]=x;
}
struct no{int x,y,z;};
vector<no>v[xx<<2];
struct xxj
{
	int s[32];
	void insert(int x)
	{
		for(int i=29;i>=0;i--)if(x>>i&1)if(!s[i])swap(x,s[i]);else x^=s[i];
	}
	void get(int x)
	{
		for(int i=29;i>=0;i--)if(x>>i&1)x^=s[i];
		cout<<x<<'\n';
	}
};
void cover(int k,int l,int r,int x,int y,no w)
{
	if(x<=l&&r<=y)return v[k].push_back(w),void();
	int mid=l+r>>1;
	if(x<=mid)cover(k<<1,l,mid,x,y,w);
	if(mid<y)cover(k<<1|1,mid+1,r,x,y,w);
}
void solve(int k,int l,int r,xxj X)
{
	int now=top;
	for(int i=0;i<v[k].size();i++)if(!merge(v[k][i].x,v[k][i].y,v[k][i].z))X.insert(v[k][i].z^get(v[k][i].x)^get(v[k][i].y));
	if(l==r)
	{
		if(qx[l])X.get(get(qx[l])^get(qy[l]));
	}
	else 
	{
		int mid=l+r>>1;
		solve(k<<1,l,mid,X);
		solve(k<<1|1,mid+1,r,X);
	}
	while(top!=now)erase();
}
signed main(){
	n=read(),m=read();
	pre();
	int tt=0;
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		if(a>b)swap(a,b);
		uu[++tt]=a,vv[tt]=b;
		val[tt]=read();
		mp[make_pair(a,b)]=tt;
		s[tt]=1;
	}
	q=read();
	for(int i=1;i<=q;i++)
	{
		int op=read(),a=read(),b=read();
		if(a>b)swap(a,b);
		if(op==1)
		{
			uu[++tt]=a,vv[tt]=b;
			val[tt]=read();
			mp[make_pair(a,b)]=tt;
			s[tt]=i;
		}
		if(op==2)t[mp[make_pair(a,b)]]=i;
		if(op==3)qx[i]=a,qy[i]=b;
	}
	for(int i=1;i<=tt;i++)
	{
		if(!t[i])t[i]=q;
		cover(1,1,q,s[i],t[i],(no){uu[i],vv[i],val[i]});
	}
	solve(1,1,q,(xxj){});
	return 0;
}