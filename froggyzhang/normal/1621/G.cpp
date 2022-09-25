#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int mod=1e9+7;
typedef long long ll;
class BIT{
	int Len;
	vector<int> b;
	inline int lowbit(int x){return x&(-x);}
public:
	BIT(int _n){b.resize(_n+1),Len=_n;}
	inline void Add(int x,int d){
		while(x<=Len)b[x]=(b[x]+d)%mod,x+=lowbit(x);
	}
	inline int Ask(int x){
		int ans=0;
		while(x)ans=(b[x]+ans)%mod,x-=lowbit(x);
		return ans;
	}
	int Query(int l,int r){
		if(l>r)return 0;
		return (Ask(r)-Ask(l-1)+mod)%mod;
	}
};
int n,a[N],b[N],len,g[N],dp[N][2];
vector<int> p[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i)p[i].clear();
	for(int i=1;i<=n;++i){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	len=unique(b+1,b+n+1)-b-1;
	BIT A(len);
	for(int i=1;i<=n;++i){
		a[i]=lower_bound(b+1,b+len+1,a[i])-b;
		p[a[i]].push_back(i);
	}
	for(int i=1;i<=n;++i){
		g[i]=(A.Ask(a[i]-1)+1)%mod;
		A.Add(a[i],g[i]);
	}
	BIT B(n),B0(n),B1(n);
	int mx=0;
	vector<int> H;
	int ans=0;
	for(int i=len;i>=1;--i){
		for(auto x:p[i]){
			if(x>mx){
				for(auto u:H){
					B.Add(u,dp[u][1]);
					B0.Add(u,mod-dp[u][0]);
					B1.Add(u,mod-dp[u][1]);
				}
				mx=x;
				dp[x][0]=0,dp[x][1]=1;
				B1.Add(x,1);
				H.clear();
			}
			else{
				int t=B.Query(x+1,mx);
				dp[x][0]=(t+B0.Query(x+1,mx)+1)%mod;
				dp[x][1]=(t+B1.Query(x+1,mx)+1)%mod;
				ans=(ans+1LL*dp[x][0]*g[x])%mod;
				B0.Add(x,dp[x][0]);
				B1.Add(x,dp[x][1]);
			}
			H.push_back(x);
		}
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