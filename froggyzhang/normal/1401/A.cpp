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
int T;
int main(){
	T=read();
	while(T--){
		int n=read(),k=read();
		if(k>n){
			printf("%d\n",k-n);
		}
		else{
			printf("%d\n",(n+k)&1);
		}
	}
	return 0;
}