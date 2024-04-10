#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
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
ll a,b;
ll check(ll x){
	int A=0,B=0;
	ll p=b;
	while(p%x==0)p/=x,++A;
	p=a;
	while(p%x==0)p/=x,++B;
	ll o=a;
	for(int i=1;i<=B-A+1;++i){
		o/=x;
	}
	return o;
}
ll Solve(){
	if(a%b)return a;
	ll ans=0;
	ll tmp=b;
	for(ll i=2;i*i<=tmp;++i){
		if(tmp%i==0){
			ans=max(ans,check(i));
			while(tmp%i==0)tmp/=i;
		}
	}
	if(tmp>1)ans=max(ans,check(tmp));
	return ans;
}
int main(){
	T=read();
	while(T--){
		a=read(),b=read();
		printf("%lld\n",Solve());
	}
	return 0;
}