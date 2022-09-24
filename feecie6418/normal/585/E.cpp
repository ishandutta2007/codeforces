#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,cnt[10000005],pw2[500005]={1},f[10000005],g[10000005],h[10000005],m=1e7;
int v[10000005],p[10000005];
void Del(int &x,int y){x-=y;if(x<0)x+=mod;}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cin>>n;
	for(int i=1,x;i<=n;i++)cin>>x,cnt[x]++,pw2[i]=pw2[i-1]*2%mod;
	for(int i=2;i<=m;i++){
		if(v[i])continue;
		p[++p[0]]=i;
		for(ll j=1ll*i*i;j<=m;j+=i)v[j]=1;
	}
	for(int i=1;i<=p[0];i++)for(int j=m/p[i];j;j--)cnt[j]+=cnt[j*p[i]];
	for(int i=m;i>=1;i--)f[i]=h[i]=pw2[cnt[i]]-1;
	for(int i=1;i<=p[0];i++)for(int j=1;j*p[i]<=m;j++)Del(h[j],h[j*p[i]]);
	for(int i=m;i>=1;i--)g[i]=1ll*f[i]*cnt[i]%mod;
	for(int i=1;i<=p[0];i++)for(int j=1;j*p[i]<=m;j++)Del(g[j],g[j*p[i]]);
	cout<<(g[1]-1ll*n*h[1]%mod+mod)%mod;
}