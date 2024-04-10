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
const int xx=2e5+5;
struct SAM
{
	struct nod{int to[26],size,link;}e[xx<<1];
	int last,cst;
	void init(){last=cst=1;e[1].size=1;}
	int add(int x)
	{
		int now=++cst,p=last;e[now].size=e[p].size+1;last=now;
		while(p&&!e[p].to[x])e[p].to[x]=now,p=e[p].link;
		if(!p)e[now].link=1;
		else 
		{
			int q=e[p].to[x];
			if(e[p].size+1==e[q].size)e[now].link=q;
			else 
			{
				int s=++cst;
				e[s].size=e[p].size+1;
				for(int j=0;j<26;j++)e[s].to[j]=e[q].to[j];
				e[s].link=e[q].link;
				e[q].link=e[now].link=s;
				while(p&&e[p].to[x]==q)e[p].to[x]=s,p=e[p].link;
			}
		}
		return now;
	}
	void tp();
}sz,sf;// 
namespace T// 
{
	struct node{int next,to;}e[xx<<1];
	int cnt,h[xx];
	void add(int x,int y){cnt++;e[cnt]={h[x],y};h[x]=cnt;}
	int f[xx],dep[xx],size[xx],son[xx];
	void build()
	{
		for(int i=2;i<=sz.cst;i++)
			add(sz.e[i].link,i);
	}
	void dfs(int x,int y)
	{
		f[x]=y,size[x]=1,dep[x]=dep[y]+1;
		//SAMsize 
		int mx=-1;
		for(int i=h[x];i;i=e[i].next)
		{
			if(e[i].to==y)continue;
			dfs(e[i].to,x),size[x]+=size[e[i].to];
			if(size[e[i].to]>mx)mx=size[e[i].to],son[x]=e[i].to;
		}
	}
	int top[xx],dfx[xx],CC;
	void dfss(int x,int y)
	{
		top[x]=y,dfx[x]=++CC;
		if(!son[x])return;
		dfss(son[x],y);
		for(int i=h[x];i;i=e[i].next)
		{
			if(e[i].to==f[x]||e[i].to==son[x])continue;
			dfss(e[i].to,e[i].to);
		}
	}
	int lca(int x,int y)
	{
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]])swap(x,y);
			x=f[top[x]];
		}
		return dep[x]<dep[y]?x:y;
	}
	ll get(int x,int y){return sz.e[lca(x,y)].size;}
}
struct A
{
	int x;
	bool operator<(const A&w)const{return T::dfx[x]<T::dfx[w.x];}
};
ll in(set<A>&s,int w)
{
	set<A>::iterator it=s.insert({w}).first;//second
	// 
	ll dlt=sz.e[w].size;
	if(s.size()==1)return dlt;
	if(it==s.begin())return dlt-T::get(w,(++it)->x);
	if((++it)==s.end())return dlt-T::get((--it)->x,(--it)->x);
	int nx=it->x;
	--it,--it;
	int pr=it->x;
	return dlt+T::get(pr,nx)-T::get(pr,w)-T::get(w,nx);
}
struct no
{
	ll ans;
	set<A>s;
}V[xx];
char s[xx];
int n,idz[xx],idf[xx];
int t[xx],id[xx];
void SAM::tp()
{
	for(int i=1;i<=cst;i++)t[e[i].size]++;
	for(int i=1;i<=n+1;i++)t[i]+=t[i-1];
	for(int i=1;i<=cst;i++)id[t[e[i].size]--]=i;
}
void merge(no&a,no&b)
{
	if(a.s.size()<b.s.size())swap(a,b);
	for(auto it:b.s)a.ans+=in(a.s,it.x);
	b.s.clear();
}
int main(){
	sz.init(),sf.init();
	scanf("%s",s+1);
	n=strlen(s+1);
	idz[0]=1;
	for(int i=1;i<=n;i++)idz[i]=sz.add(s[i]-'a');
	idf[n+1]=1;
	for(int i=n;i>=1;i--)idf[i]=sf.add(s[i]-'a');
	//set 
	//size 
	T::build(),T::dfs(1,0),T::dfss(1,1);
	sf.tp();
	for(int i=n+1;i>=2;i--)
		V[idf[i]].ans=in(V[idf[i]].s,idz[i-2]);
	ll ans=0;
	for(int x=sf.cst;x>=1;x--)
	{
		int i=id[x];
		ans+=V[i].ans*(sf.e[i].size-sf.e[sf.e[i].link].size);
//		cout<<i<<" "<<V[i].ans<<" "<<(sf.e[i].size-sf.e[sf.e[i].link].size)<<"!!\n";// 
		if(i!=1)merge(V[sf.e[i].link],V[i]);
	}
//	cout<<ans<<"\n";
	for(int i=1;i<=sz.cst;i++)ans+=sz.e[i].size-sz.e[sz.e[i].link].size;
//	ans--;//* 
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}