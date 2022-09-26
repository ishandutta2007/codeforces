#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 105
const int mx=100;
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
int n,a[N],T;
int main(){
	T=read();
	while(T--){
		n=read();
		int mx=0,sum=0;
		for(int i=1;i<=n;++i){
			a[i]=read();
			mx=max(mx,a[i]);
			sum+=a[i];
		}
		if(mx>sum/2){
			puts("T");
		}
		else{
			printf(sum&1?"T\n":"HL\n");
		}
	}
	return 0;
}