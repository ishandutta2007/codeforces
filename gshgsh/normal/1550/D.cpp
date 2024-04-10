#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 200001
int T,N,l,r,fc[MAXN],inv[MAXN];
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int C(int a,int b){if(a<0||b<0||b>a)return 0;return 1ll*fc[a]*inv[b]%P*inv[a-b]%P;}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>l>>r;fc[0]=1;For(i,1,N)fc[i]=1ll*fc[i-1]*i%P;inv[N]=pow(fc[N],P-2);FOR(i,N-1,0)inv[i]=1ll*inv[i+1]*(i+1)%P;int ans=0;
		if(N&1){ans=2ll*min(1-l,r-N)*C(N,N/2)%P;for(int k=min(1-l,r-N)+1,x=max(l+k,1),y=min(r-k,N);x-1<y+1;k++,x=max(l+k,1),y=min(r-k,N))ans=(1ll*ans+C(y-x+1,N/2-x+1)+C(y-x+1,N/2-x+2))%P;}
		else{ans=1ll*min(1-l,r-N)*C(N,N/2)%P;for(int k=min(1-l,r-N)+1,x=max(l+k,1),y=min(r-k,N);x-1<y+1;k++,x=max(l+k,1),y=min(r-k,N))ans=(ans+C(y-x+1,N/2-x+1))%P;}
		cout<<ans<<endl;
	}
	return 0;
}