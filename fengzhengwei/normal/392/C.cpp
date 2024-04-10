#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
ll n,k;
const int mod=1e9+7;
struct matrix
{
	ll a[88][88];
	matrix(){memset(a,0,sizeof(a));}
	void operator*(const matrix&w)
	{
		matrix s;
		for(int i=1;i<=k+k+3;i++)
		{
			for(int K=1;K<=k+k+3;K++)
			{
				ll ss=a[i][K];
				for(int j=1;j<=k+k+3;j++)
				{
					s.a[i][j]+=ss*w.a[K][j];
					s.a[i][j]%=mod;
				}
			}
		}
		for(int i=1;i<=k+k+3;i++)for(int j=1;j<=k+k+3;j++)a[i][j]=s.a[i][j];
	}
	void print()
	{
		for(int i=1;i<=k+k+3;i++)
		
			for(int j=1;j<=k+k+3;j++)cout<<a[i][j]<<" \n"[j==k+k+3];
		puts("");
	}
}ans,zy;
ll C[45][45];
//y=x+1
//a*x^0 a*x^1 a*x^2 a*x^3  a*x^k b*y^0 b*y^1 b*y^2 b*y^3 b*y^k   sum
// 1      2     3     4         k+1   k+2   k+3   k+4   k+5      k+k+2  k+k+3
signed main(){
	n=read();
	k=read();
	if(n==1)return puts("1"),0;
	for(int i=0;i<=k;i++)C[i][0]=1;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	for(int i=1;i<=k+1;i++)ans.a[1][i]=1;
	for(int i=0;i<=k;i++)ans.a[1][i+k+2]=(1ll<<(i+1))%mod;
	ans.a[1][k+k+3]=ans.a[1][k+1];
	zy.a[k+k+3][k+k+3]=1;
	zy.a[k+k+2][k+k+3]=1;
	for(int i=k+2;i<=k+k+2;i++)zy.a[i][i-k-1]=1;
	for(int i=k+2;i<=k+k+2;i++)// 
	{
		for(int j=0;j<=i-k-2;j++)zy.a[j+1][i]+=C[i-k-2][j]*((1ll<<(i-k-2-j))%mod)%mod;
		for(int j=0;j<=i-k-2;j++)zy.a[j+k+2][i]+=C[i-k-2][j];
	}
	n-=1;
	while(n)
	{
		if(n&1)ans*zy;
		zy*zy;
		n>>=1;
	}
	cout<<ans.a[1][k+k+3]<<'\n';
	return 0;
}