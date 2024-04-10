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
		int l=read(),r=read();
		if(r<(l<<1)){
			printf("-1 -1\n");
		}
		else{
			printf("%d %d\n",l,l<<1);
		}
	}
	return 0;
}