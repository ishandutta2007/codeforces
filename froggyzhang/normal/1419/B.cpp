#include<iostream>
#include<cstdio>
#include<cstring>
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
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;;++i){
			ll x=(1LL<<i)*((1LL<<i)-1)>>1;
			if(n<x){
				printf("%d\n",i-1);break;
			}
			n-=x;
		}
	}
	return 0;
}