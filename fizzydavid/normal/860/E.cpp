//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c==' '||c=='\n')c=_buff.get();return c;}
int n,p[500111],lv[500111];
vector<int>con[500111];
int head[500111],to[500111],nxt[500111],etot;
int q[500111],qn,qid[500111];
void adde(int x,int y)
{
	nxt[++etot]=head[x];
	head[x]=etot;
	to[etot]=y;
}
int mxl[500111],mxu[500111],st[500111],csz[500111];
pair<pair<int,int>,int> tab[500111];
ll ans[500111];
void merge(int x,int y,ll coef)//y to x
{
	ans[tab[x].FF.FF-1]-=tab[y].SS*coef;
	ans[tab[x].FF.SS]+=tab[y].SS*coef;
	ans[tab[y].FF.FF-1]-=tab[x].SS*coef;
	ans[tab[y].FF.SS]+=tab[x].SS*coef;
	tab[x].FF.FF=min(tab[x].FF.FF,tab[y].FF.FF);
	tab[x].FF.SS=max(tab[x].FF.SS,tab[y].FF.SS);
	tab[x].SS+=tab[y].SS;
}

int tmp[500111],tmpsz;
int main()
{
	geti(n);
	int rt=0;
	for(int i=1;i<=n;i++)
	{
		geti(p[i]);
		if(p[i]==0)rt=i;
		con[p[i]].PB(i);
	}
	q[++qn]=rt;lv[1]=1;p[1]=0;
	for(int i=1;i<=qn;i++)
	{
		int u=q[i];
		qid[u]=i;
		for(int j=0;j<con[u].size();j++)
		{
			int v=con[u][j];
			q[++qn]=v;
			p[qn]=i;
			adde(i,qn);
			lv[qn]=lv[i]+1;
		}
	}
	for(int x=n;x>=1;x--)
	{
		mxl[x]=x;
		for(int i=head[x];i;i=nxt[i])
		{
			int u=to[i];
			if(lv[mxl[u]]>lv[mxl[x]])mxl[x]=mxl[u],mxu[x]=u;
		}
		csz[x]=lv[mxl[x]]-lv[x];
		st[mxl[x]+1]++;
	}
	for(int i=1;i<=n;i++)st[i]+=st[i-1];
	for(int x=n;x>=1;x--)
	{
		int g=mxl[x];
		tmpsz=0;
		for(int i=head[x];i;i=nxt[i])
		{
			tmp[tmpsz++]=to[i];
			if(mxu[x]==to[i])reverse(tmp,tmp+tmpsz);
		}
		for(int i=1;i<tmpsz;i++)
		{
			int u=tmp[i];
			for(int j=0;j<=csz[u];j++)
			{
				int k=csz[x]-1-(csz[u]-j);
				merge(st[g]+k,st[mxl[u]]+j,lv[x]);
			}
		}
		tab[st[g]+csz[x]]=MP(MP(x,x),1);
	}
	for(int i=n;i>=1;i--)ans[i]+=ans[i+1];
	for(int i=2;i<=n;i++)ans[i]+=ans[p[i]]+lv[i]-1;
	for(int i=1;i<=n;i++)puti(ans[qid[i]]);
	return 0;
}