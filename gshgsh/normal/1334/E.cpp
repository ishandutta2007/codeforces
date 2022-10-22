#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 998244353
#define MAXN 101
ll D,p[MAXN];int Q,tot,fc[MAXN],inv[MAXN];
ll get(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int calc(ll x){int cnt=0,ans=1;For(i,1,tot)if(x%p[i]==0){int c=0;while(x%p[i]==0)x/=p[i],c++;cnt+=c;ans=1ll*ans*inv[c]%P;}return 1ll*ans*fc[cnt]%P;}
int main()
{
	D=get();for(int i=2;1ll*i*i<=D;i++)if(D%i==0){p[++tot]=i;while(D%i==0)D/=i;}if(D>1)p[++tot]=D;
	fc[0]=1;For(i,1,MAXN-1)fc[i]=1ll*fc[i-1]*i%P;inv[MAXN-1]=pow(fc[MAXN-1],P-2);FOR(i,MAXN-2,0)inv[i]=1ll*inv[i+1]*(i+1)%P;
	Q=get();while(Q--){ll x=get(),y=get(),d=__gcd(x,y);cout<<1ll*calc(x/d)*calc(y/d)%P<<'\n';}return 0;
}