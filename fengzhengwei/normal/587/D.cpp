#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
char st;
const int xx=7e5+5e4+5;//15m=7e5+5e4() 
struct node{int next,to;}e[xx];
int cnt,h[xx];
void add(int x,int y)
{
	cnt++;e[cnt].next=h[x];
	h[x]=cnt;e[cnt].to=y;
}
int dfn[xx],low[xx],stk[xx],bel[xx],vis[xx],cst,top,scc;
void tj(int x)
{
	low[x]=dfn[x]=++cst;stk[++top]=x;vis[x]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(!dfn[e[i].to])tj(e[i].to),low[x]=min(low[x],low[e[i].to]);
		else if(vis[e[i].to])low[x]=min(low[x],dfn[e[i].to]);
	}
	if(dfn[x]==low[x])
	{
		scc++;
		while(stk[top]!=x)vis[stk[top]]=0,bel[stk[top--]]=scc;
		vis[stk[top]]=0,bel[stk[top--]]=scc;
	}
}
int n,m;
struct no
{
	int u,v,val,col,id;//idid 
	bool operator<(const no&w)const{return val<w.val;}
}q[xx];
int lsh[xx],tt,nt;//nt 
vector<int>v[xx],s[xx];// s 
void bdcol(vector<int>s)//sid buildcolor   2m
{
	for(auto it:s)v[q[it].u].push_back(it),v[q[it].v].push_back(it);
	for(auto it:s)
	{
		vector<int>p;
		for(auto x:v[q[it].u])if(x!=it)p.push_back(x);
		for(auto x:v[q[it].v])if(x!=it)p.push_back(x);
		sort(p.begin(),p.end());
		int sz=unique(p.begin(),p.end())-p.begin();
		if(sz>2)puts("No"),exit(0);// 
		for(int i=0;i<sz;i++)add(it*2-1,p[i]*2);//() 
		// 
	}
	for(auto it:s)v[q[it].u].clear(),v[q[it].v].clear();
}
int CNT,H[xx];
void cun()// 
{
	CNT=cnt;
	memcpy(H,h,sizeof(h));
}
void huan()// 
{
	cnt=CNT;
	memcpy(h,H,sizeof(h));
}
vector<int>ans;
bool check(int x)
{
	memset(dfn,0,sizeof(dfn));
	scc=0,cst=0,top=0;
	cun();
	for(int i=1;i<=m;i++)//*2-1 
	if(q[i].val>x)// 
	{
		for(int j=i;j<=m;j++)add(j*2,j*2-1);// //m
		break;
	}
	for(int i=1;i<=nt;i++)if(!dfn[i])tj(i);
	for(int i=1;i<=m;i++)if(bel[i*2]==bel[i*2-1])return huan(),0;
	ans.clear();
	for(int i=1;i<=m;i++)if(bel[i*2]<bel[i*2-1])ans.push_back(i);
	return huan(),1;
}
vector<int>pre[xx],suf[xx];
int tou[xx],tov[xx];
char ed;
signed main(){
//	freopen("a.in","r",stdin);
//	cerr<<(&st-&ed)/1024/1024<<"\n";
	n=read(),m=read();
	for(int i=1;i<=m;i++)q[i].u=read(),q[i].v=read(),q[i].col=lsh[++tt]=read(),q[i].val=read(),q[i].id=i;
	sort(lsh+1,lsh+tt+1);
	tt=unique(lsh+1,lsh+tt+1)-lsh-1;
	for(int i=1;i<=m;i++)q[i].col=lower_bound(lsh+1,lsh+tt+1,q[i].col)-lsh;
	sort(q+1,q+m+1);//v 
	for(int i=1;i<=m;i++)s[q[i].col].push_back(i);
	for(int i=1;i<=tt;i++)bdcol(s[i]);// 
//	if(m==50000)return 0;
	nt=m+m;
	for(int i=1;i<=m;i++)
	{
		v[q[i].u].push_back(i);
		tou[i]=v[q[i].u].size()-1;
		v[q[i].v].push_back(i);
		tov[i]=v[q[i].v].size()-1;
	}
	for(int i=1;i<=n;i++)//i*2-1   8m
	{
		if(!v[i].size())continue;
		pre[i].push_back(v[i][0]*2-1);
		int sz=v[i].size();
		for(int j=1;j<sz;j++)
		{
			++nt;add(nt,pre[i][j-1]);add(nt,v[i][j]*2-1);
			pre[i].push_back(nt);
		}
		suf[i].resize(sz);
		suf[i][sz-1]=v[i][sz-1]*2-1;
		for(int j=sz-2;j>=0;j--)
		{
			++nt;add(nt,suf[i][j+1]),add(nt,v[i][j]*2-1);
			suf[i][j]=nt;
		}
	}
	for(int i=1;i<=m;i++)//4m
	{
		if(tou[i]!=0)add(i*2,pre[q[i].u][tou[i]-1]);
		if(tou[i]!=v[q[i].u].size()-1)add(i*2,suf[q[i].u][tou[i]+1]);
		if(tov[i]!=0)add(i*2,pre[q[i].v][tov[i]-1]);
		if(tov[i]!=v[q[i].v].size()-1)add(i*2,suf[q[i].v][tov[i]+1]);
	}
	
	int l=0,r=m,Ans=-1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(q[mid].val))Ans=mid,r=mid-1;
		else l=mid+1;
	}
	if(Ans==-1)puts("No"),exit(0);
	puts("Yes");
	cout<<q[Ans].val<<" "<<ans.size()<<"\n";
	for(auto it:ans)cout<<q[it].id<<" ";puts("");
	return 0;
}