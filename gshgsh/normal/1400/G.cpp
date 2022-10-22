#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
#include<set>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 998244353
#define MAXN 500001
int N,M,u[MAXN],v[MAXN],l[MAXN],r[MAXN],c[MAXN],fc[MAXN],inv[MAXN],sum[41][MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int C(int a,int b){return 1ll*fc[a]*inv[b]%P*inv[a-b]%P;}
int main()
{
	N=get(),M=get();For(i,1,N)l[i]=get(),r[i]=get(),c[l[i]]++,c[r[i]+1]--;For(i,1,N)c[i]+=c[i-1];For(i,0,M-1)u[i]=get(),v[i]=get();
	fc[0]=1;For(i,1,N)fc[i]=1ll*fc[i-1]*i%P;inv[N]=pow(fc[N],P-2);FOR(i,N-1,0)inv[i]=1ll*inv[i+1]*(i+1)%P;
	For(i,0,M*2)For(j,i,N)sum[i][j]=(sum[i][j-1]+(c[j]>=j?C(c[j]-i,j-i):0))%P;int ans=0;
	For(i,0,(1<<M)-1)
	{
		int l=1,r=N;set<int>s;For(j,0,M-1)if(i>>j&1)l=max(l,max(::l[u[j]],::l[v[j]])),r=min(r,min(::r[u[j]],::r[v[j]])),s.insert(u[j]),s.insert(v[j]);
		if(l<=r)ans=(ans+1ll*(__builtin_popcount(i)&1?P-1:1)*(sum[s.size()][r]-sum[s.size()][l-1]+P))%P;
	}
	cout<<ans<<'\n';
}