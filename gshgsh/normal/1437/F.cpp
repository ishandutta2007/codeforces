#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 998244353
#define MAXN 5001
int N,a[MAXN],b[MAXN],fc[MAXN],inv[MAXN],f[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int main()
{
	N=get();For(i,1,N)a[i]=get();sort(a+1,a+N+1);For(i,1,N)while(a[b[i]+1]*2<=a[i])b[i]++;b[0]=-1;
	fc[0]=1;For(i,1,N)fc[i]=1ll*fc[i-1]*i%P;inv[N]=pow(fc[N],P-2);FOR(i,N-1,0)inv[i]=1ll*inv[i+1]*(i+1)%P;f[0]=1;
	For(i,1,N)For(j,0,b[i])f[i]=(f[i]+1ll*f[j]*fc[N-b[j]-2]%P*inv[N-b[i]-1])%P;cout<<(b[N]==N-1?f[N]:0)<<'\n';
}