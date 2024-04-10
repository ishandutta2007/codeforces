#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef pair<int,int> pr;
typedef long long ll;
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
int n,ans=0,p[200005],cnt[200005],mn[200005],vst[200005];
struct Edge{
	int to,u,v;
};
vector<Edge> g[200005];
vector<pr> pk[200005];
void dfs1(int x,int fa,int val){
	ans=(ans+val)%mod;
	for(auto i:g[x]){
		int y=i.to;
		if(y==fa)continue;
		int tmp[25]={0};
		for(pr j:pk[i.u]){
			cnt[j.first]-=j.second;
			tmp[++tmp[0]]=j.first;
		}
		for(pr j:pk[i.v]){
			cnt[j.first]+=j.second;
			tmp[++tmp[0]]=j.first;
		}
		for(int j=1;j<=tmp[0];j++)mn[tmp[j]]=min(mn[tmp[j]],cnt[tmp[j]]);
		dfs1(y,x,1ll*val*Power(i.u,mod-2)%mod*i.v%mod);
		for(pr j:pk[i.u]){
			cnt[j.first]+=j.second;
		}
		for(pr j:pk[i.v]){
			cnt[j.first]-=j.second;
		}
	}
}
void Solve(){
	scanf("%d",&n);
	for(int i=1,x,y,z,w;i<n;i++){
		scanf("%d%d%d%d",&x,&y,&z,&w);
		g[x].push_back({y,z,w});
		g[y].push_back({x,w,z});
	}
	dfs1(1,0,1);
	for(int i=1;i<=n;i++){
		ans=1ll*ans*Power(i,-mn[i])%mod;
	}
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++){
		g[i].clear();
		cnt[i]=mn[i]=0;
	}
	ans=0;
}
int main(){
	for(int i=2;i<=200000;i++){
		if(!vst[i]){
			p[++p[0]]=i;
			for(int j=i+i;j<=200000;j+=i)vst[j]=1;
			for(int j=i;j<=200000;j+=i){
				int k=j,cnt=0;
				while(k%i==0)k/=i,cnt++;
				pk[j].push_back(pr(i,cnt));
			}
		}
	}
	int t;
	cin>>t;
	while(t--)Solve();
}