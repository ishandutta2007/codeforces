#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef unsigned long long ll;
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
typedef pair<ll,ll> Q;
typedef pair<Q,ll> R;

struct ha_sh{
	#define mod_num 1
	//SZ
	#define SZ 100005
	
	ll M[10] = {1000000007,1000000009};
	ll c[10] = {37, 41};
	ll val[mod_num][SZ], hs[mod_num][SZ];
	
	void init(string s){
		rep(i,mod_num) val[i][0] = 1;
		rep(j,SZ-1){
			rep(i,mod_num) val[i][j+1] = val[i][j] * c[i] ;
		}
		rep(i,s.size()){
			rep(j,mod_num){
				hs[j][i+1] = hs[j][i] + val[j][i+1] * (s[i]-'a'+1);
			}
		}
	}
	ll get_val(int l,int r){
		ll num = 0;
		ll coef = 1;
		rep(i,mod_num){
			ll add = (hs[i][r+1] - hs[i][l]) * val[i][SZ-1-l] ;//% M[i];
			num += coef * add;
			coef *= M[i];
		}
		return num;
	}
	ll get_val_str(string s){
		ll H[mod_num] = {};
		rep(i,s.size()){
			rep(j,mod_num){
				H[j] += val[j][i+1] * (s[i]-'a'+1);
			//	H[j] %= M[j];
			}
		}
		ll num = 0;
		ll coef = 1;
		rep(i,mod_num){
			ll add = H[i] * val[i][SZ-1] ;//% M[i];
			num += coef * add;
			coef *= M[i];
		}
		return num;
	}
}kaede;

string s;
int n,q;
vector<int>sz;
vector<int>pos[100005];
vector<pair<ll,P>>query[100005];
int cnt[100005], len[100005];

//all m_i are distinct 99%
int main(){
	cin >> s >> q;
	n = s.size();
	kaede.init(s);
	
	rep(i,q){
		int t; string ss; cin >> t >> ss;
		ll H = kaede.get_val_str(ss);
		query[ss.size()].pb(mp(H,mp(t,i))); 
		sz.pb(ss.size());
		cnt[i] = t;
		len[i] = ss.size();
	}
	
	SORT(sz); ERASE(sz);
	
	//i|query[i]| = cnt_i
	//n * sum {log (cnt_i)} sub. sum {i * cnt_i} <= 10^5
	// O(N sqrt log) 
	
	rep(i,sz.size()){
		int x = sz[i]; 
		SORT(query[x]);
		rep(j,n){
			if(j+x-1 < n){
				ll h = kaede.get_val(j,j+x-1);
				int r = POSL(query[x],mp(h,mp(-1,-1)));
				if(r < query[x].size() && query[x][r].fi == h) pos[query[x][r].sc.sc].pb(j);
			}
		}
	}
	
	rep(i,q){
		if(pos[i].size() >= cnt[i]){
			int szz = pos[i].size(), ans = INF;
			rep(j,szz){
				if(j+cnt[i]-1 >= szz) break;
				ans = min(ans, pos[i][j+cnt[i]-1] - pos[i][j] + len[i]);
			}
			printf("%d\n",ans);
		}
		else puts("-1");
	}
	return 0;
}