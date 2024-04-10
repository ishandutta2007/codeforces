#include<bits/stdc++.h>
using namespace std;
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
int T;
ll n;
ll Solve(){
	n=read();
	if(n%2050)return -1;
	n/=2050;
	ll ans=0;
	while(n)ans+=n%10,n/=10;
	return ans;
}
int main(){
	
	T=read();
	while(T--){
		printf("%lld\n",Solve());
	}
	return 0;
}