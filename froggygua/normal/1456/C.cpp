#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 500010
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
int n,m,a[N];
ll ans,s[N],now;
int main(){
	n=read(),m=read()+1;
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
		now+=1LL*(n-i)*a[i];
	}
	ans=now;
	for(int i=n;i>=1;--i){
		if((n-i)%m){
			now-=s[i];
		}
		ans=max(ans,now);
	}
	printf("%lld\n",ans);
	return 0;
}