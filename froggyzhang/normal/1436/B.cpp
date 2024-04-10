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
int T,n;
inline bool Isprime(int x){
	if(x==1)return false;
	for(int i=2;i*i<=x;++i){
		if(x%i==0)return false;
	}
	return true;
}
int Get(int n){
	for(int i=1;;++i){
		if(!Isprime(i)&&Isprime(n+i-1))return i;
	}
}
int main(){
	T=read();
	while(T--){
		n=read();
		int x=Get(n);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				printf("%d ",i==j?x:1);
			}
			printf("\n");
		}
	}
	return 0;
}