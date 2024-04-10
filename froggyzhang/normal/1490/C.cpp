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
ll x;
void Solve(){
	x=read();
	for(ll i=1;i*i*i<=x;++i){
		ll j=pow(x-i*i*i,0.33);
		while(i*i*i+j*j*j<x)++j;
		if(j&&i*i*i+j*j*j==x){
			puts("Yes");return;
		}	
	}
	puts("No");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;	
}