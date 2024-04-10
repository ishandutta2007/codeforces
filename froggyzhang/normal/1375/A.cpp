#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
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
int T,n;
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			int x=read();
			printf("%d ",i&1?abs(x):-abs(x));
		}
		printf("\n");
	}
	return 0;
}