#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=1e9+7;
inline int read(){
	int x=0,f=1;
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
int n;
int main(){
	n=read();
	int fac=1,pw=1;
	for(int i=1;i<=n;++i){
		fac=1LL*fac*i%mod;
	}
	for(int i=1;i<n;++i){
		(pw<<=1)%=mod;
	} 
	printf("%d\n",(fac-pw+mod)%mod);
	return 0;
}