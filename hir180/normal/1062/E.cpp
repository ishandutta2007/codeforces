#include <bits/stdc++.h>
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
int n,q;
vector<int>edge[100005];
int num[100005],nxt=0;
int up[100005][21],dep[100005];
int rev[100005];
void dfs(int v,int u){
	rev[nxt+1] = v;
	num[v] = nxt++;
	up[v][0] = u;
	if(u==-1) dep[v]=0; else dep[v]=dep[u]+1;
	rep(i,edge[v].size()){
		int to = edge[v][i];
		dfs(to,v);
	}
}

struct RMQ{
	#define ss (1<<18)
	P seg[ss];
	void update(int k,int a){
		int kk = k;
		k+=ss/2-1; seg[k]=mp(a,kk);
		while(k>0){
			k=(k-1)/2;
			if(seg[k*2+1].fi > seg[k*2+2].fi) seg[k]=seg[k*2+1];
			else seg[k]=seg[k*2+2];
		}
	}
	P query(int a,int b,int k,int l,int r){
		if(r<a || b<l || a>b) return mp(0,-1);
		if(a<=l && r<=b) return seg[k];
		else{
			P vl=query(a,b,k*2+1,l,(l+r)/2);
			P vr=query(a,b,k*2+2,(l+r)/2+1,r);
			if(vl.fi > vr.fi) return vl;
			else return vr;
		}
	}
	
}kaede[2];

int get_lca(int s,int t){
	if(dep[s]>dep[t]) swap(s,t);
	rep(i,19){
		if((((dep[t]-dep[s])>>i)&1)){
			t = up[t][i];
		}
	}
	if(s==t) return s;
	for(int i=19;i>=0;i--){
		if(up[s][i]!=up[t][i]){
			s = up[s][i];
			t = up[t][i];
		}
	}
	return up[s][0];
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++){
		int a; scanf("%d",&a);
		edge[a].pb(i);
	}
	dfs(1,-1);
	for(int i=1;i<=n;i++){
		kaede[0].update(i,num[i]+1);
		kaede[1].update(i,INF-num[i]-1);
	}
	for(int j=0;j<20;j++){
		repn(i,n){
			if(up[i][j] == -1) up[i][j+1] = -1;
			else up[i][j+1] = up[up[i][j]][j];
		}
	}
	rep(i,q){
		int a,b;
		scanf("%d%d",&a,&b);
		P p = kaede[0].query(a,b,0,0,(1<<17)-1);
		P q = kaede[1].query(a,b,0,0,(1<<17)-1);
		//cout << p.fi << " " << p.sc << endl;
		//cout << q.fi << " " << q.sc << endl;
		int mn = INF-q.fi;
		int mx = p.fi;
		
		P ep = kaede[0].query(a,p.sc-1,0,0,(1<<17)-1);
		P eq = kaede[0].query(p.sc+1,b,0,0,(1<<17)-1);
		int mxx = max(ep.fi,eq.fi);
		
		ep = kaede[1].query(a,q.sc-1,0,0,(1<<17)-1);
		eq = kaede[1].query(q.sc+1,b,0,0,(1<<17)-1);
		int mnn = INF-max(ep.fi,eq.fi);
		//mnn-mx or mn-mxx
		int e = get_lca(rev[mnn],rev[mx]);
		int f = get_lca(rev[mn],rev[mxx]);
		if(dep[e] > dep[f]){
			printf("%d %d\n",q.sc,dep[e]);
		}
		else{
			printf("%d %d\n",p.sc,dep[f]);
		}
	}
}