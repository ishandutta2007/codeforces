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
#define N 300030
int T,n,m,a[N],c[N];
ll Solve(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=m;++i){
		c[i]=read();
	}
	sort(a+1,a+n+1);
	int p=1;
	for(int i=n;i>=1;--i){
		if(a[i]<n-i+1){
			p=i+1;break;
		}
	}
	ll ans=0;
	for(int i=1;i<p;++i)ans+=c[a[i]];
	for(int i=1;i<=n-p+1;++i){
		ans+=c[i];
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