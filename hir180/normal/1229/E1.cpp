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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
int n,m;
ll cnt[(1<<20)],cnt2[(1<<20)];
ll a[10][10];
int rev[(1<<20)],rev2[(1<<20)];
void dfs(int cur,vector<int>con,ll prob){
	if(cur == m){
		int nxt = 0, id = 0;
		rep(j,(1<<n)){
			if(__builtin_popcount(j) != m) continue;
			vector<int>vi; rep(i,n) if(((j>>i)&1)) vi.pb(i);
			int ok = 0;
			do{
				rep(x,m) if(!((con[x]>>vi[x])&1)) goto fail;
				ok = 1; break; fail:;
			}while(next_permutation(vi.begin(),vi.end()));
			if(ok) id |= (1<<nxt);
			nxt++;
		}
		cnt[id] += prob;
		return;
	}
	rep(j,(1<<n)){
		con.pb(j);
		ll nw = prob;
		rep(k,n){
			if(((j>>k)&1)){
				nw = nw*a[cur][k]%mod;
			}
			else{
				nw = nw*(mod+1-a[cur][k])%mod;
			}
		}
		dfs(cur+1,con,nw);
		con.pop_back();
	}
}
void dfs2(int cur,vector<int>con,ll prob){
	if(cur == n){
		int nxt = 0, id = 0;
		rep(j,(1<<n)){
			if(__builtin_popcount(j) != n-m) continue;
			vector<int>vi; rep(i,n) if(((j>>i)&1)) vi.pb(i);
			int ok = 0;
			do{
				rep(x,n-m) if(!((con[x]>>vi[x])&1)) goto fail2;
				ok = 1; break; fail2:;
			}while(next_permutation(vi.begin(),vi.end()));
			if(ok) id |= (1<<nxt);
			nxt++;
		}
		cnt2[id] += prob;
		return;
	}
	rep(j,(1<<n)){
		con.pb(j);
		ll nw = prob;
		rep(k,n){
			if(((j>>k)&1)){
				nw = nw*a[cur][k]%mod;
			}
			else{
				nw = nw*(mod+1-a[cur][k])%mod;
			}
		}
		dfs2(cur+1,con,nw);
		con.pop_back();
	}
}

int main(){
	cin >> n;
	rep(i,n) rep(j,n){
		cin >> a[i][j]; a[i][j] = a[i][j]*modpow(100LL,mod-2)%mod; a[i][j] = (a[i][j]%mod+mod)%mod;
	}
	if(n == 1){
		cout << a[0][0] << endl;
		return 0;
	}
	m = n/2;
	dfs(0,vector<int>(),1);
	rep(i,(1<<20)) cnt[i] %= mod;
	//cnt[j]... j no submask
	for(int i=0;i<20;i++){
		for(int j=0;j<(1<<20);j++){
			if(((j>>i)&1)){
				cnt[j] += cnt[j^(1<<i)];
				cnt[j] %= mod;
			}
		}
	}
	ll all = cnt[(1<<20)-1];
	dfs2(m,vector<int>(),1);
	rep(i,(1<<20)) cnt2[i] %= mod;
	memset(rev,-1,sizeof(rev));
	int nd = 0;
	rep(i,(1<<n)){
		if(__builtin_popcount(i) != m) continue;
		rev[i] = nd++;
	}
	memset(rev2,-1,sizeof(rev2));
	nd = 0;
	int cor[25]={};
	rep(i,(1<<n)){
		if(__builtin_popcount(i) != n-m) continue;
		cor[nd] = rev[(1<<n)-1-i];
		rev2[i] = nd++;
	}
	ll ans = 0;
	rep(i,(1<<nd)){
		ll cur = cnt2[i];
		int mask = 0;
		rep(j,nd){
			if(((i>>j)&1));
			else mask += (1<<cor[j]);
		}
		ans += cur * (all-cnt[mask]) %mod;
	}
	cout << (ans%mod+mod)%mod << endl;
}