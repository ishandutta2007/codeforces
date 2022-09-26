#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 1010
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
int T,a[N],b[N],n,m;
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		for(int i=1;i<=m;++i){
			b[i]=read();
		}
		bool ok=false;
		for(int i=1;i<=n;++i){
			if(ok)break;
			for(int j=1;j<=m;++j){
				if(a[i]==b[j]){
					printf("YES\n1 %d\n",a[i]);
					ok=true;break;
				}
			}
		}
		if(!ok){
			printf("NO\n");
		}
	}
	return 0;
}