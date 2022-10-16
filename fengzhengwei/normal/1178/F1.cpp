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
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=505,yy=1e6+5;
int c[yy],n,m;
struct nod{int l,r,id;nod(){l=1e9,r=-1e9;}bool operator<(const nod&w)const{return (r-l+1)<(w.r-w.l+1);};}e[xx];
struct M
{
	struct node{int next,to;}e[xx<<1];
	int cnt,h[xx];
	void cls(){memset(h,0,sizeof(h));cnt=0;}
	void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}
	void run(int x);
}m1,m2;
// 
int fa[yy];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
const int mod=998244353;
ll ans=1;
int size[xx];
// 
ll f[xx][xx],g[xx];
void ad(ll &a,ll b){a+=b,a%=mod;}
void M::run(int x)
{
	size[x]=1,f[x][1]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		run(e[i].to);
		memset(g,0,sizeof(g));
		for(int j=1;j<=size[e[i].to];j++)
		{
			for(int k=1;k<=size[x];k++)//n^2n 
			{
				for(int w=0;w<=j;w++)
					ad(g[k+w],f[x][k]*f[e[i].to][j]%mod);
				// 
			}
		}
		size[x]+=size[e[i].to];
		for(int j=1;j<=size[x];j++)f[x][j]=g[j];
	}
}
void get(vector<int>&v)
{
	//n^3 
	if(v.size()==1||!v.size())return;
//	cerr<<v.size()<<"!!\n";
//	for(auto it:v)cout<<it<<" ";puts("");
	memset(f,0,sizeof(f));
	m2.cls();
	int M=1e9;
	for(int i=0;i<v.size();i++)M=min(M,v[i]);
	for(int i=0;i<v.size();i++)
	{
		int mn=1e9;
		for(int j=i-1;j>=0;j--)
		{
			if(v[j]<v[i])break;
			mn=min(mn,v[j]);
		}
		if(mn!=1e9)m2.add(v[i],mn);
		mn=1e9;
		for(int j=i+1;j<v.size();j++)
		{
			if(v[j]<v[i])break;
			mn=min(mn,v[j]);
		}
		if(mn!=1e9)m2.add(v[i],mn);
//		,cerr<<v[i]<<" "<<v[mn]<<" "<<mn<<"!!\n";
	}
	m2.run(M);
	ll sum=0;
	for(int i=1;i<=size[M];i++)sum+=f[M][i];
	sum%=mod;
	ans*=sum;
	ans%=mod;
}
void dfs(int x)
{
	// 
	vector<int>id;
	for(int i=m1.h[x];i;i=m1.e[i].next)
	{
		dfs(m1.e[i].to);
		id.push_back(m1.e[i].to);
	}
	// 
//	for(int i=1;i<=n;i++)cout<<e[i].l<<" "<<e[i].r<<"!!\n";
	sort(id.begin(),id.end(),[&](int a,int b){return e[a].l<e[b].l;});
	vector<int>w;
	int cnt=0;
	while(cnt!=id.size())
	{
		if(!w.size()||(e[*--w.end()].r+1==e[id[cnt]].l))
		{
			// 
			w.push_back(id[cnt]);
			cnt++;
		}
		else 
		{
			get(w);
			w.clear();
		}
	}
	get(w);
	
}
int main(){
//	vector<int>v;
//	v.push_back(1);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(2);
//	get(v);
//	cout<<ans<<"\n";
//	exit(0);
	n=read(),m=read();
	for(int i=1;i<=m;i++)c[i]=read(),e[c[i]].l=min(e[c[i]].l,i),e[c[i]].r=max(e[c[i]].r,i);
	// 
	for(int i=1;i<=m+1;i++)fa[i]=i;
	for(int i=n;i>=1;i--)
	{
		int x=e[i].l;
		while(x<=e[i].r)
		{
			if(c[x]!=i)puts("0"),exit(0);
			fa[x]=x+1;
			x=find(x);
//			cout<<x<<" "<<c[x]<<" "<<fa[n+1]<<"!!ASD\n";
		}
	}
//	puts("SSSDA");
//	exit(0);
	e[0].l=0,e[0].r=m;
	for(int i=0;i<=n;i++)e[i].id=i;
//	for(int i=0;i<=n;i++)cout<<e[i].l<<" "<<e[i].r<<"ASD\n";
	sort(e,e+n+1);
//	for(int i=0;i<=n;i++)cout<<e[i].l<<" "<<e[i].r<<"ASD\n";
	for(int i=0;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(e[j].l<=e[i].l&&e[i].r<=e[j].r)
			{
				m1.add(e[j].id,e[i].id);
//			,cerr<<j<<" "<<i<<" "<<e[j].id<<" "<<e[i].id<<"\n";// 
				break;
			}
	sort(e,e+n+1,[&](nod a,nod b){return a.id<b.id;});
	dfs(0);
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}