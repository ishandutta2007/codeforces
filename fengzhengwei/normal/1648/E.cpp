#include<bits/stdc++.h>
#define ll long long
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
const int xx=2e5+5;
int T;
//vectorsizsizvectorset/ map 
struct node{int next,to,v;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y,int z){/*cerr<<x<<" qq "<<y<<" "<<z<<"\n";*/cnt++;e[cnt]={h[x],y,z};h[x]=cnt;}// 
map<pair<int,int> ,int>mp;
struct dsu
{
	int fa[xx],siz[xx];
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	void merge(int x,int y)
	{
		x=find(x),y=find(y);
		fa[y]=x,siz[x]+=siz[y];
	}
}F1,F2;
int d[xx];
vector<int>v[xx];
void merge(vector<int>&a,vector<int>&b)
{
	if(a.size()<b.size())swap(a,b);
	for(auto it:b)a.push_back(it);
	b.clear();
}
struct nod
{
	int a,b,c;
	bool operator<(const nod&w)const{return c<w.c;}
};
vector<nod>V;
set<int>s[xx];
int uu[xx],vv[xx];
int f[200005][21],g[200005][21],dep[xx];
void dfs(int x,int y)
{
	dep[x]=dep[y]+1;
	for(int i=1;i<=20;i++)f[x][i]=f[f[x][i-1]][i-1],g[x][i]=max(g[x][i-1],g[f[x][i-1]][i-1]);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		f[e[i].to][0]=x,g[e[i].to][0]=e[i].v;
		dfs(e[i].to,x);
	}
}
int lg[xx];
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	int mx=0;
	while(dep[x]!=dep[y])
		mx=max(mx,g[x][lg[dep[x]-dep[y]]]),x=f[x][lg[dep[x]-dep[y]]];
	if(x==y)return mx;
	for(int i=lg[dep[x]];i>=0;i--)
	{
		if(f[x][i]!=f[y][i])
		{
			mx=max(mx,g[x][i]);
			mx=max(mx,g[y][i]);
			x=f[x][i],y=f[y][i];
		}
	}
	mx=max(mx,g[x][0]);
	mx=max(mx,g[y][0]);
	return mx;
}
int main(){
	lg[0]=-1;
	for(int i=1;i<xx;i++)lg[i]=lg[i-1]+(i==(i&-i));
	T=read();
	while(T--)
	{
		mp.clear(),V.clear();
		int n=read(),m=read();
		memset(h,0,sizeof(h[0])*(n+1));
		cnt=0;
		for(int i=1;i<=n;i++)v[i].clear(),v[i].push_back(i);
		for(int i=1;i<=n;i++)
			for(int j=0;j<=20;j++)f[i][j]=g[i][j]=0;
		for(int i=1;i<=m;i++)
		{
			int a=read(),b=read(),c=read();
			uu[i]=a,vv[i]=b;
			mp[make_pair(a,b)]=mp[make_pair(b,a)]=1;
			d[a]++,d[b]++;
			V.push_back({a,b,c});
		}
		for(int i=1;i<=n;i++)F1.fa[i]=i,F2.fa[i]=i,F1.siz[i]=d[i];
		for(int i=1;i<=n;i++)s[i].clear(),s[i].insert(i);//sF1 
		sort(V.begin(),V.end());
		for(auto It:V)
		{
			if(F1.find(It.a)==F1.find(It.b))continue;
			It.a=F1.find(It.a),It.b=F1.find(It.b);
			if(F1.siz[It.a]>F1.siz[It.b])swap(It.a,It.b);//a 
			vector<int>Er;
			for(auto C:s[It.a])
			{
				int lst=-1;//lst 
////			cerr<<It.a<<" "<<It.b<<" "<<C<<"!@#$\n";
				for(auto A:v[C])
				{
					vector<int>er;
					for(auto C2:s[It.b])
					{
						if(C2==lst)continue;
						int cr=0;
						for(auto B:v[C2])
						{
//								cerr<<A<<" "<<B<<" "<<It.a<<" "<<It.b<<"!!\n";
							if(mp.find(make_pair(A,B))==mp.end())
							{
//								assert(F2.find())
								cr=1,add(A,B,It.c),add(B,A,It.c);
								break;
							}
						}
						if(cr)
						{
							if(lst!=-1)
							{
								er.push_back(C2);
//								F2.merge(lst,C2);
								merge(v[lst],v[C2]);
							}
							else lst=C2;
//							,F2.merge(lst,C);
						}
					}
					for(auto it:er)s[It.b].erase(it);
				}
				if(lst!=-1)Er.push_back(C),merge(v[lst],v[C]);
			}
			for(auto it:Er)s[It.a].erase(it);
			for(auto it:s[It.a])s[It.b].insert(it);
			F1.merge(It.b,It.a);
			s[It.a].clear();
		}
		dfs(1,0);
		for(int i=1;i<=m;i++)
			cout<<lca(uu[i],vv[i])<<" ";
		puts("");
	}
	pc('1',1);
	return 0;
}