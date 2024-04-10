#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
using namespace std;

int n;long long m;long long num[21];
int inv[21];
int ans=0;
const int mod=1e9+7;

inline int por(int x,int y){
	long long res=1;
	while(y){
		if(y&1) (res*=x)%=mod;
		y>>=1;
		x=(long long)x*x%mod;
	}
	return res;
}
inline int C(long long x,int y){
	if(x<y)return 0;
	x%=mod;
	if(x<y)return 0;
	long long res=1;
	for(int i=x-y+1;i<=x;++i) (res*=i)%=mod;
	(res*=inv[y])%=mod;
	return res;
}
int main(void){
	scanf("%d%lld",&n,&m);
	inv[0]=inv[1]=1;
	for(int i=2;i<=20;++i)inv[i]=por(i,mod-2);
	for(int i=2;i<=20;++i)inv[i]=(long long)inv[i]*inv[i-1]%mod;
	for(int i=1;i<=n;++i)scanf("%lld",num+i);
	for(int i=0;i<(1<<n);++i){
		long long k=n+m-1,cnt=0;
		for(int j=0;j<n;++j)if(i>>j&1)k-=num[j+1]+1,++cnt;
		if(cnt&1) (ans-=C(k,n-1))%=mod;
		else      (ans+=C(k,n-1))%=mod;
	}
	ans=(ans+mod)%mod;
	printf("%d\n",ans);
	return 0;
}