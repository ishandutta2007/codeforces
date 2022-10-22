#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 1000000007
#define MAXN 500001
int T,N,cnt[61];ll a[MAXN];
ll get(){ll x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,0,60)cnt[i]=0;For(i,1,N){a[i]=get();For(j,0,60)cnt[j]+=(a[i]>>j)&1;}int ans=0;
		For(i,1,N){int res1=0,res2=0;For(j,0,60){int s=(a[i]>>j)&1;if(s)res1=(res1+(1ll<<j)%P*cnt[j])%P;if(s)res2=(res2+(1ll<<j)%P*N)%P;else res2=(res2+(1ll<<j)%P*cnt[j])%P;}ans=(ans+1ll*res1*res2)%P;}
		cout<<ans<<endl;
	}
	return 0;
}