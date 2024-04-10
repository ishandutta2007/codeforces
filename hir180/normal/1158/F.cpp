#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define per(i,x) for(int i=x-1;i>=0;i--)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}
const int mod = 998244353;
template<class T>
void add(T&a, T b){
	a += b;
	if(a >= mod) a-=mod;
}
int n,c,a[3005];
ll bin[3005],rev[3005],revo[3005],endd[3005];
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
int dp[2][3005][(1<<12)];
int cnt[3005];
int ans[3005];

int main(){
	scanf("%d%d",&n,&c);
	mt19937 mt(61471);
	repn(i,n){
		scanf("%d",&a[i]);
		a[i]--;
	}
	bin[0] = 1;
	for(int i=1;i<3005;i++) bin[i] = bin[i-1]*2LL%mod;
	rep(i,3005) rev[i] = modpow(bin[i], mod-2);
	rep(i,3005) revo[i] = modpow(bin[i]-1, mod-2);
	
	if(c <= 12){
		int cur = 0, nxt = 1;
		dp[0][0][0] = 1;
		repn(i,n){
			rep(x,i/c+2) rep(y,(1<<c)) dp[nxt][x][y] = 0;
			int M = (1<<a[i]);
			rep(x,i/c+2) rep(y,(1<<c)){
				if(dp[cur][x][y] == 0) continue;
				//add
				{
					if((y|M) == (1<<c)-1){
					    dp[nxt][x+1][0]+=dp[cur][x][y];
					    if(dp[nxt][x+1][0]>=mod)dp[nxt][x+1][0]-=mod; 
					}
					else{
					    dp[nxt][x][(y|M)]+=dp[cur][x][y];
					    if(dp[nxt][x][(y|M)]>=mod) dp[nxt][x][(y|M)]-=mod;
					}
				}
				//not add
				dp[nxt][x][y]+=dp[cur][x][y];
				if(dp[nxt][x][y]>=mod)dp[nxt][x][y]-=mod;
			}
			swap(cur, nxt);
		}
		rep(x,n/c+2) rep(y,(1<<c)){
			add(ans[x], dp[cur][x][y]);
		}
		add(ans[0], mod-1);
		rep(i,n+1){
			printf("%d\n",ans[i]);
		}
		return 0;
	}
	else{
		dp[0][0][0] = 1;
		endd[n+1] = 1;
		for(int i=1;i<=n;i++){
			memset(cnt,0,sizeof(cnt));
			for(int j=i;j<=n;j++) cnt[a[j]]++;
			ll way = 1;
			rep(i,c) way = way*(bin[cnt[i]]-1)%mod;
			endd[i] = bin[n+1-i]+mod-way;
			if(endd[i] >= mod) endd[i] -= mod;
			for(int j=n;j>=i;j--){
				//cnt[a[j]]
				way = way*revo[cnt[a[j]]]%mod;
				rep(x,i/c+2){
					dp[0][j][x+1]+=(int)(way*1LL*dp[0][i-1][x]%mod);
					if(dp[0][j][x+1]>=mod)dp[0][j][x+1]-=mod;
				}
				way = way*(bin[--cnt[a[j]]]-1)%mod;
			}
		}
		rep(x,n+1) rep(y,n/c+2) {
			add(ans[y], (int)(dp[0][x][y]*endd[x+1]%mod));
		}
		add(ans[0], mod-1);
		rep(i,n+1){
			printf("%d\n",ans[i]);
		}
		return 0;
	}
}