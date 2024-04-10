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
bool no[26];
int cnt;
void setno(int x)
{
	if(!no[x])
	{
		no[x]=1;
		cnt++;
	}
}
char s[100111];

int main()
{
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<n;i++)
	{
		char cmd[10];
		scanf("%s",cmd);
		if(cmd[0]=='!')
		{
			ans+=cnt==25;
			scanf("%s",s);
			int l=strlen(s);
			int msk=0;
			for(int j=0;j<l;j++)
			{
				msk|=1<<(s[j]-'a');
			}
			for(int j=0;j<26;j++)if(!((msk>>j)&1))setno(j);
		}
		else if(cmd[0]=='.')
		{
			scanf("%s",s);
			int l=strlen(s);
			int msk=0;
			for(int j=0;j<l;j++)
			{
				msk|=1<<(s[j]-'a');
			}
			for(int j=0;j<26;j++)if(((msk>>j)&1))setno(j);
		}
		else if(cmd[0]=='?')
		{
			ans+=cnt==25;
			scanf("%s",s);
			setno(s[0]-'a');
		}
	}
	cout<<ans<<endl;
	return 0;
}