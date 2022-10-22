#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 998244853
#define MAXN 1000001
int N,K,a[MAXN],cnt[MAXN],f[MAXN],ans;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int main()
{
	N=get();For(i,1,N)a[i]=get(),K=max(K,a[i]),cnt[a[i]]++;
	FOR(i,K,1){int c=0;for(int j=i;j<=K;j+=i)c+=cnt[j];f[i]=pow(2,c)-1;for(int j=i*2;j<=K;j+=i)f[i]=(f[i]-f[j]+P)%P;}
	ans=-N;For(i,1,K)ans+=f[i]!=0;cout<<ans<<'\n';return 0;
}