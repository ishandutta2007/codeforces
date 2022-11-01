#include<bits/stdc++.h>
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
int T,n,d[N];
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		d[i]=read();	
	}	
	ll ans=0;
	sort(d+1,d+n+1);
	for(int i=2;i<=n;++i){
		int x=d[i]-d[i-1];
		ans+=x;
		ans-=1LL*(i-1)*(n-i+1)*x;	
	}
	printf("%lld\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}