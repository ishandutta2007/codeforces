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
int a1,a2,k1,k2,n;
int p;
int main(){
	a1=read(),a2=read(),k1=read(),k2=read();
	n=read();
	p=(k1-1)*a1+(k2-1)*a2;
	if(p>=n){
		printf("%d ",0);
	}
	else{
		printf("%d ",n-p);
	}
	if(k1>k2){
		swap(k1,k2),swap(a1,a2);
	}
	if(a1*k1>n){
		printf("%d\n",n/k1);
	}
	else{
		printf("%d\n",a1+(n-a1*k1)/k2);
	}
	return 0;
}