#include<iostream>
#include<cstring>
#include<cstdio>
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
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n,m,p[N],a[N];
int main(){
	T=read();
	while(T--){
		n=read();
		int an=0;
		for(int i=1;i<=n;++i){
			p[i]=read();
		}
		a[++an]=p[1];
		for(int i=2;i<n;++i){
			if(p[i]>p[i-1]&&p[i]>p[i+1]||p[i]<p[i-1]&&p[i]<p[i+1])a[++an]=p[i];
		}
		a[++an]=p[n];
		printf("%d\n",an);
		for(int i=1;i<=an;++i){
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	return 0;
}