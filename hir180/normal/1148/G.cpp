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

int k,n,a[100005];
int sm[10000005];
int cnt[10000005];
vector<int>vec[100005];
bool S[100005];

struct U{
	int par[100005],ran[100005];
	void init(){ for(int i=0;i<100005;i++) par[i] = i; }
	int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
	void unite(int x,int y){
		x = find(x); y = find(y); if(x==y) return;
		if(ran[x] < ran[y]) par[x] = y;
		else{
			par[y] = x;
			if(ran[x] == ran[y]) ran[x]++;
		}
	}
	bool same(int x,int y){ return find(x)==find(y); }
}kaede;

vector<int>id[100005];
vector<int>edge[100005];
int rev[256];

void dfs(int v,int u,int zan,vector<int>&vi){
	if(zan == vi.size()) return;
	vi.pb(v);
	rep(i,edge[v].size()){
		if(edge[v][i] == u) continue;
		dfs(edge[v][i],v,zan,vi);
	}
}
vector<int>qq[10000005];
int xxx[10000005];

int main(){
    rep(i,8) rev[(1<<i)] = i;
	for(int i=2;i<10000005;i++){
		if(sm[i]) continue;
		for(int j=2;i*j<10000005;j++) sm[i*j] = i;
	}
	scanf("%d%d",&n,&k);
	rep(i,n) scanf("%d",&a[i]);
	
	rep(i,n){
		int A = a[i];
		while(sm[A]){
			vec[i].pb(sm[A]);
			A /= sm[A];
		}
		vec[i].pb(A);
		
		SORT(vec[i]); ERASE(vec[i]);
		int sz = vec[i].size();
		int val[256];
		rep(mask,(1<<sz)){
			int x = 1;
			if(mask){
			    int k = mask&-mask;
			    x = val[mask-k] * vec[i][rev[k]];
			}
			cnt[x] ++;
			val[mask] = x;
			qq[x].pb(i);
		}
	}

	vector<int>sol;
	kaede.init();
	memset(xxx,-1,sizeof(xxx));
	bool EX = 0;

	rep(i,n){
		int sz = vec[i].size();
		int ret = 0;
		int val[256];
		rep(mask,(1<<sz)){
			int x = 1;
			if(mask){
			    int k = mask&-mask;
			    x = val[mask-k] * vec[i][rev[k]];
			}
			if(__builtin_popcount(mask)%2 == 0) ret += cnt[x];
			else ret -= cnt[x];
			val[mask] = x;
		}
		if(ret == 0){
			sol.pb(i);
			S[i] = 1;
		}
		else if(ret >= 2 && !EX){
			EX = 1;
			int pre = -1;
			rep(W,2){
				int lb = pre, ub = n-1;
				{
					while(ub-lb > 1){
						int mid = (lb+ub)/2;
						ll R = 0;
		        		rep(mask,(1<<sz)){
		        			int x = val[mask];
							if(__builtin_popcount(mask)%2 == 0) R += POSU(qq[x],mid);
							else R -= POSU(qq[x],mid);
						}
						if(R > W) ub = mid;
						else lb = mid;
					}
				}
				
				xxx[a[i]] = ub;
				
	          	assert(__gcd(a[i],a[ub]) == 1);
	          	
				if(kaede.same(i,ub) == false){
					kaede.unite(i,ub);
					edge[i].pb(ub);
					edge[ub].pb(i);
				}
				pre = ub;
			}
		}
		else{
			int lb = -1, ub = n-1;
			if(xxx[a[i]] == -1){
				while(ub-lb > 1){
					int mid = (lb+ub)/2;
					ll R = 0;
	        		rep(mask,(1<<sz)){
	        			int x = val[mask];
						if(__builtin_popcount(mask)%2 == 0) R += POSU(qq[x],mid);
						else R -= POSU(qq[x],mid);
					}
					if(R) ub = mid;
					else lb = mid;
				}
			}
			else ub = xxx[a[i]];
			xxx[a[i]] = ub;
			
          	assert(__gcd(a[i],a[ub]) == 1);
			if(kaede.same(i,ub) == false){
				kaede.unite(i,ub);
				edge[i].pb(ub);
				edge[ub].pb(i);
			}
		}
	}
	
	//clique
	if(sol.size() >= k-1){
		rep(i,n){
			if(!S[i]) {
				sol.pb(i); break;
			}
		}
		rep(i,k) printf("%d\n",sol[i]+1);
	}
	else{
		rep(i,n) if(edge[i].size() >= 2) goto nxt;
		{
			rep(i,n){
				rep(j,edge[i].size()){
					if(i < edge[i][j]) sol.pb(i);
				}
			}
			rep(i,k) printf("%d\n",sol[i]+1);
			return 0;
		}
		nxt:;
		vector<P>ans;
		rep(i,n){
			id[kaede.find(i)].pb(i);
		}
		int zan = 0;
		rep(i,n){
			if(id[i].size() >= 2){
				ans.pb(mp(i,id[i].size()));
				zan += id[i].size();
			}
		}
		if(k%2 == 0){
			rep(i,ans.size()){
				while(ans[i].sc > 2 && zan > k){
					zan --;
					ans[i].sc --;
				}
			}
			rep(i,ans.size()){
				while(zan > k){
					zan -= 2;
					ans[i].sc = 0;
				}
			}
		}
		else{
			bool B = 0;
			rep(i,ans.size()){
				if(!B && ans[i].sc > 2){
					while(ans[i].sc > 3 && zan > k){
						zan --;
						ans[i].sc --;
					}
					B = 1;
				}
				else{
					while(ans[i].sc > 2 && zan > k){
						zan --;
						ans[i].sc --;
					}
				}
			}
			rep(i,ans.size()){
				if(ans[i].sc > 2) continue;
				while(zan > k){
					zan -= 2;
					ans[i].sc = 0;
				}
			}
		}
		
		vector<int>ret;
		rep(i,ans.size()){
			if(ans[i].sc == 0) continue;
			int NXT = ret.size()+ans[i].sc;
			dfs(ans[i].fi,-1,NXT,ret);
		}
		rep(i,k) printf("%d\n",1+ret[i]);
	}
}