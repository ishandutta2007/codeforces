#include<bits/stdc++.h>
using namespace std;
#define N 200010
const int mod=998244353;
typedef long long ll;
int n,s[N],a[N],dp[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	dp[0]=s[0]=1;
	for(int i=1,now=0;i<=n;++i){
		static int st[N],top;
		while(top&&a[i]<=a[st[top]]){
			now=(now+1LL*(mod-a[st[top]])*(s[st[top]-1]-(top>1?s[st[top-1]-1]:0)))%mod;
			--top;	
		}
		now=(now+1LL*a[i]*(s[i-1]-(top?s[st[top]-1]:0)+mod))%mod;
		st[++top]=i;
		dp[i]=i&1?now:mod-now;
		s[i]=(s[i-1]+(i&1?mod-dp[i]:dp[i]))%mod;
	}
	cout<<dp[n]%mod<<'\n';
	return 0;
}