#pragma GCC optimize(2)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[1000005],w[1000005],cnt[1000005],tot,ans=1;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int o=1;o<=12;o++){
		memset(cnt,0,sizeof(cnt)),tot=0;
		ll x=a[1ll*rand()*rand()%n+1];
		for(ll i=1;i*i<=x;i++){
			if(x%i)continue;
			w[++tot]=i;
			if(i*i!=x)w[++tot]=x/i;
		}
		sort(w+1,w+tot+1);
		for(int i=1;i<=n;i++)++cnt[lower_bound(w+1,w+tot+1,__gcd(a[i],x))-w];
		for(int i=1;i<=tot;i++){
			for(int j=1;j<i;j++)if(w[i]%w[j]==0)cnt[j]+=cnt[i];
		}
		for(int i=tot;i>=1;i--)if(cnt[i]*2>=n)ans=max(ans,w[i]);
	}
	cout<<ans;
}