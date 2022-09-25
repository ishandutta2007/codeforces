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
int T,n,a[N];
ll s[N];
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	double ans=-1e18;
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<n;++i){
		ans=max(ans,s[i]*1.0/i+(s[n]-s[i])*1.0/(n-i));	
	}
	printf("%.8lf\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	};;
	return 0;
}