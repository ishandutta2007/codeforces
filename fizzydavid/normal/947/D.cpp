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
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
char s[100111],t[100111];
int pres[100111],pret[100111];
int cnts[100111],cntt[100111];
int n,m;
bool ans[100111];
int main()
{
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	for(int i=1;i<=n;i++)pres[i]+=pres[i-1]+(s[i]!='A');
	for(int i=1;i<=m;i++)pret[i]+=pret[i-1]+(t[i]!='A');
	for(int i=1;i<=n;i++)cnts[i]=(s[i]=='A'?cnts[i-1]+1:0);
	for(int i=1;i<=m;i++)cntt[i]=(t[i]=='A'?cntt[i-1]+1:0);
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int sl,sr,tl,tr;
		scanf("%d%d%d%d",&sl,&sr,&tl,&tr);
		int a=pres[sr]-pres[sl-1];
		int b=pret[tr]-pret[tl-1];
		int a2=min(sr-sl+1,cnts[sr]);
		int b2=min(tr-tl+1,cntt[tr]);
		if(a==0)
		{
			if(b==0)
			{
				ans[i]=(a2>=b2&&(a2-b2)%3==0);
			}
			else
			{
				ans[i]=(b%2==0&&a2>b2);
			}
		}
		else
		{
			if(a2<b2)ans[i]=0;
			else if(a2==b2)
			{
				ans[i]=a<=b&&(b-a)%2==0;
			}
			else
			{
				if((a2-b2)%3==0)ans[i]=a<=b&&(b-a)%2==0;
				else
				{
					a+=2;
					ans[i]=a<=b&&(b-a)%2==0;
				}
			}
		}
	}
	for(int i=1;i<=q;i++)putchar('0'+ans[i]);
	return 0;
}