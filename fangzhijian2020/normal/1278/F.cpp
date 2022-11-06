#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int ksm(int a,int n){
	int ans=1;
	while(n){
		if(n&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;n>>=1;
	}
	return ans;
}
int n,m,k,s2[5005][5005],ans; 
int main(){
	n=read();m=read();k=read();
	s2[0][0]=1;
	for(int i=1;i<=k;++i){
		for(int j=1;j<=k;++j){
			s2[i][j]=(1ll*s2[i-1][j]*j%mod+s2[i-1][j-1])%mod;
		}
	}
	int tmp=1;
	for(int i=0;i<=min(n,k);++i){
		ans=(ans+1ll*s2[k][i]*tmp%mod*ksm(m,n-i)%mod)%mod;
		tmp=1ll*tmp*(n-i)%mod;
	}
	cout<<1ll*ans*ksm(ksm(m,n),mod-2)%mod;
	return 0;
}