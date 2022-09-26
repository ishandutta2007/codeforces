#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 300030
inline ll read(){
    ll x=0,f=1;
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
ll n,mod,fac[N],ans;
int main(){
	n=read(),mod=read();
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	for(int i=1;i<=n;i++){
		ans=(ans+fac[i]*fac[n-i]%mod*(n-i+1)%mod*(n-i+1)%mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
}