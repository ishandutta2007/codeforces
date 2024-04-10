#include<bits/stdc++.h>
using namespace std;
#define N 400020
const int mod=1e9+7;
typedef long long ll;
int n,a[N],b[N],dp[N],m,p[N],ok[N],ans;
class BIT{
	int b[N];
	inline int lowbit(int x){return x&(-x);}
public:
	inline void Add(int x,int d){
		while(x)b[x]=(b[x]+d)%mod,x-=lowbit(x);
	}
	inline int Ask(int x){
		int ans=0;
		while(x<=2*n)ans=(ans+b[x])%mod,x+=lowbit(x);
		return ans;
	}
}B;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
		p[i]=i;
	}
	sort(p+1,p+n+1,[&](int i,int j){return b[i]<b[j];});
	for(int i=1;i<=n;++i){
		int u=p[i];
		dp[u]=(1+B.Ask(a[u]))%mod;
		B.Add(a[u],dp[u]);
	}
	cin>>m;
	for(int i=1;i<=m;++i){
		int x;
		cin>>x;
		ok[x]=1;
	}
	for(int i=n,las=1;i>=1;--i){
		int u=p[i];
		B.Add(a[u],mod-dp[u]);
		if(ok[u]){
			if(a[u]>=las){
				ans=(ans+B.Ask(las)+1)%mod;
				las=a[u];
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}