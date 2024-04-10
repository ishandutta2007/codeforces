#include<bits/stdc++.h>
using namespace std;
#define N 400040
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
int T,n,a[N];
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	ll ans=0;
	a[n+1]=0;
	for(int i=1;i<=n;++i){
		if(a[i]>a[i-1]&&a[i]>a[i+1]){
			ans+=a[i]-max(a[i-1],a[i+1]);
			a[i]=max(a[i-1],a[i+1]);
		}
	}
	for(int i=1;i<=n+1;++i)ans+=abs(a[i]-a[i-1]);
	printf("%lld\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}