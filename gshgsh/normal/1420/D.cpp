#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define lowbit(x) x&-x
#define Pair pair<int,int>
#define F first
#define S second
#define P 998244353
#define MAXN 300001
int N,K,l[MAXN],r[MAXN],fc[MAXN],inv[MAXN],M,b[MAXN*2],c[MAXN*2],ans;Pair a[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int pow(int a,int b){int ans=1;while(b)b&1?ans=1ll*ans*a%P:0,a=1ll*a*a%P,b>>=1;return ans;}int C(int a,int b){if(a<b)return 0;return 1ll*fc[a]*inv[b]%P*inv[a-b]%P;}
void upd(int x){for(int i=x;i;i-=lowbit(i))c[i]++;}int ask(int x){int ans=0;for(int i=x;i<=M;i+=lowbit(i))ans+=c[i];return ans;}
int main()
{
	N=get(),K=get();For(i,1,N)b[++M]=l[i]=get(),b[++M]=r[i]=get();sort(b+1,b+M+1);M=unique(b+1,b+M+1)-b-1;For(i,1,N)a[i]={lower_bound(b+1,b+M+1,l[i])-b,lower_bound(b+1,b+M+1,r[i])-b};sort(a+1,a+N+1);
	fc[0]=1;For(i,1,N)fc[i]=1ll*fc[i-1]*i%P;inv[N]=pow(fc[N],P-2);FOR(i,N-1,0)inv[i]=1ll*inv[i+1]*(i+1)%P;
	For(i,1,N)ans=(ans+C(ask(a[i].F),K-1))%P,upd(a[i].S);cout<<ans<<endl;return 0;
}