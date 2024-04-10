#include<iostream>
#include<cstdio>
#include<cstring>
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
int n,a[N],ans;
int main(){
	n=read();
	a[0]=0x3f3f3f3f;
	for(int i=1;i<=n;++i){
		int x=read();
		a[i]=(x-i+n)/n;
		if(a[i]<a[ans]){
			ans=i;
		}
	}
	printf("%d\n",ans);
	return 0;
}