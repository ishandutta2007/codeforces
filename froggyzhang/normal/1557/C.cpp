#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int mod=1e9+7;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m;
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
	int T=read();
	while(T--){
		n=read(),m=read();
		if(!(n&1)){
			int A=qpow(2,n-1),B=(A<<1)%mod;
			int ans=qpow(A-1,m);
			for(int i=m;i>=1;--i){
				ans=(ans+1LL*qpow(A-1,m-i)*qpow(B,i-1))%mod;
			}
			printf("%d\n",ans);
		}
		else{
			printf("%d\n",qpow(qpow(2,n-1)+1,m));	
		}
	}
	return 0;
}