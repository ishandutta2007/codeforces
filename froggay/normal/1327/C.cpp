#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 222
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
int n,m,k,a[N][N];
int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=k;++i){
		read(),read();
	}
	for(int i=1;i<=k;++i){
		int x=read(),y=read();
		a[x][y]=1;
	}
	printf("%d\n",n+m+n*m-1);
	for(int i=1;i<=n;++i){
		putchar('U');
	}
	for(int i=1;i<=m;++i){
		putchar('L');
	}
	for(int i=1;i<=n;++i){
		if(i&1){
			for(int j=1;j<m;++j){
				putchar('R');
			}
		}
		else{
			for(int j=1;j<m;++j){
				putchar('L');
			}
		}
		if(i<n)putchar('D');
	}
	return 0;
}