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
int n;
bool query(int R1,int C1,int R2,int C2,bool rev=0)
{
	if(rev)swap(R1,R2),swap(C1,C2);
	printf("? %d %d %d %d\n",R1,C1,R2,C2);
	fflush(stdout);
	char s[5];
	scanf("%s",s);
	if(s[0]=='B')exit(0);
	if(s[0]=='Y')return true;else return false;
}
vector<pair<int,int> > solve(int sx,int sy,int tx,int ty,int d1x,int d1y,int d2x,int d2y,bool rev=0)
{
	vector<pair<int,int> > ret;
	int x=sx,y=sy;
	ret.PB(MP(sx,sy));
	for(int i=1;i<n;i++)
	{
		int nx,ny;
		nx=x+d1x,ny=y+d1y;
		if(query(nx,ny,tx,ty,rev))
		{
			x=nx;y=ny;
		}
		else
		{
			nx=x+d2x,ny=y+d2y;
			if(query(nx,ny,tx,ty,rev))
			{
				x=nx;y=ny;
			}
			else assert(false);
		}
		ret.PB(MP(x,y));
	}
	return ret;
}
void out(vector<pair<int,int> > &v)
{
	for(int i=0;i+1<v.size();i++)
	{
		if(v[i+1].FF==v[i].FF)putchar('R');
		else putchar('D');
	}
}
int main()
{
	scanf("%d",&n);
	vector<pair<int,int> > v1,v2;
	v1=solve(1,1,n,n,1,0,0,1);
	v2=solve(n,n,1,1,0,-1,-1,0,1);
	reverse(v2.begin(),v2.end());
	printf("! ");
	out(v1);out(v2);
	puts("");
	fflush(stdout);
	return 0;
}