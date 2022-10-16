#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc/
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
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
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
	wt(x),pc(op,0);
}
const int xx=6e5+5;
struct nod{int next,to,v;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y,int z){cnt++,e[cnt]={h[x],y,z},h[x]=cnt;}
int n;
struct no{int to,v;};
vector<no>v[xx];
int fa[xx];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
set<int>rem;// 
int id[xx],al[xx];//alive 
namespace fhq
{
	ll sum[xx];
	int c[xx][2],siz[xx],v[xx],rd[xx],cst;
	// 
	void upd(int k){siz[k]=siz[c[k][0]]+siz[c[k][1]]+1,sum[k]=sum[c[k][0]]+sum[c[k][1]]+v[k];}
	void split(int k,int a,int &x,int &y)
	{
		if(!k)return x=y=0,void();
		if(v[k]<=a)x=k,split(c[k][1],a,c[k][1],y);
		else y=k,split(c[k][0],a,x,c[k][0]);
		upd(k);
	}
	int merge(int x,int y)
	{
		if(!x||!y)return x+y;
		if(rd[x]<rd[y])return c[x][1]=merge(c[x][1],y),upd(x),x;
		return c[y][0]=merge(x,c[y][0]),upd(y),y;
	}
	void insert(int &root,int V)
	{
		int x,y;
		split(root,V,x,y);
		++cst,rd[cst]=rand(),siz[cst]=1,sum[cst]=v[cst]=V;
		root=merge(x,merge(cst,y));
	}
	void erase(int &root,int V)
	{
		int x,y,z;
		split(root,V-1,x,y);
		split(y,V,y,z);
		y=merge(c[y][0],c[y][1]);
		root=merge(x,merge(y,z));
	}
	ll ask(int k,int a)
	{
		if(a<=0)return 0;
//		assert(a>=0);
//		if(!a)return 0;
		if(siz[k]<a)return 1e12;
		if(siz[k]==a)return sum[k];
		if(siz[c[k][0]]+1==a)return sum[c[k][0]]+v[k];
		if(a<=siz[c[k][0]])return ask(c[k][0],a);
		return sum[c[k][0]]+v[k]+ask(c[k][1],a-siz[c[k][0]]-1);
	}
}
using fhq::insert;
using fhq::erase;
using fhq::ask;
int val[xx];
void merge(int a,int b)
{
	a=find(a),b=find(b);
	rem.erase(b);
	rem.insert(a);
	fa[b]=a;
}
void over(int x)
{
	al[x]=1;
	rem.insert(x);
	for(auto it:v[x])
	{
		if(al[it.to])
		{
			merge(x,it.to);
			// 
			erase(val[x],it.v);
			erase(val[it.to],it.v);
			add(x,it.to,it.v),add(it.to,x,it.v);
		}
	}
}
//set 
ll ans[xx],sum,f[xx][2];
//z 
int now;//now 
void dfs(int x,int y,int z)
{
	f[x][0]=f[x][1]=1e12;
	vector<ll>rsm;
	ll ttsum=0;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x,e[i].v);
		ttsum+=f[e[i].to][0];
		rsm.push_back(f[e[i].to][1]-f[e[i].to][0]);
	}
	//val, 
	//log 
//	cout<<ask(val[x],1)<<"\n";
//	cout<<ask(val[x],2)<<"\n";
	sort(rsm.begin(),rsm.end());
	ll ns=0;
	for(int i=0;i<=rsm.size();i++)
	{
		f[x][0]=min(f[x][0],ns+ttsum+ask(val[x],v[x].size()-now-i));
		if(i==rsm.size())break;
		ns+=rsm[i];
	}
	if(y)
	{
		ll ns=0;
		for(int i=0;i<=rsm.size();i++)
		{
			f[x][1]=min(f[x][1],ns+ttsum+ask(val[x],v[x].size()-now-i-1));
			if(i==rsm.size())break;
			ns+=rsm[i];
		}
		f[x][1]+=z;
	}
	
}

signed main(){
	srand(514);
	n=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read(),c=read();
		v[a].push_back({b,c}),v[b].push_back({a,c});
		insert(val[a],c),insert(val[b],c);
	}
	for(int i=1;i<=n;i++)id[i]=i;
	sort(id+1,id+n+1,[&](int a,int b){return v[a].size()>v[b].size();});
	for(int i=1;i<=n;i++)fa[i]=i;
	int tt=1;
	for(int an=n-1;an>=0;an--)
	{
//		cerr<<v[id[tt]].size()<<"\n";
		while(tt<=n&&v[id[tt]].size()>an)over(id[tt]),tt++;
//		,cerr<<tt<<"!!\n";
		sum=0,now=an;
//		for(auto it:rem)cout<<it<<"!!\n";
		for(auto it:rem)
			dfs(it,0,-1),sum+=f[it][0];
		ans[an]=sum;
	}
	for(int i=0;i<n;i++)cout<<ans[i]<<" ";
	puts("");
	pc('1',1);
	return 0;
}