#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int mu[100005],vst[100005],p[100005],n,v1[100005],v2[100005],s1[100005],s2[100005];
int smu[100005],sii1[100005],rs[100005];
int S(int x){
	if(v1[x])return s1[x];
	v1[x]=1;
	for(int i=1,j;i<=x;i=j+1){
		j=x/(x/i);
		s1[x]=(s1[x]+1ll*(smu[j]-smu[i-1]+mod)%mod*sii1[x/i])%mod;
	}
	return s1[x];
}
int S2(int x){
	if(v2[x])return s2[x];
	v2[x]=1;
	for(int i=1,j;i<=x;i=j+1){
		j=x/(x/i);
		int w=1ll*(x/i)*(x/i-1)/2%mod;
		s2[x]=(s2[x]+1ll*(rs[j]-rs[i-1]+mod)%mod*w)%mod;
	}
	return s2[x];
}
int main(){
	cin>>n;
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!vst[i])p[++p[0]]=i,mu[i]=mod-1;
		for(int j=1;j<=p[0]&&i*p[j]<=n;j++){
			vst[i*p[j]]=1;
			if(i%p[j])mu[i*p[j]]=mod-mu[i];
			else {
				mu[i*p[j]]=0;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		smu[i]=(smu[i-1]+1ll*i*mu[i])%mod;
		rs[i]=(rs[i-1]+mu[i])%mod;
		sii1[i]=(sii1[i-1]+1ll*i*(i-1))%mod;
	}
	int ans=0;
	for(int d=1;d<=n;d++){
		int w=d/__gcd(d,n);
		int s1=1ll*w*d%mod*S(n/d-(n%d==0))%mod,s2=1ll*w*n%mod*S2(n/d-(n%d==0))%mod;
		ans=(ans+s2)%mod;
		ans=(ans-s1+mod)%mod;
		//cout<<d<<' '<<ans<<' '<<S(1)<<' '<<S2(1)<<'\n';
	}
	cout<<ans;
}