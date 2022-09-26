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
int T,x1,y1,x2,y2;
inline int Abs(int x){
	return x>=0?x:-x;
}
int main(){
	T=read();
	while(T--){
		x1=read(),y1=read();
		x2=read(),y2=read();
		int d=Abs(x1-x2)+Abs(y1-y2);
		printf("%d\n",d+(x1!=x2&&y1!=y2)*2);
	}
	return 0;
}