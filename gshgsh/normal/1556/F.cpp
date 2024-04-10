#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 14
int N,a[MAXN],siz[1<<MAXN],f[1<<MAXN],beat[MAXN][MAXN],ans;
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int g(int a,int b){int ans=1;For(i,0,N-1)if((a>>i)&1)For(j,0,N-1)if((b>>j)&1)ans=1ll*ans*beat[i][j]%P;return ans;}
int main()
{
	cin>>N;For(i,0,N-1)cin>>a[i];For(i,0,N-1)For(j,0,N-1)if(i!=j)beat[i][j]=1ll*a[i]*pow(a[i]+a[j],P-2)%P;For(i,1,(1<<N)-1)siz[i]=siz[i>>1]+(i&1);
	For(i,1,(1<<N)-1){for(int j=i-1&i;j;j=j-1&i)f[i]=(f[i]+1ll*f[j]*g(j,j^i))%P;f[i]=(P+1-f[i])%P;ans=(ans+1ll*siz[i]*f[i]%P*g(i,i^(1<<N)-1))%P;}
	cout<<ans<<'\n';return 0;
}