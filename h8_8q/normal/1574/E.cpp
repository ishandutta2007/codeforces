#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>
 
#define int long long
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f3f3f3f3f
 
using namespace std;
 
inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}
 
inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}
 
template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}
 
const int N=1e6+5,mod=998244353;
int n,m,q,sm1[N][2],sm2[N][2],q1,q2,s1,s2,s3,s4;
 
map<pair<int,int>,int> a;
 
inline void del(int x,int y)
{
	int qwq=a[mp(x,y)];
	if(qwq!=0)
	{
		if(qwq==2) qwq=0;
		if((x+y)%2==qwq) q1--;
		if((x+y)%2==(qwq^1)) q2--;
		sm1[x][qwq^(y&1)]--;
		if(sm1[x][qwq^(y&1)]==0&&sm1[x][qwq^(y&1)^1]==0) s3++;
		else if(sm1[x][qwq^(y&1)]==0&&sm1[x][qwq^(y&1)^1]!=0) s1--;
		sm2[y][qwq^(x&1)]--;
		if(sm2[y][qwq^(x&1)]==0&&sm2[y][qwq^(x&1)^1]==0) s4++;
		else if(sm2[y][qwq^(x&1)]==0&&sm2[y][qwq^(x&1)^1]!=0) s2--;
		a[mp(x,y)]=0;
	}
}
 
inline void upd(int x,int y,int v)
{
	a[mp(x,y)]=v;
	if(v==2) v=0;
	if((x+y)%2==v) q1++;
	if((x+y)%2==(v^1)) q2++;
	if(sm1[x][v^(y&1)]==0&&sm1[x][v^(y&1)^1]==0) s3--;
	else if(sm1[x][v^(y&1)]==0&&sm1[x][v^(y&1)^1]!=0) s1++;
	sm1[x][v^(y&1)]++;
	if(sm2[y][v^(x&1)]==0&&sm2[y][v^(x&1)^1]==0) s4--;
	else if(sm2[y][v^(x&1)]==0&&sm2[y][v^(x&1)^1]!=0) s2++;
	sm2[y][v^(x&1)]++;
}
 
inline int q_pow(int a,int b)
{
	int c=1;
	while(b)
	{
		if(b&1) c=a*c%mod;
		a=a*a%mod;b>>=1;
	}
	return c;
}
 
signed main()
{
	//freopen("yangli.in","r",stdin);
	//freopen("std.out","w",stdout);
	n=read();m=read();q=read();
	s3=n;s4=m;
	while(q--)
	{
		int x=read(),y=read(),p=read();
		del(x,y);
		if(p!=-1)
			upd(x,y,p+1);
		if(s1!=0&&s2!=0)
			printf("0\n");
		else if(s1!=0)
			printf("%lld\n",q_pow(2,s4));
		else if(s2!=0)
			printf("%lld\n",q_pow(2,s3));
		else
		{
			int jian=(q1==0)+(q2==0);
			printf("%lld\n",(q_pow(2,s3)+q_pow(2,s4)-jian+mod)%mod);
		}
	}
	return 0;
}