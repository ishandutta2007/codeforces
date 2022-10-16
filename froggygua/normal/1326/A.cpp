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
int T,n;
int main(){
	T=read();
	while(T--){
		n=read();
		if(n==1){
			printf("-1\n");
		}
		else{
			printf("2");
			for(int i=2;i<=n;++i){
				printf("3");
			}
			printf("\n");
		}
	}
	return 0;
}