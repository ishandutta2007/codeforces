#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 233
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
int n,m,a[N],b[N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=m;++i){
		b[i]=read();
	}
	for(int i=0;i<(1<<9);++i){
		bool ok=true;
		for(int j=1;j<=n;++j){
			bool emm=false;
			for(int k=1;k<=m;++k){
				if((i&(a[j]&b[k]))==(a[j]&b[k])){
					emm=true;
					break;
				} 
			}
			if(!emm){
				ok=false;
				break;
			}
		}
		if(ok){
			return !printf("%d\n",i);
		}
	}
	return 0;
}