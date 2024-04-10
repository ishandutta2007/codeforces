#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100010
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
	return x*f;
}
int n,a[N],vis[N];
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]%a[1]!=0){
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n",2*n);
	for(int i=1;i<=2*n;i+=2){
		if(i^1)printf(" ");
		printf("%d %d",a[(i+1)/2],a[1]);
	}
	return 0;
}