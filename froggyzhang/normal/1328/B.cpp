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
int T,n,k;
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		int pos=n-1;
		while(k>n-pos){
			k-=n-pos;
			--pos;
		}
		for(int i=1;i<=n;++i){
			putchar((i==pos||i==n-k+1)?'b':'a');
		}
		putchar('\n');
	}
	return 0;
}