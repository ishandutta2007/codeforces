#include<bits/stdc++.h>
using namespace std;
#define N 30030
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
int n,C,Q,a[N];
ll dp[N][5],sm[N][5];
void Solve(){
	n=read(),C=read(),Q=read();
	memset(dp,0,sizeof(dp));
	memset(sm,0,sizeof(sm));
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=0;i<=C;++i)dp[n+1][i]=1,sm[n+1][i]=0;
	for(int i=n;i>=1;--i){
		for(int j=0;j<=C;++j){
			sm[i][j]=sm[i+1][j];
			for(int k=0;k<=j&&i+k<=n;++k){
				dp[i][j]+=dp[i+k+1][j-k];
				if(a[i+k]<a[i])sm[i][j]+=dp[i+k+1][j-k];
			}
		}
	}
	while(Q--){
		int pos=read();
		ll k=read();
		if(k>dp[1][C]){
			puts("-1");
			continue;
		}
		int u=1,rem=C;
		while("zyk nb!"){
			int l=1,r=n-u+2,ans=0;
			auto check = [&](int x) -> bool{
				return sm[u][rem]-sm[u+x][rem]<k&&sm[u][rem]-sm[u+x][rem]+dp[u+x][rem]>=k;
			};
			while(l<r){
				int mid=(l+r)>>1;
				if(check(mid))l=mid+1,ans=mid;
				else r=mid;
			}
			k-=sm[u][rem]-sm[u+ans][rem];
			u+=ans;
			if(u>pos){
				printf("%d\n",a[pos]);break;
			}
			static vector<int> t;
			t.clear();
			for(int i=0;i<=min(n-u,rem);++i)t.push_back(i);
			sort(t.begin(),t.end(),[&](int i,int j){return a[u+i]<a[u+j];});
			int len=0;
			for(auto x:t){
				ll w=dp[u+x+1][rem-x];
				if(k>w){
					k-=w;
				}
				else{
					len=x,rem-=x;
					break;
				}
			}
			u+=len;
			if(u>=pos){
				printf("%d\n",a[u+(u-len)-pos]);break;
			}
			++u;
		}
	}
}
int main(){
	int T=read();
	while(T--)Solve();
	return 0;
}