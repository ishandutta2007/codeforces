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
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}
int n;
char ss[100111];
string s[100111];
bool hs[256];
vector<string> anss;
vector<int> pos[256];
int ps[100111][26];
bool vis[100111];
char a[100];
bool has[256];
void dfs(int p,int x)
{
//	cout<<"dfs:"<<p<<" "<<x<<endl;
	vis[x]=1;
	for(int i=p;i<p+s[x].size();i++)
	{
		if(a[i]&&a[i]!=s[x][i-p])
		{
			puts("NO");
			exit(0);
		}
		if(!a[i])
		{
			a[i]=s[x][i-p];
			if(has[a[i]])
			{
				puts("NO");
				exit(0);
			}
			has[a[i]]=1;
			for(int j=0;j<pos[a[i]].size();j++)
			{
				int u=pos[a[i]][j];
				if(!vis[u])
				{
					dfs(i-ps[u][a[i]-'a'],u);
				}
			}
		}
	}
	
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",ss);
		int l=strlen(ss);
		if(l>26)
		{
			puts("NO");
			return 0;
		}
		for(int j=0;j<l;j++)
		{
			if(hs[ss[j]])
			{
				puts("NO");
				return 0;
			}
			hs[ss[j]]=1;
			ps[i][ss[j]-'a']=j;
		}
		for(int j=0;j<l;j++)s[i].PB(ss[j]);
		for(int j=0;j<l;j++)hs[ss[j]]=0;
		for(int j=0;j<l;j++)pos[ss[j]].PB(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			memset(a,0,sizeof(a));
			memset(has,0,sizeof(has));
			dfs(50,i);
			string ts="";
			for(int j=0;j<100;j++)
			{
				if(a[j])
				{
					ts=ts+a[j];
				}
			}
			anss.PB(ts);
		}
	}
	sort(anss.begin(),anss.end());
	for(int i=0;i<anss.size();i++)cout<<anss[i];
	return 0;
}