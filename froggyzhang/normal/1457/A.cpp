#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define y1 ysgh
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
int n,m,x,y,T;
inline int calc(int x1,int y1,int x2,int y2){
	return abs(x1-x2)+abs(y1-y2);
}
int main(){
	T=read();
	while(T--){
		n=read(),m=read(),x=read(),y=read();
		printf("%d\n",max(max(calc(1,1,x,y),calc(1,m,x,y)),max(calc(n,1,x,y),calc(n,m,x,y))));
	}
	return 0;
}