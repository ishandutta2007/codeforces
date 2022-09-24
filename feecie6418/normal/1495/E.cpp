#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll s[3],sum;
int n,m,a[5000005],f[5000005],bel[5000005],seed,base;
int rnd(){
	int ret=seed;
	seed=(1ll*seed*base+233)%mod;
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,p,k,b,w,lst=1;i<=m;lst=p+1,i++){
		scanf("%d%d%d%d",&p,&k,&b,&w);
		seed=b,base=w;
		for(int j=lst;j<=p;j++)bel[j]=rnd()%2+1,a[j]=rnd()%k+1;
	}
	for(int i=1;i<=n;i++)s[bel[i]]+=a[i],f[i]=a[i];
	long long ans=1;
	sum+=s[bel[1]]>=s[3-bel[1]];
	if(s[1]>=s[2]){
		for(int i=1;i<=n;i++){
			if(bel[i]==2)sum+=a[i],a[i]=0;
			else {
				int o=min(sum,1ll*a[i]);
				a[i]-=o,sum-=o;
			}
		}
		for(int i=1;i<=n;i++){
			if(bel[i]==2)sum+=a[i],a[i]=0;
			else {
				int o=min(sum,1ll*a[i]);
				a[i]-=o,sum-=o;
			}
		}
		for(int i=1;i<=n;i++)ans=1ll*(((1ll*i*i)^(f[i]-a[i]))+1)%mod*ans%mod;
	}
	else {
		for(int i=1;i<=n;i++){
			if(bel[i]==1)sum+=a[i],a[i]=0;
			else {
				int o=min(sum,1ll*a[i]);
				a[i]-=o,sum-=o;
			}
		}
		for(int i=1;i<=n;i++){
			if(bel[i]==1)sum+=a[i],a[i]=0;
			else {
				int o=min(sum,1ll*a[i]);
				a[i]-=o,sum-=o;
			}
		}
		for(int i=1;i<=n;i++)ans=1ll*(((1ll*i*i)^(f[i]-a[i]))+1)%mod*ans%mod;
	}
	cout<<ans;
}