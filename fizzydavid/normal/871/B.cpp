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
int n;
int ask(int x,int y)
{
	printf("? %d %d\n",x,y);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int a[5011],b[5011];
int A[5011],B[5011];
bool hs[5011];
int tans[5011];
bool check()
{
	memset(hs,0,sizeof(hs));
	for(int i=0;i<n;i++)
	{
		if(A[i]<0||A[i]>=n||hs[A[i]])return false;
		hs[A[i]]=1;
	}
	memset(hs,0,sizeof(hs));
	for(int i=0;i<n;i++)
	{
		if(B[i]<0||B[i]>=n||hs[B[i]])return false;
		hs[B[i]]=1;
	}
	for(int i=0;i<n;i++)
	{
		if(A[B[i]]!=i)return false;
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		a[i]=ask(i,0);
	}
	for(int i=0;i<n;i++)
	{
		b[i]=ask(0,i);
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		A[0]=i;B[0]=A[0]^a[0];
		for(int j=1;j<n;j++)
		{
			A[j]=A[0]^a[0]^a[j];
			B[j]=B[0]^b[0]^b[j];
		}
		if(check())
		{
			cnt++;
			for(int j=0;j<n;j++)tans[j]=A[j];
		}
	}
	printf("!\n");
	printf("%d\n",cnt);
	for(int i=0;i<n;i++)printf("%d%c",tans[i],i+1<n?' ':'\n');
	fflush(stdout);
	return 0;
}