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
int n,k;
int main(){
	n=read(),k=read();
	for(int i=1;;++i){
		if(1LL*i*(i+1)/2-k+i==n){
			printf("%lld\n",1LL*i*(i+1)/2-k);
			return 0;
		}
	}
	return 0;
}