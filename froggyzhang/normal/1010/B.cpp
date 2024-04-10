#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
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
int m,n,a[33];
inline int Ask(int x){
	printf("%d\n",x);
	fflush(stdout);
	int d=read();
	if(!d)exit(0);
	return d;
}
int main(){
	m=read(),n=read();
	for(int i=1;i<=n;++i){
		a[i]=Ask(1);
	}
	int l=1,r=m+1,o=1;
	while(l<r){
		int mid=(l+r)>>1;
		int t=Ask(mid)*a[(o-1)%n+1];
		++o;
		if(t==1){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	return 0;
}