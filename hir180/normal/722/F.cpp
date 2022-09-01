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

vector<P1>pos[100005];
int n,m;
int pr[12]={2,3,5,7,11,13,17,19,23,29,31,37};
struct seg{
	P cur[12][(1<<19)];
	int sz;
	P merge(P a,P b){
		if(a.fi == -1 || b.fi == -1) return mp(-1,-1);
		if(a.fi < b.fi) swap(a,b);
		assert(a.fi%b.fi == 0);
		if(a.sc%b.fi != b.sc) return mp(-1,-1);
		else return a;
	}
	void init(vector<P>vec){
		sz = 1;
		while(sz < vec.size()+5) sz <<= 1;
		rep(x,sz*2) rep(y,12) cur[y][x] = mp(1,0);
		rep(i,vec.size()){
			int x = vec[i].fi;
			int v = vec[i].sc;
			rep(j,12){
				int X = 1;
				while(x%pr[j] == 0){ X*=pr[j]; x/=pr[j]; }
				cur[j][i+sz-1] = mp(X,v%X);
			}
			assert(x == 1);
		}
		rep(j,12) for(int i=sz-2;i>=0;i--) cur[j][i] = merge(cur[j][i*2+1],cur[j][i*2+2]);
	}
	vector<P>query(int a,int b,int k,int l,int r){
		if(r < a || b < l || a > b){
			vector<P>ret; ret.resize(12,P(1,0)); return ret;
		}
		if(a <= l && r <= b){
		    vector<P>ret; ret.resize(12); rep(i,12) ret[i] = cur[i][k]; return ret;
		}
		auto L = query(a,b,k*2+1,l,(l+r)/2);
		auto R = query(a,b,k*2+2,(l+r)/2+1,r);
		vector<P>ret = L;
		rep(i,ret.size()) ret[i] = merge(L[i],R[i]);
		return ret;
	}
	vector<P>query(int a,int b){ return query(a,b,0,0,sz-1); }
}kaede;

int solver(int A,vector<P1>_v){
	if(A >= _v.size()) return _v.size();
	int n = _v.size();
	vector<P>v; rep(i,_v.size()) v.pb(_v[i].sc);
	kaede.init(v);
	int ret = 0;
	int nxt = 0;
	rep(i,n){
		if(n-i <= ret || n-i <= A) break;
		while(nxt < n){
			auto R = kaede.query(i,nxt);
			rep(i,12) if(R[i].fi == -1) goto nxt;
			nxt++;
		}
		nxt:;
		ret = max(ret,nxt-i);
	}
	return ret;
}

int main(){
	cin >> n >> m;
	rep(i,n){
		int a; cin >> a;
		rep(j,a){
			int b; cin >> b;
			pos[b].pb(P1(i,P(a,j)));
		}
	}
	repn(i,m){
		if(pos[i].empty()) {
			puts("0") ; continue;
		}
		vector<P1>vec;
		int ans = 0;
		rep(j,pos[i].size()){
			if(j == 0){
				vec.pb(pos[i][j]);
			}
			else if(vec.back().fi+1 == pos[i][j].fi){
				vec.pb(pos[i][j]);
			}
			else{
				ans = max(ans,solver(ans,vec));
				vec.clear();
				vec.pb(pos[i][j]);
			}
		}
		if(vec.size()) ans = max(ans,solver(ans,vec));
		printf("%d\n",ans);
	}
	return 0;
}