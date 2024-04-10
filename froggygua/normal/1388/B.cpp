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
int T,n;
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			putchar((n-i)*4<n?'8':'9');
		}
		putchar('\n');
	}
	return 0;
}