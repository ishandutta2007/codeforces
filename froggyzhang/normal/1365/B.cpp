#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 505
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
int T,n,a[N],b[N];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		for(int i=1;i<=n;++i){
			b[i]=read();
		}
		bool ok=false;
		for(int i=2;i<=n;++i){
			if(b[i]^b[1]){
				ok=true;break;
			}
		}
		if(ok||n==1){
			printf("Yes\n");
			continue;
		}
		ok=true;
		for(int i=2;i<=n;++i){
			if(a[i]<a[i-1]){
				ok=false;break;
			}
		}
		printf(ok?"Yes\n":"No\n");
	}
	return 0;
}