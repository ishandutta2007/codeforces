#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 200020
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
int T,n,k,a[N];
ll Solve(){
	n=read(),k=read();
	for(int i=1;i<=n*k;++i){
		a[i]=read();
	}
	int p=n*k+1;
	n=n/2+1;
	ll ans=0;
	for(int i=1;i<=k;++i){
		p-=n;
		ans+=a[p];
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		printf("%lld\n",Solve());
	}
	return 0;
}