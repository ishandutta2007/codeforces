#include<bits/stdc++.h>
using namespace std;
#define N 233
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
int T,n,k,a[N];
void Solve(){
	n=read(),k=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<n;++i){
		if(a[i]<=k)k-=a[i],a[n]+=a[i],a[i]=0;
		else a[i]-=k,a[n]+=k,k=0;
	}
	for(int i=1;i<=n;++i){
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}