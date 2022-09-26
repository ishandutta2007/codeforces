#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
#define N 1000100
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
int n,p[N],bit[N];
ll fac[N],ans,sum;
inline ll Get(int n){
	ll tmp=1LL*n*(n-1)/2%mod;
	return tmp*tmp%mod*fac[n-2]%mod;
}
inline int lowbit(int x){
	return x&(-x);
}
inline void Add(int x,int d){
	while(x<=n){
		bit[x]+=d;
		x+=lowbit(x);
	}
}
inline int Ask(int x){
	int ans=0;
	while(x){
		ans+=bit[x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	n=read();
	fac[0]=1;
	for(int i=1;i<=n;i++){
		p[i]=read();
		fac[i]=fac[i-1]*i%mod;
	}
	for(int i=1;i<=n;i++){
		Add(p[i],1);
		int tot=Ask(p[i]-1);
		ll t=p[i]-tot-1;
		ans=(ans+sum*t%mod*fac[n-i])%mod;
		ans=(ans+t*(t-1)/2%mod*fac[n-i]%mod)%mod;
		ans=(ans+t*Get(n-i)%mod)%mod;
		ans=(ans+t)%mod;
		sum=(sum+t)%mod;
	}
	cout<<ans<<endl;
	return 0;
}