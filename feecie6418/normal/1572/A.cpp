#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,f[300005],ind[300005];
vector<int> g[300005];
void Solve(){
	scanf("%d",&n);
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k),ind[i]=k;
		for(int j=1,x;j<=k;j++)scanf("%d",&x),g[x].push_back(i);
	}
	queue<int> q;
	int cnt=0,ans=0;
	for(int i=1;i<=n;i++)if(!ind[i])q.push(i),f[i]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop(),cnt++,ans=max(ans,f[x]);
		for(int y:g[x]){
			if(y<x)f[y]=max(f[y],f[x]+1);
			else f[y]=max(f[y],f[x]);
			if(!--ind[y])q.push(y);
		}
	}
	if(cnt!=n)puts("-1");
	else cout<<ans<<'\n';
	for(int i=1;i<=n;i++)ind[i]=f[i]=0,g[i].clear();
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}