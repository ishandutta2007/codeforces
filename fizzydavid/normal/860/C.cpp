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
string hhh;
int n,sl,en;
char s[11];
string a[100111];
int ty[100111];
set<string> st,st2,allnum;
map<string,int>tst;
string tos(int x)
{
	string ret="";
	while(x>0)ret+=char('0'+x%10),x/=10;
	reverse(ret.begin(),ret.end());
	return ret;
}
bool ok[100111];
string goal[100111];
int nxt[100111];
int vis[100111],visn;
vector<pair<string,string> >cmd;
void dfs(int x)
{
	if(vis[x])return;
	vis[x]=visn;
	if(ty[x]==1)
	{
		if(st.size()>0)
		{
			goal[x]=*st.begin();
			st.erase(st.begin());
		}
		else goal[x]=hhh;
	}
	else if(ty[x]==0)
	{
		if(st2.size()>0)
		{
			goal[x]=*st2.begin();
			st2.erase(st2.begin());
		}
		else goal[x]=hhh;
	}
	nxt[x]=tst[goal[x]];
	if(nxt[x]==0)
	{
		cmd.PB(MP(a[x],goal[x]));
		return;
	}
	dfs(nxt[x]);
	cmd.PB(MP(a[x],goal[x]));
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		sl=strlen(s);
		a[i]="";
		for(int j=0;j<sl;j++)a[i]+=s[j];
		scanf("%d",&ty[i]);
		if(ty[i]==1)en++;
		tst[a[i]]=i;
	}
	hhh="aaaaaa";
	while(tst.find(hhh)!=tst.end())
	{
		hhh[0]++;
		int it=0;
		while(hhh[it]>'z')hhh[it]='a',hhh[++it]++;
	}
	
	for(int i=1;i<=en;i++)st.insert(tos(i));
	for(int i=en+1;i<=n;i++)st2.insert(tos(i));
	for(int i=1;i<=n;i++)allnum.insert(tos(i));
	
	int cnt1=en,cnt2=n-en;
	for(int i=1;i<=n;i++)
	{
		if(ty[i]==1)
		{
			if(st.find(a[i])!=st.end())
			{
				st.erase(a[i]);
				ok[i]=1;
				cnt1--;
			}
		}
		else
		{
			if(st2.find(a[i])!=st2.end())
			{
				st2.erase(a[i]);
				ok[i]=1;
				cnt2--;
			}
		}
	}
	
	int op1=0,op2=1;
	if(cnt1<cnt2)swap(op1,op2);
	
	for(int i=1;i<=n;i++)
	{
		if(ok[i])continue;
		if(vis[i])continue;
		if(ty[i]!=op1)continue;
		if(allnum.find(a[i])==allnum.end())continue;
		++visn;
		bool f0=st.find(a[i])!=st.end(),f1=st2.find(a[i])!=st2.end();
		if(f0)st.erase(a[i]);
		if(f1)st2.erase(a[i]);
		dfs(i);
		if(f0)st.insert(a[i]);
		if(f1)st2.insert(a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(ok[i])continue;
		if(vis[i])continue;
		if(ty[i]!=op2)continue;
		if(allnum.find(a[i])==allnum.end())continue;
		++visn;
		bool f0=st.find(a[i])!=st.end(),f1=st2.find(a[i])!=st2.end();
		if(f0)st.erase(a[i]);
		if(f1)st2.erase(a[i]);
		dfs(i);
		if(f0)st.insert(a[i]);
		if(f1)st2.insert(a[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		if(ok[i])continue;
		if(vis[i])continue;
		++visn;
		bool f0=st.find(a[i])!=st.end(),f1=st2.find(a[i])!=st2.end();
		if(f0)st.erase(a[i]);
		if(f1)st2.erase(a[i]);
		dfs(i);
		if(f0)st.insert(a[i]);
		if(f1)st2.insert(a[i]);
	}
	
	string tmp;
	if(st.size()>0)tmp=*st.begin();
	if(st2.size()>0)tmp=*st2.begin();
	for(int i=1;i<=n;i++)if(goal[i]==hhh)cmd.PB(MP(goal[i],tmp));
	
	printf("%d\n",int(cmd.size()));
	for(int i=0;i<cmd.size();i++)
	{
		printf("move %s %s\n",cmd[i].FF.c_str(),cmd[i].SS.c_str());
	}
	return 0;
}