#include<iostream>
#include<cstring>
#include<cstdio>
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
int T,x,n,a[N];
int main(){
	T=read();
	while(T--){
		n=read(),x=read();
		int sum=0,ans=n;
		for(int i=1;i<=n;++i){
			a[i]=read();
			sum+=a[i];
			if(a[i]%x)ans=min(ans,min(i,n-i+1));
		}
		if(sum%x){
			printf("%d\n",n);
		}
		else if(ans<n){
			printf("%d\n",n-ans);
		}
		else{
			printf("%d\n",-1);
		}
	}
	return 0;
}