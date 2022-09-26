#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
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
int T,n,k,a[233];
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		if(k>(n-1)/2){
			puts("-1");
			continue;
		}
		for(int i=1;i<=n;++i)a[i]=0;
		int now=n;
		for(int i=2;i<=2*k;i+=2){
			a[i]=now;--now;
		}
		for(int i=n;i>=1;--i){
			if(!a[i])a[i]=now,now--;
		}
		for(int i=1;i<=n;++i){
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	return 0;
}