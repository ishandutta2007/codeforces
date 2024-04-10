#include<bits/stdc++.h>
using namespace std;
#define N 3030
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
int n,m,l[N],r[N],a[N];
ll dp[N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		l[i]=read(),r[i]=read(),a[i]=read();
	}
	for(int i=n;i>=1;--i){
		ll need=a[i]+(i<n&&r[i]==l[i+1]?dp[i+1]:0);
		if(1LL*m*(r[i]-l[i]+1)<need){
			return !printf("-1\n");	
		}
		dp[i]=max(0LL,need-1LL*m*(r[i]-l[i]));
	}
	ll now=0,ans=0;
	for(int i=1;i<=n;++i){
		if(now<dp[i]){
			ans+=now,now=m;
		}	
		ans+=a[i];
		now=((now-a[i])%m+m)%m;
	}
	printf("%lld\n",ans);
	return 0;
}