#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const int mod=998244353;
int n,m,a[N],b[N],pa[N],pb[N],vis[N],g[N];
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>pa[i];
		vis[i]=g[i]=0;
		b[i]=-1;
	}
	for(int i=1;i<=n;++i){
		cin>>pb[i];
	}
	for(int i=1;i<=n;++i){
		a[pa[i]]=i;
		if(~pb[i])b[pb[i]]=i;
	}
	for(int i=1;i<=n;++i){
		if(~b[i])vis[b[i]]=i;
	}
	for(int i=1;i<=n;++i){
		if(vis[a[i]]){
			if(i-vis[a[i]]>m){
				cout<<0<<'\n';
				return;
			}
		}
		else{
			++g[max(1,i-m)];
		}
	}
	int ans=1,cnt=0;
	for(int i=1;i<=n;++i){
		cnt+=g[i];
		if(!~b[i])ans=1LL*ans*cnt%mod,--cnt;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}