#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 300030 
const int mod=998244353;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,a[N],s[N]; 
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	} 
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;++i){
		s[i]=(s[i-1]+a[i])%mod;
	}
	for(int k=1;k<=n;++k){
		int ans=0;
		for(int i=0,j=0;i<n;i+=k,++j){
			ans=(ans+1LL*j*(s[min(i+k,n)]-s[i]+mod)%mod)%mod;
		}
		ans=1LL*qpow(n,mod-2)*ans%mod;
		printf("%d ",ans);
	}
	return 0;
}