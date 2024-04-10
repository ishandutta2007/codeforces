#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
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
int n,m;
// 
const int xx=4e5+5;
struct nod{int next,to;}e[xx<<3];//tarjan 
vector<vector<int> >mp;
struct node{int id,h;bool operator<(const node&w)const{return h<w.h;};};
vector<vector<node> >col;//icolumn 
int a[xx],cst,cnt,h[xx];
vector<pair<int,int> >eg;
int O=0;
void add(int x,int y)
{
	if(!O)eg.push_back(make_pair(x,y));
//	if(cnt%1000==0)cout<<x<<" sss "<<y<<" "<<cnt<<"\n";
	cnt++,e[cnt].next=h[x];
	h[x]=cnt,e[cnt].to=y;
}
int dfn[xx],low[xx],bel[xx],stk[xx],vis[xx],mx[xx],mn[xx],scc,top,Cst;// 
void tarjan(int x)
{
//	cerr<<x<<"\n";
	dfn[x]=low[x]=++Cst;stk[++top]=x,vis[x]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(!dfn[e[i].to])tarjan(e[i].to),low[x]=min(low[x],low[e[i].to]);
		else if(vis[e[i].to])low[x]=min(low[x],dfn[e[i].to]);
	}
	if(dfn[x]==low[x])
	{
		scc++;
		while(stk[top]!=x)vis[stk[top]]=0,bel[stk[top--]]=scc;
		vis[stk[top]]=0,bel[stk[top--]]=scc;
	}
}
signed main(){
//	freopen("a.in","r",stdin);
	memset(mx,-0x3f,sizeof(mx));
	memset(mn,0x3f,sizeof(mn));
	n=read(),m=read();
	mp.resize(n+2);
	for(int i=1;i<=n+1;i++)mp[i].resize(m+2);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char c;
			while((c=getchar())!='.'&&c!='#');
			mp[i][j]=(c=='#');
		}
	}
	for(int i=1;i<=m;i++)a[i]=read();
	col.resize(m+2);
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++)if(mp[i][j])col[j].push_back((node){++cst,i});
//    for(int j=1;j<=m;j++)
//    {
//    	for(auto it:col[j])cout<<it.id<<" "<<it.h<<" "<<j<<"\n";
//	}
    for(int j=1;j<=m;j++)
    {
    	for(int i=col[j].size()-2;i>=0;i--)// 
    		add(col[j][i+1].id,col[j][i].id);
//			,puts("DD");
    	for(int i=0;i<col[j].size();i++)// 
    	{
//    		cout<<i<<" "<<j<<"\n";
    		if(i!=0&&col[j][i].h==col[j][i-1].h+1)add(col[j][i-1].id,col[j][i].id);
//			,puts("CC");
    		vector<node>::iterator it=lower_bound(col[j-1].begin(),col[j-1].end(),(node){0,col[j][i].h});
    		if(it!=col[j-1].end())add(it->id,col[j][i].id);
//			,puts("AA");
    		it=lower_bound(col[j+1].begin(),col[j+1].end(),(node){0,col[j][i].h});
    		if(it!=col[j+1].end())add(it->id,col[j][i].id);
//			,puts("BB");
		}
	}
//	cout<<cst<<"\n";
	for(int i=1;i<=cst;i++)if(!dfn[i])tarjan(i);
	for(int j=1;j<=m;j++)
	{
		if(!col[j].size())continue;
		mx[bel[col[j][0].id]]=max(mx[bel[col[j][0].id]],j);
		mn[bel[col[j][0].id]]=min(mn[bel[col[j][0].id]],j);
	}
//	cout<<bel[5]<<"www \n";
	memset(e,0,sizeof(e[0])*(cnt+1));
	memset(h,0,sizeof(h));
	cnt=0,O=1;
	for(auto it:eg)if(bel[it.first]!=bel[it.second])add(bel[it.first],bel[it.second]);
	for(int x=1;x<=scc;x++)// 
	{
		for(int i=h[x];i;i=e[i].next)
		{
			mx[x]=max(mx[x],mx[e[i].to]);
			mn[x]=min(mn[x],mn[e[i].to]);
		}
	}
	int last=0,ans=0,Mx=1e9;
	for(int i=1;i<=m;i++)//j 
	{
		if(!col[i].size())continue;
		if(a[i])
		{
			int x=col[i][col[i].size()-a[i]].id;
			if(mn[bel[x]]<=last);
			else Mx=min(Mx,mx[bel[x]]);
		}
		if(Mx==i)last=i,ans++,Mx=1e9;
//		cout<<mn[bel[x]]<<" "<<mx[bel[x]]<<" "<<Mx<<" "<<last<<"\n";
	}
	cout<<ans<<'\n';
	return 0;
}