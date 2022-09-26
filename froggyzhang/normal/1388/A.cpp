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
		if(n<31){
			printf("NO\n");
		}
		else{
			printf("YES\n");
			if(n==36){
				puts("5 6 10 15");
			}
			else if(n==44){
				puts("6 7 10 21\n");
			}
			else if(n==40){
				puts("10 21 6 3");
			}
			else{
				printf("%d %d %d %d\n",10,6,14,n-30);
			}
		}
	}
	return 0;
}