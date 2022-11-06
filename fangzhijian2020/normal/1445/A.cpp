#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read(){
	int a=0,opt=0;char c=getchar();while(c<'0'||'9'<c)opt|=c=='-',c=getchar();
	while('0'<=c&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();return opt?-a:a;
}
int T,n,x,opt,a[55],b[55];
int main(){
	T=read()+1;
	while(--T){
		n=read();x=read();opt=0;
		for(int i=1;i<=n;++i)a[i]=read();
		for(int i=1;i<=n;++i)b[i]=read();
		for(int i=1;i<=n;++i){
			if(a[i]+b[n-i+1]>x){
				puts("No");opt=1;break;
			}
		}
		if(!opt)puts("Yes");
	}
	return 0;
}