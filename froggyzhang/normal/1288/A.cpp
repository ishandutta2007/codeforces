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
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n,d;
int main(){
	T=read();
	while(T--){
		n=read(),d=read();
		bool ok=false;
		for(int i=0;i<=min(500000,d-1);++i){
			if(i+(d-1)/(i+1)+1<=n){
				ok=true;
				break;
			}
		}
		printf(ok?"YES\n":"NO\n");
	}
	return 0;
}