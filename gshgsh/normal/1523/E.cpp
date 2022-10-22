#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 200001
int T,N,K,fc[MAXN],inv[MAXN];
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int C(int a,int b){return 1ll*fc[a]*inv[b]%P*inv[a-b]%P;}
int main()
{
	cin>>T;N=MAXN-1;fc[0]=1;For(i,1,N)fc[i]=1ll*fc[i-1]*i%P;inv[N]=pow(fc[N],P-2);FOR(i,N-1,0)inv[i]=1ll*inv[i+1]*(i+1)%P;
	while(T--){cin>>N>>K;int x=1,ans=0;while(N-(x-2)*(K-1)>=x-1)ans=(ans+1ll*C(N-(x-2)*(K-1),x-1)*pow(C(N,x-1),P-2))%P,x++;cout<<ans<<'\n';}return 0;
}