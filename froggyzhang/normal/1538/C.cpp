#include<bits/stdc++.h>
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
int n,a[N],l,r,T;
void Solve(){
	ll ans=0;
	n=read(),l=read(),r=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		ans-=(a[i]+a[i]>=l&&a[i]+a[i]<=r);
	}
	sort(a+1,a+n+1);
	int j=n,k=n;
	for(int i=1;i<=n;++i){
		while(j&&a[i]+a[j]>=l)--j;
		while(k&&a[i]+a[k]>r)--k;
		ans+=k-j;
	}
	ans>>=1;
	printf("%lld\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}