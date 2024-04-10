#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
int n,m,cnt[N],p[N],vis[N],o;
bitset<N> dp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>p[i];
	}
	vector<int> zz;
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		int jb=0;
		for(int u=i;!vis[u];u=p[u])vis[u]=1,++jb;
		++cnt[jb];
		for(int j=2;j<=jb;j+=2)zz.push_back(2);
		if(jb&1)zz.push_back(1);
	}
	sort(zz.begin(),zz.end(),greater<int>());
	int o=0;
	for(int i=0;i<min((int)zz.size(),m);++i){
		o+=zz[i];
	}
	dp[0]=1;
	for(int i=1;i<=n;++i){
		if(!cnt[i])continue;
		for(int p=1;p<=cnt[i];p<<=1){
			cnt[i]-=p;
			dp|=dp<<(i*p);
		}
		dp|=dp<<(cnt[i]*i);
	}
	cout<<m+1-dp[m]<<' '<<o<<'\n';
	return 0;
}