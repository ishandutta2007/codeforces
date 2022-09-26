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
int n,mod,k;
ll ans;
map<int,int> mp;
int main(){
	n=read(),mod=read(),k=read();
	for(int i=1;i<=n;++i){
		int x=read();
		int t=(1LL*x*x%mod*x%mod*x%mod-1LL*k*x%mod+mod)%mod;
		ans+=mp[t];
		++mp[t];
	}
	printf("%d\n",ans);
	return 0;
}