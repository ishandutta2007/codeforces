#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 998244353
#define MAXN 21
#define MAXM 50001
int N,M,cnt[MAXM][MAXN],ans;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int pow(int a,int b){int ans=1;while(b)b&1?ans=1ll*ans*a%P:0,a=1ll*a*a%P,b>>=1;return ans;}
int main()
{
	N=get(),M=get();For(i,1,N)For(j,1,M)cnt[j][N+1-get()]++;int x=1;For(i,1,N)x=1ll*x*i%P;x=pow(x,P-2);
	For(i,1,M){int sum=0,now=1;For(j,0,N-1)sum+=cnt[i][j],now=1ll*now*(sum-j)%P;ans=(ans+1-1ll*now*x%P+P)%P;}cout<<ans<<endl;return 0;
}