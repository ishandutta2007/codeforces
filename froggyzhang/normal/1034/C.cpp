#include<bits/stdc++.h>
using namespace std;
#define N 1000010
typedef long long ll;
const int mod=1e9+7;
int n,p[N],a[N],f[N],g[N],cnt[N],ok[N],ans;
ll S,s[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=2;i<=n;++i){
		cin>>f[i];
	}
	for(int i=n;i>=1;--i){
		s[i]+=a[i];
		s[f[i]]+=s[i];	
	}
	S=s[1];
	for(int i=1;i<=n;++i){
		ll t=S/__gcd(S,s[i]);
		if(t<=n)++cnt[t];
	}
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;j+=i)
			g[j]+=cnt[i];
	for(int i=1;i<=n;++i){
		ok[i]=g[i]==i;
	}
	for(int i=1;i<=n;++i){
		if(ok[i]){
			if(i>1)--ok[i];
			ans=(ans+ok[i])%mod;
			for(int j=i+i;j<=n;j+=i){
				if(ok[j])ok[j]+=ok[i];	
			}
		}	
	}
	cout<<ans<<'\n';
	return 0;
}