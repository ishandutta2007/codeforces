#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 55
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n,m,a[N][N];
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				a[i][j]=read();
			}
		}
		int c1=0,c2=0;
		for(int i=1;i<=n;++i){
			int qwq=1;
			for(int j=1;j<=m;++j){
				if(a[i][j]){
					qwq=0;break;
				}
			}
			c1+=qwq;
		}
		for(int j=1;j<=m;++j){
			int qwq=1;
			for(int i=1;i<=n;++i){
				if(a[i][j]){
					qwq=0;break;
				}
			}
			c2+=qwq;
		}
		printf(min(c1,c2)&1?"Ashish\n":"Vivek\n");
	}
	return 0;
}