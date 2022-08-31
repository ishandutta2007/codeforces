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
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll r;
int n;
ll ans[80005];
char str[500005];
vector<P>dep[500005];
map<P,ll>W;

ll rec(int L,int R,int D){
	if(W.find(P(L,R)) != W.end()) return W[mp(L,R)] ;
    if(L == R){
        assert(str[L] == '*');
        return W[mp(L,R)] = 1;
    }
	int a = POSL(dep[D],mp(L,-1));
	int ty = dep[D][a].sc;
	int pre = L-1;
	ll sum = 0, mn = 1e9;
	while(1){
		assert(ty == dep[D][a].sc);
		ll ret = rec(pre+2,dep[D][a].fi-2,D+1);
		if(ty == 0) mn = min(mn,ret);
		else sum += ret;
		
		pre = dep[D][a].fi;
		a ++;
		if(a == dep[D].size() || dep[D][a].fi > R){
			ret = rec(pre+2,R-1,D+1);
			if(ty == 0) mn = min(mn,ret);
			else sum += ret;
			break;
		}
	}
	
	return W[mp(L,R)] = (ty==0?mn:sum);
}
int go;
void make(int L,int R,int D,int x){
    if(L == R){
        ans[go++] = x;
        return;
    }
	int a = POSL(dep[D],mp(L,-1));
	int ty = dep[D][a].sc;
	int pre = L-1;
	if(ty == 0){
		ll mn = 1e9;
		P go = mp(-1,-1);
		while(1){
			assert(ty == dep[D][a].sc);
			ll ret = rec(pre+2,dep[D][a].fi-2,D+1);
			mn = min(mn,ret);
			
			pre = dep[D][a].fi;
			a ++;
			if(a == dep[D].size() || dep[D][a].fi > R){
				ret = rec(pre+2,R-1,D+1);
				mn = min(mn,ret);
				break;
			}
		}
		
		a = POSL(dep[D],mp(L,-1)); pre = L-1;
		while(1){
			assert(ty == dep[D][a].sc);
			ll ret = rec(pre+2,dep[D][a].fi-2,D+1);
			if(mn == ret){ go = mp(pre+2,dep[D][a].fi-2); }
			pre = dep[D][a].fi;
			a ++;
			if(a == dep[D].size() || dep[D][a].fi > R){
				ret = rec(pre+2,R-1,D+1);
				mn = min(mn,ret);
				if(mn == ret){ go = mp(pre+2,R-1); }
				break;
			}
		}
		a = POSL(dep[D],mp(L,-1)); pre = L-1;
		while(1){
			assert(ty == dep[D][a].sc);
			make(pre+2,dep[D][a].fi-2,D+1,(go==mp(pre+2,dep[D][a].fi-2)?x:0));
			pre = dep[D][a].fi;
			a ++;
			if(a == dep[D].size() || dep[D][a].fi > R){
				make(pre+2,R-1,D+1,(go==mp(pre+2,R-1)?x:0));
				break;
			}
		}
	}
	else{
		while(1){
			assert(ty == dep[D][a].sc);
			make(pre+2,dep[D][a].fi-2,D+1,x);
			pre = dep[D][a].fi;
			a ++;
			if(a == dep[D].size() || dep[D][a].fi > R){
				make(pre+2,R-1,D+1,x);
				break;
			}
		}
	}
	return ;
}
void solve(){
    W.clear();
	scanf("%lld ",&r);
	gets(str);
	int k = strlen(str);
	rep(i,k) dep[i].clear();
	int cur_dep = 0;
	rep(i,k){
		if(str[i] == '(') cur_dep++;
		else if(str[i] == ')') cur_dep--;
		else if(str[i] == 'S'){
			dep[cur_dep].pb(mp(i,0));
		}
		else if(str[i] == 'P'){
			dep[cur_dep].pb(mp(i,1));
		}
	}
	ll x = rec(0,k-1,1);
	go = 0;
	make(0,k-1,1,x);
	printf("REVOLTING");
	rep(i,go) printf(" %lld",ans[i] * r);
	puts("");
}
int main(){
	int t; scanf("%d",&t);
	while(t--){
		solve();
	}
}