#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
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
int n;
map<string,int>mp;
void clear(char *s)
{
	int p=strlen(s);
	for(int i=0;i<p;i++)
	{
		if(s[i]>='A'&&s[i]<='Z')
			s[i]=s[i]-'A'+'a';
	}
}
const int xx=5e5+5;
char s[xx];
struct node{int next,to;}e[xx<<1];
int cnt,h[xx],tt;
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
ll len[xx],R[xx];
void in(char *s)
{
	if(!mp[s])
	{
		mp[s]=++tt;
		len[tt]=strlen(s);
		for(int i=0;i<len[tt];i++)if(s[i]=='r')R[tt]++;
	}
}
int dfn[xx],cst,scc,top,stk[xx],vis[xx],low[xx],bel[xx];
pair<ll,ll>val[xx];
void tj(int x)
{
	dfn[x]=low[x]=++cst;
	stk[++top]=x;vis[x]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(!dfn[e[i].to])
		{
			tj(e[i].to);
			low[x]=min(low[x],low[e[i].to]);
		}
		else if(vis[e[i].to])low[x]=min(low[x],dfn[e[i].to]);
	}
	if(dfn[x]==low[x])
	{
		scc++;
		while(stk[top]!=x)
		{
			bel[stk[top]]=scc,vis[stk[top]]=0,
			val[scc]=min(val[scc],make_pair(R[stk[top]],len[stk[top]]));
			top--;
		}
		bel[stk[top]]=scc,vis[stk[top]]=0,
		val[scc]=min(val[scc],make_pair(R[stk[top]],len[stk[top]]));
		top--;
	}
}
vector<int>v;
signed main(){
	memset(val,0x3f,sizeof(val));
	n=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		clear(s);
		in(s);
		v.push_back(mp[s]);
	}
	int m=read();
	vector<pair<int,int> >P;
	for(int i=1;i<=m;i++)
	{
		scanf("%s",s);
		clear(s);
		in(s);
		int a=mp[s];
		scanf("%s",s);
		clear(s);
		in(s);
		add(a,mp[s]);
		P.push_back(make_pair(a,mp[s]));
	}
	for(int i=1;i<=tt;i++)if(!dfn[i])tj(i);
	memset(e,0,sizeof(e[0])*(cnt+1));
	memset(h,0,sizeof(h[0])*(tt+1));
	cnt=0;
	for(auto it:P)
		if(bel[it.first]!=bel[it.second])add(bel[it.first],bel[it.second]);
	for(int x=1;x<=scc;x++)
	{
		for(int i=h[x];i;i=e[i].next)
			val[x]=min(val[x],val[e[i].to]);
	}
	ll ans1=0,ans2=0;
	for(int i=1;i<=n;i++)
		ans1+=val[bel[v[i-1]]].first,ans2+=val[bel[v[i-1]]].second;
	cout<<ans1<<" "<<ans2<<"\n";
	return 0;
}