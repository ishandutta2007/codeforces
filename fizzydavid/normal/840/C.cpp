//by yjz
#include<bits/stdc++.h>
#include<queue>
#include<ctime>
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
int n,a[333],v[333],vn;
map<int,int>mp;
int C[633][633],fac[633];
int dp[333][333];
int main()
{
	fac[0]=1;
	for(int i=1;i<605;i++)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=0;i<=605;i++)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	geti(n);
	for(int i=1;i<=n;i++)
	{
		geti(a[i]);
		for(int j=2;1ll*j*j<=a[i];j++)
		{
			while(a[i]%(j*j)==0)a[i]/=j*j;
		}
		mp[a[i]]++;
	}
	foreach(it,mp)v[++vn]=it->SS;
//	cout<<"vn="<<vn<<endl;
//	for(int i=1;i<=vn;i++)cout<<v[i]<<" ";cout<<endl;
	dp[1][v[1]-1]=fac[v[1]];
	int sum=v[1];
	for(int i=2;i<=vn;i++)
	{
		for(int j=0;j<sum;j++)
		{
			int lft=sum+1-j;
			int &pv=dp[i-1][j];
			if(pv==0)continue;
			for(int k=0;k<=j;k++)
			{
				for(int l=0;l<=lft&&k+l<=v[i];l++)
				{
//					cerr<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
					int &nv=dp[i][j-k+v[i]-k-l];
//					cout<<pv<<" "<<C[j][k]<<" "<<C[lft][l]<<" "<<C[v[i]-k-l+k+l-1][k+l]<<" "<<fac[v[i]]<<endl;
					nv=(nv+1ll*pv*C[j][k]%mod*C[lft][l]%mod*C[v[i]-k-l+k+l-1][k+l-1]%mod*fac[v[i]])%mod;
				}
			}
		}
		sum+=v[i];
	}
	cout<<dp[vn][0]<<endl;
	return 0;
}