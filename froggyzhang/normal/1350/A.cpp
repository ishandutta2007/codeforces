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
int T,k,n;
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		int num=n;
		for(int i=2;i*i<=n;++i){
			if(n%i==0){
				num=i;break;
			}
		}
		printf("%I64d\n",2LL*(k-1)+num+n);
	}
	return 0;
}