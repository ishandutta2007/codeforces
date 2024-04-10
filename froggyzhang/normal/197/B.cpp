#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 10010
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
int n,m,a[N],b[N];
int _gcd(int a,int b){
	if(b==0)return a;
	return _gcd(b,a%b);
}
int main(){
	n=read(),m=read();
	for(int i=0;i<=n;++i){
		a[i]=read();
	}
	for(int i=0;i<=m;++i){
		b[i]=read();
	}
	if(n>m){
		if((a[0]<0)^(b[0]<0))printf("-");
		printf("Infinity\n");
	}
	else if(n<m){
		printf("0/1\n");
	}
	else{
		int type=0;
		if(a[0]<0)type^=1,a[0]=-a[0];
		if(b[0]<0)type^=1,b[0]=-b[0];
		int g=_gcd(a[0],b[0]);
		if(type)printf("-");
		printf("%d/%d\n",a[0]/g,b[0]/g);
	}
	return 0;
}