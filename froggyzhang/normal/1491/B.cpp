#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define N 100010
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
int T,n,u,v,a[N];
int Solve(){
	n=read(),u=read(),v=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	if(n==1)return -1;
	for(int i=2;i<=n;++i){
		if(abs(a[i]-a[i-1])>=2)return 0;
	}
	bool same=true;
	for(int i=2;i<=n;++i){
		if(a[i]^a[1]){
			same=false;
			break;
		}
	}
	return same?v+min(u,v):min(u,v);
}
int main(){
	T=read();
	while(T--){
		printf("%d\n",Solve());
	}
	return 0;
}