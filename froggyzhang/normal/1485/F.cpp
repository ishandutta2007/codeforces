#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int mod=1e9+7;
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
int n,a[N],T;
ll s[N];
map<ll,int> mp;
int Solve(){
	int ans=1;
	mp.clear();
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		s[i]=s[i-1]+a[i-1];
	}
	mp[0]=1;
	for(int i=1;i<=n;++i){
		int p=(ans-mp[s[i]]+mod)%mod;
		ans=(ans+p)%mod;
		mp[s[i]]=(mp[s[i]]+p)%mod;
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		printf("%d\n",Solve());
	}
	return 0;
}