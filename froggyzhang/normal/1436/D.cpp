#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 200020
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
int n,f[N],a[N],leaf[N];
ll s[N];
int main(){
	n=read();
	for(int i=1;i<=n;++i)leaf[i]=1;
	for(int i=2;i<=n;++i){
		f[i]=read();
		leaf[f[i]]=0;
	}
	for(int i=1;i<=n;++i){
		s[i]=a[i]=read();
	}
	for(int i=n;i>=1;--i){
		s[f[i]]+=s[i];
		leaf[f[i]]+=leaf[i];
	}
	ll ans=0;
	for(int i=1;i<=n;++i){
		ans=max(ans,(s[i]+leaf[i]-1)/leaf[i]);
	}
	printf("%lld\n",ans);
	return 0;
}