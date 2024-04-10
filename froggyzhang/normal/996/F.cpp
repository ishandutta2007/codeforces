#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
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
int n,Q,a[1<<18];
ll tot;
int main(){
	n=read(),Q=read();
	for(int i=0;i<(1<<n);++i){
		a[i]=read();
		tot+=a[i];
	}
	printf("%.10lf\n",tot*1.0/(1<<n));
	while(Q--){
		int x=read(),y=read();
		tot-=a[x];
		a[x]=y;
		tot+=a[x];
		printf("%.10lf\n",tot*1.0/(1<<n));
	}
	return 0;
}