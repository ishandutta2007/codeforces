#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define lowbit(x) x&-x
#define P 998244353
#define MAXN 500001
int N,a[MAXN],l[MAXN],r[MAXN],cnt[MAXN],s[MAXN],ans,vis[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
void upd(int x,int v){for(int i=x;i<=N;i+=lowbit(i))s[i]=(s[i]+v)%P;}
int ask(int x){int ans=0;for(int i=x;i;i-=lowbit(i))ans=(ans+s[i])%P;return ans;}
int main()
{
	N=get();For(i,1,N)a[i]=get();FOR(i,N,1)if(a[i]!=-1)ans=(ans+ask(a[i]-1))%P,upd(a[i],1);For(i,1,N)s[i]=0;
	int c=0;For(i,1,N)if(a[i]==-1)c++;ans=(ans+1ll*c*(c-1)%P*pow(4,P-2))%P;
	For(i,1,N)l[i]=l[i-1]+(a[i]==-1);FOR(i,N,1)r[i]=r[i+1]+(a[i]==-1);For(i,1,N)if(a[i]!=-1)vis[a[i]]=i;
	c=0;For(i,1,N)if(!vis[i])c++;else cnt[vis[i]]=c;
	For(i,1,N)if(a[i]!=-1)ans=(ans+1ll*l[i]*(c-cnt[i])%P*pow(c,P-2)+1ll*r[i]*cnt[i]%P*pow(c,P-2))%P;cout<<ans<<'\n';return 0;
}