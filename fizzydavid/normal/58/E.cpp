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
char s1[30],s2[30],s3[30],s[30]; 
int l1,l2,l3;
int dp[23][9][9][9][2];
ll pre[23][9][9][9][2];
ll encode(int a,int b,int c,int d,int e,int f,int g)
{
	ll ret=0;
	ret=ret<<5|a;
	ret=ret<<5|b;
	ret=ret<<5|c;
	ret=ret<<5|d;
	ret=ret<<5|e;
	ret=ret<<5|f;
	ret=ret<<5|g;
	return ret;
}
void decode(ll ret,int &a,int &b,int &c,int &d,int &e,int &f,int &g)
{
	g=ret&31;ret>>=5;
	f=ret&31;ret>>=5;
	e=ret&31;ret>>=5;
	d=ret&31;ret>>=5;
	c=ret&31;ret>>=5;
	b=ret&31;ret>>=5;
	a=ret&31;
}
int A[30],B[30],C[30];
void dfs(ll msk,int l=0)
{
	int a,b,c,d,e,f,g;
	decode(msk,a,b,c,d,e,f,g);
//	cerr<<a<<","<<b<<","<<c<<","<<d<<","<<e<<" "<<f<<" "<<g<<endl;
	if(a>0)dfs(pre[a][b][c][d][e],l+1);
	if(l>0)
	{
		A[a]=f%10;
		B[a]=g%10;
	}
}
void out(int s[])
{
	bool fb=0;
	for(int i=29;i>=0;i--)
	{
		if(s[i]>0)fb=1;
		if(fb)putchar('0'+s[i]);
	}
}
int main()
{
	scanf("%s",s);
	int l=strlen(s);
	int tit=0;
	while(s[tit]!='+')s1[l1++]=s[tit++];tit++;
	while(s[tit]!='=')s2[l2++]=s[tit++];tit++;
	while(tit<l)s3[l3++]=s[tit++];
	reverse(s1,s1+l1);
	reverse(s2,s2+l2);
	reverse(s3,s3+l3);
	
	memset(dp,31,sizeof(dp));
	dp[0][0][0][0][0]=0;
	int ans=23333333;
	ll ansmsk;
	for(int i=0;i<22;i++)
	{
		for(int j1=0;j1<=l1+1;j1++)
		{
			for(int j2=0;j2<=l2+1;j2++)
			{
				for(int j3=0;j3<=l3;j3++)
				{
					for(int t=0;t<2;t++)
					{
						int &cur=dp[i][j1][j2][j3][t];
						if(cur>2333333)continue;
						if(j1>=l1&&j2>=l2&&j3>=l3&&cur<ans)
						{
							ans=cur;
							ansmsk=encode(i,j1,j2,j3,t,0,0);
						}
						for(int v1=0;v1<=10;v1++)
						{
							if(v1==10&&j1<l1||v1<10&&j1==l1+1)continue;
							for(int v2=0;v2<=10;v2++)
							{
								if(v2==10&&j2<l2||v2<10&&j2==l2+1)continue;
								int cost=(v1<10)+(v2<10);
								int nj1=j1,nj2=j2,nj3=j3;
								if(v1==10&&j1==l1||v1==s1[j1]-'0')nj1++;
								if(v2==10&&j2==l2||v2==s2[j2]-'0')nj2++;
								if((v1%10+v2%10+t)%10==s3[j3]-'0')nj3++;
								int nt=v1%10+v2%10+t>=10;
								if(dp[i+1][nj1][nj2][nj3][nt]>cur+cost)
								{
									dp[i+1][nj1][nj2][nj3][nt]=cur+cost;
									pre[i+1][nj1][nj2][nj3][nt]=encode(i,j1,j2,j3,t,v1,v2);
								}
							}
						}
					}
				}
			}
		}
	}
//	cerr<<"ans="<<ans<<endl;
	dfs(ansmsk);
	for(int i=0;i<29;i++)
	{
		C[i+1]+=(C[i]+A[i]+B[i])/10;
		C[i]=(C[i]+A[i]+B[i])%10;
	}
	out(A);putchar('+');out(B);putchar('=');out(C);
	return 0;
}