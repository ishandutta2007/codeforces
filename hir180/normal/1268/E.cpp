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

#define at(i,x) for(auto i:x)
#define pot(x) cout << x.fi << " " << x.sc << endl
int n,m;
vector<int>G[500005];
vector<int>edge[500005];
int up[500005],dep[500005];
bool used[500005];
int cnt[500005];
vector<P>ctr;
void dfs(int v,int u){
	up[v] = u; used[v] = 1;
	if(u == -1) dep[v] = 0; else dep[v] = dep[u]+1;
	rep(i,G[v].size()){
		if(G[v][i] == u) continue;
		if(used[G[v][i]]){
			if(dep[v] < dep[G[v][i]]){
				cnt[G[v][i]]++; cnt[v]--;
				ctr.pb(P(G[v][i],v));
			}
		}
		else{
			dfs(G[v][i],v);
			edge[v].pb(G[v][i]);
		}
	}
}
void dfs2(int v,int u){
	rep(i,edge[v].size()){
		dfs2(edge[v][i],v);
		cnt[v] += cnt[edge[v][i]];
	}
	if(cnt[v] == 0 && u != -1){
		ctr.pb(P(v,u));
	}
}
vector<vector<int>>cyc;
vector<vector<int>>num;
int sum[500005];
vector<vector<int>>gen;
vector<vector<int>>bad[2];
map<P,int>M;
vector<P>belong[500005];

vector<P>vec;
int in[500005];
int sm[500005];

struct seg{
	vector<int>bit;
	int sz ;
	void init(int nn){
		sz = 1;
		while(sz < nn+3) sz <<= 1;
		bit.resize(sz,0);
	}
	void update(int i,int x)
	{
	    i++;
		for(int s=i;s<sz;s+=s&-s) bit[s]+=x;
	}
	int query(int a,int b){ return sum(b+1)-sum(a); }
	int sum(int i){
	    int ret = 0;
	    for(int s=i;s>0;s-=s&-s) ret+=bit[s];
	    return ret;
	}
}kaede[2][500005];

int evaluate(int dir,int cyc_num,int pos){
	int sz = cyc[cyc_num].size();
	assert(0 <= pos && pos < sz);
	if(dir == 0){
		int a = POSL(bad[0][cyc_num],pos+1);
		int en = pos+sz-1;
		if(a < bad[0][cyc_num].size()) en = min(en,bad[0][cyc_num][a]);
		int ret = en-pos;
		ret += kaede[0][cyc_num].query(pos,en-1);
		return ret;
	}
	else if(dir == 1){
		int R = pos+sz; int en = pos+1;
		int a = POSL(bad[1][cyc_num],R);
		if(a > 0) en = max(en,bad[1][cyc_num][a-1]);
		int ret = R-en;
		ret += kaede[1][cyc_num].query(en,R-1);
		return ret;
	}
	else{
		int a = POSL(bad[0][cyc_num],pos+1);
		int en = pos+sz-1;
		if(a < bad[0][cyc_num].size()) en = min(en,bad[0][cyc_num][a]);
		//[pos,en]
		
		int R = pos+sz;
		int enn = pos+1;
		a = POSL(bad[1][cyc_num],R);
		if(a > 0) enn = max(enn,bad[1][cyc_num][a-1]);
		//[enn,pos+sz]
		
		if(en < enn){
			int ret = en-pos;
			ret += kaede[0][cyc_num].query(pos,en-1);
			ret += R-enn;
			ret += kaede[1][cyc_num].query(enn,R-1);
			return ret;
		}
		else{
			int ret = sz-1;
			ret += kaede[0][cyc_num].query(pos,en-1);
			ret += kaede[1][cyc_num].query(enn,R-1);
			for(int i=enn;i<=en;i++){
				ret -= min(kaede[0][cyc_num].query(i-1,i-1),kaede[1][cyc_num].query(i,i));
			}
			return ret;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,m){
		int a,b; scanf("%d%d",&a,&b);
		G[a].pb(b); G[b].pb(a);
		if(a > b) swap(a,b);
		M[mp(a,b)] = i;
		vec.pb(mp(a,b));
	}
	dfs(1,-1);
	dfs2(1,-1);
	at(i,ctr){
		int x = i.fi, y = i.sc;
		vector<int>vi;
		while(1){
			vi.pb(x);
			if(x == y) break;
			x = up[x];
		}
		cyc.pb(vi);
	}
	rep(i,cyc.size()) rep(j,cyc[i].size()) belong[cyc[i][j]].pb(mp(i,j));

	rep(i,cyc.size()){
		vector<int>vec;
		vec.resize(cyc[i].size(),0);
		gen.pb(vec);
		vector<int>len;
		len.resize(cyc[i].size()*2,0);
		rep(j,cyc[i].size()*2){
			int a = cyc[i][j%cyc[i].size()];
			int b = cyc[i][(j+1)%cyc[i].size()];
			if(a > b) swap(a,b);
			len[j] = M[mp(a,b)];
			in[len[j]] = i;
			sm[len[j]] = j%cyc[i].size();
		}
		num.pb(len);
		vector<int>vv;
		rep(i,len.size()-1){
			if(len[i] > len[i+1]) vv.pb(i+1);
		}
		bad[0].pb(vv);
		vv.clear();
		rep(i,len.size()-1){
			if(len[i+1] > len[i]) vv.pb(i+1);
		}
		bad[1].pb(vv);
		rep(p,2) kaede[p][i].init(num[i].size());
	}
	//code from here
	reverse(vec.begin(),vec.end());

	rep(i,vec.size()){
	    int a = vec[i].fi, b = vec[i].sc; 
	    int cyc_num = in[m-1-i];
	    int sz = cyc[cyc_num].size();
	    int id1 = sm[m-1-i];
	    int id2 = (id1+1)%sz;
		int dp;
	    dp = sum[cyc[cyc_num][id2]]-gen[cyc_num][id2];
	    kaede[0][cyc_num].update(id1,dp);
	    kaede[0][cyc_num].update(id1+sz,dp);
	    int nxt;
	    if(num[cyc_num][id1] >= num[cyc_num][(id1+sz-1)%sz]){
	    	nxt = evaluate(0,cyc_num,id1);
	    }
	    else{
	    	nxt = evaluate(-1,cyc_num,id1) - evaluate(1,cyc_num,id1);
	    }
	    sum[cyc[cyc_num][id1]] += nxt;
	    gen[cyc_num][id1] += nxt;

	    dp = sum[cyc[cyc_num][id1]]-gen[cyc_num][id1];
	    kaede[1][cyc_num].update(id1,dp);
	    kaede[1][cyc_num].update(id1+sz,dp);
	    if(num[cyc_num][id1] >= num[cyc_num][id2]){
	    	nxt = evaluate(1,cyc_num,id2);
	    }
	    else{
	    	nxt = evaluate(-1,cyc_num,id2) - evaluate(0,cyc_num,id2);
	    }
	    sum[cyc[cyc_num][id2]] += nxt;
	    gen[cyc_num][id2] += nxt;
	    
	}
	repn(i,n){
		int ans = 0;
		rep(j,belong[i].size()){
			int cycid = belong[i][j].fi, id = belong[i][j].sc;
			ans += evaluate(-1,cycid,id);
		}
		printf("%d\n",ans);
	}
}