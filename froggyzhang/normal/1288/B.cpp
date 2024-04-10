#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
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
int T;
int main(){
	T=read();
	while(T--){
		int a=read(),b=read();
		int u=1,p=0;
		while(10LL*u-1<=b)u*=10,++p;
		printf("%I64d\n",1LL*p*a);
	}
	return 0;
}