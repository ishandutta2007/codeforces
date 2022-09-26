#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
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
int n;
ll a[N];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	if(n==1){
		puts("1 1");
		printf("%d\n",-a[1]);
		puts("1 1");
		puts("0");
		puts("1 1");
		puts("0");
		return 0;
	}
	printf("%d %d\n",1,n-1);
	for(int i=1;i<=n-1;++i){
		ll tmp=1LL*(a[i]%n+n)%n*(n-1);
		printf("%I64d ",tmp);
		a[i]+=tmp;
	}
	printf("\n");
	printf("%d %d\n",n,n);
	printf("%d\n",-a[n]);
	a[n]=0;
	printf("%d %d\n",1,n);
	for(int i=1;i<=n;++i){
		printf("%I64d ",-a[i]);
	}
	return 0;
}