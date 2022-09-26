#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200020
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
int n,b[N];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		b[i]=read();
	}
	int p=0;
	for(int i=1;i<=n;++i){
		if(b[i]>=0){
			p+=b[i];
			printf("%d ",p);
		}
		else{
			printf("%d ",p+b[i]);
		}
	}
	return 0;
}