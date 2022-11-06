#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6,mod=1e9+7;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,f[1000005],ans,Size[1000005];
void FMT(){
	for(int j=1;j<=N;j<<=1){
		for(int i=0;i<=N;++i){
			if(i&j)f[i^j]+=f[i];
		}
	}
}
int ksm(int a,int n){
	int ans=1;
	while(n){
		if(n&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;n>>=1;
	}
	return ans;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i)++f[read()];
	FMT();
	for(int i=0;i<=N;++i){
		if(i)Size[i]=Size[i>>1]+(i&1);
		ans=(ans+(Size[i]&1?mod-ksm(2,f[i])+1:ksm(2,f[i])-1))%mod;
	}
	cout<<ans<<"\n";
	return 0;
}