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
int T,n,a,b;
int main(){
	T=read();
	while(T--){
		n=read(),a=read(),b=read();
		for(int i=0;i<n;++i){
			putchar(i%b+'a');
		}
		putchar('\n');
	}
	return 0;
}