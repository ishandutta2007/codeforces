#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> poly;
const int mod=1e9+7;
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		y>>=1,x=1ll*x*x%mod;
	}
	return r;
}
int n,K,a[100005],jc[100005]={1},ny[100005]={1},suf[100005],ans=0,pwk[100005]={1},mul[100005],fin[100005];
poly pre[5005];
poly Multi(poly a,poly b){
	poly ret;
	ret.resize(a.size()+b.size()-1);
	for(int i=0;i<a.size();i++)for(int j=0;j<b.size();j++)ret[i+j]=(ret[i+j]+1ll*a[i]*b[j])%mod;
	return ret;
}
poly Add(const poly &a,const poly &b){
	poly ret(max(a.size(),b.size()));
	if(a.size()<b.size()){
		for(int i=0;i<a.size();i++)ret[i]=(a[i]+b[i])%mod;
		for(int i=a.size();i<b.size();i++)ret[i]=b[i];
	}
	else {
		for(int i=0;i<b.size();i++)ret[i]=(a[i]+b[i])%mod;
		for(int i=b.size();i<a.size();i++)ret[i]=a[i];
	}
	return ret;
}
int main(){
//	freopen("manastorm.in","r",stdin);
//	freopen("manastorm.out","w",stdout);
	for(int i=1;i<=100000;i++)jc[i]=1ll*jc[i-1]*i%mod,ny[i]=Power(jc[i],mod-2);
	cin>>n>>K,pre[0].push_back(1),suf[n+1]=1,mul[0]=K;
	if(!K)return puts("0"),0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i;i--)suf[i]=1ll*suf[i+1]*a[i]%mod;
	for(int i=0;i<=K&&i<=n+1;i++)pwk[i]=Power(n,K-i);
	for(int i=1;i<=K&&i<=n+1;i++)mul[i]=1ll*mul[i-1]*(K-i)%mod;
	for(int i=1;i<=n;i++){
		poly t;
		t.push_back(a[i]),t.push_back(mod-1),pre[i]=Multi(pre[i-1],t);
	}
	for(int i=0;i<n;i++)for(int j=0;j<pre[i].size();j++)fin[j]=(fin[j]+1ll*pre[i][j]*suf[i+2])%mod;
	for(int j=0;j<n&&j<K;j++)ans=(ans+1ll*fin[j]*pwk[j+1]%mod*mul[j])%mod;
	cout<<1ll*ans*Power(Power(n,mod-2),K)%mod;
}
/*
4 4
1 2 3 4
n=5000 K=10^9 a_i=23333
657217986
*/