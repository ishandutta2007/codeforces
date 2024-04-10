#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,k;
int main(){
	n=read(),k=read();
	int g=k;
	for(int i=1;i<=n;++i){
		g=__gcd(g,read());
	}
	printf("%d\n",k/g);
	for(int i=0;i<k;i+=g){
		printf("%d ",i);
	}
	return 0;
}