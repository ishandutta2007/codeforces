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
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,a1,a2,a3,b1,b2,b3;
int main(){
	n=read();
	a1=read(),a2=read(),a3=read();
	b1=read(),b2=read(),b3=read();
	printf("%d %d\n",max(0,max(b2-(n-a1),max(b3-(n-a2),b1-(n-a3)))),min(a1,b2)+min(a2,b3)+min(a3,b1));
	return 0;
}