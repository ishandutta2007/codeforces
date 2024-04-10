#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define M 20
int N,a[1<<M],f[1<<M],ans;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int main()
{
	N=get();For(i,1,N)a[get()]++;For(i,0,M-1)FOR(j,(1<<M)-1,0)if(!(j>>i&1))a[j]+=a[j|1<<i];For(i,0,(1<<M)-1)f[i]=pow(2,a[i])-1;
	For(i,0,(1<<M)-1)ans=(ans+1ll*(__builtin_popcount(i)&1?P-1:1)*f[i])%P;cout<<ans<<'\n';return 0;
}