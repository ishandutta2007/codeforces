#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 200020
const ll mod=998244353;
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
int n;
ll ans[N];
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		printf("%I64d ",((n-i-1)*qpow(10,n-2-i+1)%mod*9%mod*9%mod+2*qpow(10,n-1-i+1)*9%mod)%mod);
	}
	printf("%d",10);
	return 0;
}