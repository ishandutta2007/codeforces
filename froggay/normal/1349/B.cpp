#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100010
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
int n,k,T,a[N];
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		bool ok=true;
		int gg=0;
		for(int i=1;i<=n;++i){
			a[i]=read();
			if(a[i]^k)ok=false;
			else ++gg;
		}
		if(!gg){
			printf("no\n");
			continue;
		}
		for(int i=1;i<n;++i){
			if(a[i]>=k){
				if(a[i+1]>=k||(i<n-1&&a[i+2]>=k)){
					ok=true;
					break;
				}
			}
		}
		printf(ok?"yes\n":"no\n");
	}
	return 0;
}