#include<stdio.h>
#include<cstring>
#include<algorithm>
#define MP(x,y) make_pair(x,y)
using namespace std;
#define N 100010
long long n,k;
long long niyu[N],iniyu[N];
#define mo 1000000007
char s[N];
inline long long Power(long long a,long long b){
	long long ans=1;for(;b;b>>=1,a=1ll*a*a%mo)if(b&1)ans=1ll*ans*a%mo;
	return ans;
}
long long a[N],f[N];
inline long long c(long long n,long long m){
	return 1ll*niyu[n]*iniyu[m]%mo*iniyu[n-m]%mo;
}
long long sum[N],power[N];
long long Change(long long S,long long t){return (sum[t]-sum[S-1]*power[t-S+1]%mo+mo)%mo;}
int main(){
	scanf("%I64d%I64d",&n,&k);scanf("%s",s+1);niyu[0]=1;for(long long i=1;i<=n;i++)niyu[i]=1ll*niyu[i-1]*i%mo;
	iniyu[0]=1;iniyu[n]=Power(niyu[n],mo-2);for(long long i=n-1;i;i--)iniyu[i]=1ll*iniyu[i+1]*(i+1)%mo;
	for(long long i=1;i<=n;i++)a[i]=s[i]-'0';
	for(long long i=1;i<=n;i++)sum[i]=a[i];
	power[0]=1;for(int i=1;i<=n;i++)power[i]=(power[i-1]*10ll)%mo;
	for(long long i=2;i<=n;i++)sum[i]=(sum[i]+sum[i-1]*10ll%mo)%mo;
	for(long long i=2;i<=n;i++)(a[i]+=a[i-1])%=mo;
	f[1]=a[n]%mo;for(long long i=2;i<=n;i++)f[i]=((1ll*f[i-1]*10ll%mo+(a[n]-a[i-1])%mo)%mo-1ll*Change(n-i+2,n)*10%mo+mo)%mo;
	if(k==0)printf("%I64d\n",f[n]);
	else if(k==1){
		long long ans=0;for(long long i=1;i<=n-1;i++)(ans+=Change(1,i)+Change(n-i+1,n))%=mo;
		printf("%I64d\n",ans);
	}else{
		long long ans=0;for(long long i=1;i<=n-2-(k-2);i++){
			ans=(1ll*ans+1ll*f[i]*c(n-i-2,k-2)%mo)%mo;
		}for(long long i=1;i<=n-2-(k-2);i++){
			ans=((1ll*ans-1ll*Change(1,i)*c(n-i-2,k-2)%mo+mo)%mo-1ll*Change(n-i+1,n)*c(n-i-2,k-2)%mo+mo)%mo;
		}for(long long i=1;i<=n-k;i++){
			ans=(1ll*ans+1ll*(Change(1,i)+Change(n-i+1,n))*c(n-i-1,k-1)%mo)%mo;
		}printf("%I64d\n",ans);
	}
}