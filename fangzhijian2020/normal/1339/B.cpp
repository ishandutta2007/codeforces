#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int T,n,a[100005];
int main(){
	T=read()+1;
	while(--T){
		n=read();
		for(int i=1;i<=n;++i)a[i]=read();
		sort(a+1,a+n+1);
		if(n&1)printf("%d ",a[(n+1)/2]);
		for(int i=n/2;i;--i){
			printf("%d %d ",a[i],a[n-i+1]);
		}
		puts("");
	}
	return 0;
}