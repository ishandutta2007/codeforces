#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[24],k,b[2],f[30],t[1<<24];
const int MOD=1000000000+7;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	scanf("%d",&k);
	for(int i=0;i<k;i++)scanf("%d",&b[i]);
	f[0]=1;
	for(int i=1;i<30;i++)f[i]=(long long)f[i-1]*i%MOD;
	if(!k){
		printf("%d\n",f[n]);
		return 0;
	}
	if(k==1)b[1]=b[0],++k;
	if(b[0]>b[1])swap(b[0],b[1]);
	long long r=0,r_mod=(long long)MOD*MOD;
	for(int i=1;i<(1<<n);i++){
		int sum=0;
		int tmp=__builtin_popcount(i);
		for(int j=0;j<n;j++)if(i&1<<j){
			sum+=a[j];
			if(sum>b[1])goto fail;
		}
		if(sum==b[0]){
			t[i]=f[tmp];
			r+=(long long)f[tmp]*f[n-tmp];
			if(r>=r_mod)r-=r_mod;
		}else if(sum>b[0]){
			int ii=i;
			while(ii){
				int pos=__builtin_ctz(ii);
				t[i]+=t[i-(1<<pos)];
				ii-=1<<pos;
				if(t[i]>=MOD)t[i]-=MOD;
			}
			if(sum==b[1]){
			  r+=(long long)(f[tmp]+MOD-t[i])*f[n-tmp];
				if(r>=r_mod)r-=r_mod;
			}
		}
fail:;		
	}
	printf("%d\n",(f[n]+MOD-r%MOD)%MOD);
	return 0;
}