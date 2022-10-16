#include<bits/stdc++.h>
using namespace std;
#define N 200010
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
int T,n;
ll a[N],f[20][N];
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<n;++i){
		f[0][i]=llabs(a[i+1]-a[i]);
	}
	--n;
	for(int j=1;j<=19;++j){
		for(int i=1;i+(1<<j)-1<=n;++i){
			f[j][i]=__gcd(f[j-1][i],f[j-1][i+(1<<j-1)]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		int u=i;
		ll g=0;
		for(int j=20;j>=0;--j){
			if(u+(1<<j)-1<=n&&__gcd(g,f[j][u])>1){
				g=__gcd(g,f[j][u]);
				u+=(1<<j);
			}	
		}
		ans=max(ans,u-i);
	}
	printf("%d\n",ans+1);
}
int main(){
	T=read();
	while(T--)Solve();
	return 0;
}