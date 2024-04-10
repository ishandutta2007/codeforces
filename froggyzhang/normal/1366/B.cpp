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
int T,n,m,x;
int main(){
	T=read();
	while(T--){
		n=read(),x=read(),m=read();
		int l=x,r=x;
		while(m--){
			int p=read(),q=read();
			if(!(q<l||p>r)){
				l=min(p,l),r=max(r,q);
			}
		}
		printf("%d\n",r-l+1);
	}
	return 0;
}