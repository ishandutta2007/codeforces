#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define lowbit(x) x&-x
#define P 998244353
#define MAXN 200001
int N,M,K,a[MAXN],b[MAXN],cnt[MAXN],now,c[MAXN],fc[MAXN],ans;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
void upd(int x,int v){for(int i=x;i<=K;i+=lowbit(i))c[i]+=v;}
int ask(int x){int ans=0;for(int i=x;i;i-=lowbit(i))ans=(ans+c[i])%P;return ans;}
int main()
{
	N=get(),M=get();For(i,1,N)K=max(K,a[i]=get());For(i,1,M)K=max(K,b[i]=get());For(i,1,N)upd(a[i],1);fc[0]=1;For(i,1,max(N,M))fc[i]=1ll*fc[i-1]*i%P;
	For(i,1,N)cnt[a[i]]++;now=fc[N];For(i,1,K)now=1ll*now*pow(fc[cnt[i]],P-2)%P;
	For(i,1,min(N,M))
	{
		ans=(ans+1ll*now*pow(N-i+1,P-2)%P*ask(b[i]-1))%P;
		if(!cnt[b[i]]){now=0;break;}upd(b[i],-1);now=1ll*now*pow(N-i+1,P-2)%P;now=1ll*now*cnt[b[i]]%P;cnt[b[i]]--;
	}
	if(N<M)ans=(ans+now)%P;cout<<ans<<'\n';return 0;
}