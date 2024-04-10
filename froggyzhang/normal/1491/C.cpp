#include<bits/stdc++.h>
using namespace std;
#define N 5005
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
int T,n,a[N],t[N];
ll Solve(){
	n=read();
	ll ans=0;
	for(int i=1;i<=n;++i){
		a[i]=read();
		t[i]=0;
	}
	for(int i=1;i<=n;++i){
		if(a[i]>t[i]+1)ans+=a[i]-t[i]-1,t[i]=a[i]-1;
		t[i+1]+=t[i]-a[i]+1;
		for(int j=2;j<=a[i]&&i+j<=n;++j){
			++t[i+j];
		}
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