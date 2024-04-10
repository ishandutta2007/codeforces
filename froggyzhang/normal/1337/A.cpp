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
int T,a,b,c,d;
int main(){
	T=read();
	while(T--){
		a=read(),b=read(),c=read(),d=read();
		printf("%d %d %d\n",b,c,c);
	}
	return 0;
}