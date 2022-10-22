#include<iostream>
#include<map>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define S second
#define P 1000000007
#define MAXN 100001
int N,a[MAXN],fc[MAXN],inv[MAXN];int pow(int a,int b){int ans=1;while(b)b&1?ans=1ll*ans*a%P:0,a=1ll*a*a%P,b>>=1;return ans;}
int main()
{
	cin>>N;For(i,1,N)cin>>a[i];fc[0]=1;For(i,1,N)fc[i]=1ll*fc[i-1]*i%P;inv[N]=pow(fc[N],P-2);FOR(i,N-1,0)inv[i]=1ll*inv[i+1]*(i+1)%P;
	ll x=0;For(i,1,N)x+=a[i];if(x%N){cout<<0<<endl;return 0;}x/=N;int cnt1=0,cnt2=0;For(i,1,N)cnt1+=a[i]<x,cnt2+=a[i]>x;if(!cnt1&&!cnt2){cout<<1<<endl;return 0;}
	map<int,int>tot;For(i,1,N)x!=a[i]?tot[a[i]]++:0;if(cnt1==1||cnt2==1){int ans=1ll*fc[N]*inv[N-cnt1-cnt2]%P;for(auto i:tot)ans=1ll*ans*inv[i.S]%P;cout<<ans<<endl;return 0;}
	int ans=2ll*fc[cnt1]*fc[cnt2]%P;for(auto i:tot)ans=1ll*ans*inv[i.S]%P;ans=1ll*ans*fc[N]%P*inv[cnt1+cnt2]%P*inv[N-cnt1-cnt2]%P;cout<<ans<<endl;return 0;
}