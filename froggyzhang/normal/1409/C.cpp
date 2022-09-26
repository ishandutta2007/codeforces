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
int T,n,x,y;
int main(){
	T=read();
	while(T--){
		n=read(),x=read(),y=read();
		int p=0;
		for(p=x+1;;++p){
			if((y-x)%(p-x)==0&&(y-x)/(p-x)<n)break;
		}
		p-=x;
		for(int i=x;i<=y;i+=p,--n){
			printf("%d ",i);
		}
		for(int i=x-p;i>=1&&n;i-=p,--n){
			printf("%d ",i);
		}
		for(int i=y+p;n;i+=p,--n){
			printf("%d ",i);
		}
		printf("\n");
	}
	return 0;
}