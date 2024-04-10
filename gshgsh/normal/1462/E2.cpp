#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 1000000007
#define MAXN 200001
int T,N,M,K,a[MAXN],fc[MAXN];
int pow(int a,int b){int ans=1;while(b)b&1?ans=1ll*ans*a%P:0,a=1ll*a*a%P,b>>=1;return ans;}
int C(int a,int b){return 1ll*fc[a]*pow(fc[b],P-2)%P*pow(fc[a-b],P-2)%P;}
int main()
{
	cin>>T;N=MAXN-1;fc[0]=1;For(i,1,N)fc[i]=1ll*fc[i-1]*i%P;
	while(T--)
	{
		cin>>N>>M>>K;For(i,1,N)cin>>a[i];sort(a+1,a+N+1);int ans=0;
		int l=1;For(r,M,N){while(a[r]-a[l]>K)l++;if(r-l+1<M)continue;ans=(ans+C(r-l,M-1))%P;}cout<<ans<<endl;
	}
	return 0;
}