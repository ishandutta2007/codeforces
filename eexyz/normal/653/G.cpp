#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 300005
#define mod 1000000007
ll jc[N],ans,ny[N],f[N];
int n,p[N];
vector<int>gg[N];
ll ksm(ll x,ll y){ll ret=1;for(;y;y>>=1,x=x*x%mod)if(y&1)ret=ret*x%mod;return ret;}
ll C(int n,int m){return jc[n]*ny[m]%mod*ny[n-m]%mod;}
ll calc(int x,int y){
	if(x>y)swap(x,y);
	if(!x)return 0;
	ll res=0,now=ksm(2,y);int i;
	for(i=0;i<=x;++i)f[i]=jc[y]*ny[i]%mod*ny[y-i]%mod*i;
	for(i=1;i<=x;++i)(f[i]+=f[i-1])%=mod;
	for(i=0;i<=x;++i){
		(now-=C(y,i))%=mod;
		(res+=C(x,i)*(f[i]+now*i%mod))%=mod;
	}
	return res+mod;
}
int i,cnt,j,t[N],zz,e,U,u[20],c[210],tot,mn[N],d;
bool is[N];
int main(){
	cin>>n;
	for(i=2;i<=300000;++i){
		if(!is[i])p[++cnt]=i,mn[i]=i;
		for(j=1;(d=i*p[j])<=300000;++j){is[d]=1;mn[d]=p[j];if(i%p[j]==0)break;}
	}
	for(i=1;i<=n;++i){
		cin>>t[i];
		tot=0;
		while(t[i]>1){
			if(mn[t[i]]==u[tot])++c[tot];
			else u[++tot]=mn[t[i]],c[tot]=1;
			t[i]/=mn[t[i]];
		}
		for(j=1;j<=tot;++j)gg[u[j]].push_back(c[j]);
	}
	for(i=1;i<=cnt;++i)sort(gg[p[i]].begin(),gg[p[i]].end());
	for(jc[0]=ny[0]=i=1;i<=300000;++i)jc[i]=jc[i-1]*i%mod,ny[i]=ksm(jc[i],mod-2); 
	for(i=1;i<=cnt;++i){
		zz=300000;e=0;
		while(zz)zz/=p[i],++e;
		c[0]=n;for(j=1;j<=e;++j)c[j]=0;
		for(j=0;j<gg[p[i]].size();++j)--c[0],++c[gg[p[i]][j]];
		for(U=j=0;j<=e;++j)
			U+=c[j],ans+=calc(U,n-U);
	}
	cout<<ans%mod;
}