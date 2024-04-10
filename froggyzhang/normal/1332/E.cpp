#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
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
ll n,m,L,R,len;
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
	n=read(),m=read(),L=read(),R=read();
	len=R-L+1;
	if((n*m)&1){
		cout<<qpow(R-L+1,n*m)<<endl;
		return 0;
	}
	else{
		if(len&1){
			cout<<(qpow(len,n*m)+1)*qpow(2LL,mod-2)%mod<<endl;
		}
		else{
			cout<<qpow(len,n*m)*qpow(2LL,mod-2)%mod<<endl;
		}
	}
	return 0;
}