#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,m,a[200005],b[200005],cnt[200005],S=1,tmp[200005];
int jc[200005],ny[200005],c[200005];
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
void U(int x,int y){
	while(x<=200000)c[x]+=y,x+=x&-x;
}
int Q(int x){
	int r=0;
	while(x)r+=c[x],x-=x&-x;
	return r;
}
void Solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),cnt[a[i]]++,U(a[i],1),tmp[a[i]]++;
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	for(int i=1;i<=200000;i++)S=1ll*S*ny[cnt[i]]%mod;
	int ans=0;
	for(int i=0;i<m&&i<n;i++){
		ans=(ans+1ll*Q(b[i+1]-1)*jc[n-i-1]%mod*S)%mod;
		if(!cnt[b[i+1]])break;
		S=1ll*S*jc[cnt[b[i+1]]]%mod;
		cnt[b[i+1]]--;
		U(b[i+1],-1);
		S=1ll*S*ny[cnt[b[i+1]]]%mod;
	}
	if(n<m){
		bool ok=1;
		for(int i=1;i<=n;i++){
			tmp[b[i]]--;
			if(tmp[b[i]]<0)ok=0;
		}
		if(ok)ans=(ans+1)%mod;
	}
	cout<<ans;
}
int main(){
	jc[0]=ny[0]=1;
	for(int i=1;i<=200000;i++)jc[i]=1ll*jc[i-1]*i%mod;
	ny[200000]=Power(jc[200000],mod-2);
	for(int i=199999;i;i--)ny[i]=1ll*ny[i+1]*(i+1)%mod;
	int t=1;
	while(t--)Solve();
}