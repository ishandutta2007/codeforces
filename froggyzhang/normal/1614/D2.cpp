#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define N 200020
#define M 20000002
typedef long long ll;
const int MX=2e7;
int n,a[N],cnt[M],p[M>>2],pn;
bool ntp[M];
ll dp[M],ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		++cnt[a[i]];	
	}
	ntp[1]=1;
	for(int i=2;i<=MX;++i){
		if(!ntp[i]){
			p[++pn]=i;
			for(int j=i+i;j<=MX;j+=i){
				ntp[j]=1;	
			}
		}	
	}
	for(int j=1;j<=pn;++j){
		for(int i=MX/p[j];i>=1;--i){
			cnt[i]+=cnt[p[j]*i];		
		}
	}
	dp[1]=n;
	for(int i=1;i<=MX;++i){
		ans=max(ans,dp[i]);
		for(int j=1;p[j]*i<=MX&&j<=pn;++j){
			int k=p[j]*i;
			dp[k]=max(dp[k],dp[i]+1LL*cnt[k]*(k-i));	
		}
	}
	cout<<ans<<'\n';
	return 0;
}