#include<iostream>
#include<cstdio>
#include<cstring>
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
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int T;
int main(){
	T=read();
	while(T--){
		int x1=read(),y1=read(),z1=read();
		int x2=read(),y2=read(),z2=read();
		int k=min(z1,y2);
		int n=x1+y1+z1-k;
		printf("%d\n",(k<<1)-(max(0,n-(n-y1)-(n-z2))<<1));
	}
	return 0;
}