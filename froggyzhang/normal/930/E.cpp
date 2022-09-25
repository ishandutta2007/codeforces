#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int inv2=(mod+1)/2;
#define N 200020
typedef long long ll;
int dp[N],K,n,m,ans,pre[2][N];
struct Range{
	int l,r,c;
	friend bool operator < (const Range &a,const Range &b){
		return a.r==b.r?a.l>b.l:a.r<b.r;	
	}	
}a[N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>K>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i].l>>a[i].r;
		a[i].c=0;
	}
	for(int i=1;i<=m;++i){
		cin>>a[n+i].l>>a[n+i].r;
		a[n+i].c=1;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;++i){
		a[i].l=max(a[i-1].l,a[i].l);	
	}
	sort(a+n+1,a+n+m+1);
	for(int i=2;i<=m;++i){
		a[n+i].l=max(a[n+i-1].l,a[n+i].l);
	}
	sort(a+1,a+n+m+1);
	ans=1;
	int j[2]={1,1},s[2]={0,0};
	for(int i=1;i<=n+m;++i){
		int t=qpow(inv2,a[i].r-a[i].l+1);
		dp[i]=mod-t;
		int c=a[i].c;
		while(j[c]<=n+m&&a[j[c]].r<a[i].l){
			s[c]=(s[c]+dp[j[c]++])%mod;
		}
		dp[i]=(dp[i]+1LL*(mod-s[c])*t)%mod;
		dp[i]=(dp[i]+1LL*(mod-qpow(inv2,a[i].r))*(pre[c][i-1]-pre[c][j[c]-1]+mod))%mod;
		ans=(ans+dp[i])%mod;
		pre[c][i]=(pre[c][i-1]+1LL*dp[i]*qpow(2,a[i].r))%mod;
		pre[c^1][i]=pre[c^1][i-1];
	}
	cout<<1LL*ans*qpow(2,K)%mod<<'\n';
	return 0;
}