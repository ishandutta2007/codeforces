#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,K,L,a[N],s[N];
char z[N];
pair<int,int> check(int x){
	pair<int,int> dp[N];
	dp[0]=make_pair(0,0);
	for(int i=1;i<=n;++i){
		dp[i]=dp[i-1];
		if(i>=L)dp[i]=max(dp[i],make_pair(dp[i-L].first+s[i]-s[i-L]-x,dp[i-L].second+1));	
	}
	return dp[n];
}
int Solve(){
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	int l=0,r=n+1,ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		auto [w,t]=check(mid);
		if(t>=K){
			ans=w+mid*K;
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	return ans;
}
int main(){
	n=read(),K=read(),L=read();
	if(1LL*K*L>=n){
		return !printf("0\n");
	}
	scanf("%s",z+1);
	for(int i=1;i<=n;++i){
		if(z[i]>='A'&&z[i]<='Z')a[i]=1;
		else a[i]=0;
	}
	array<int,2> cnt={0,0};
	for(int i=1;i<=n;++i){
		++cnt[a[i]];
	}
	int t1=cnt[1]-Solve();
	for(int i=1;i<=n;++i)a[i]^=1;
	int t0=cnt[0]-Solve();
	printf("%d\n",min(t0,t1));
	return 0;
}