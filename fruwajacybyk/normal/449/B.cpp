#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define sz(x) ((int)(x).size())

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}

#define max_n 100005




using namespace std;

int n,m,k;
vector<PII> g[max_n];
vector<PII> specjal;
VI trains[max_n];
lint dist[max_n];
bool czy[max_n];
bool mark[max_n];
set<pair<lint,int> > q;

int main(){
	scanf("%d%d%d",&n,&m,&k);
	FOR(i,0,m){
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		g[a].pb(mp(b,c));
		g[b].pb(mp(a,c));
	}
	FOR(i,0,k){
		int a,b; scanf("%d%d",&a,&b);
		specjal.pb(mp(a,b));
		trains[a].pb(b);
	}
	dist[1] = 0;
	FOR(i,2,n+1) dist[i] = 1LL<<62;
	
	FOR(i,1,n+1) q.insert(mp(dist[i],i));

	FOR(i,2,n+1) sort(trains[i].begin(),trains[i].end());
	FOR(i,0,n+1) czy[i] = false;

	int ans = 0;
	FOR(i,2,n+1) ans+= max(sz(trains[i])-1,0);
	FOR(i,1,n+1) mark[i] = 0;

	while(q.size()!=0){
		pair<lint,int> para = *q.begin();
		q.erase(*q.begin());

		int v = para.nd;
		lint d = para.st;
		if(mark[v]==true) continue;
		mark[v] = true;
		if(v==1){
			FOR(i,0,specjal.size()){
				int u = specjal[i].st;
				lint alt = specjal[i].nd;
				if(alt<dist[u]){
					set< pair<lint,int> >::iterator it = q.find(mp(dist[u],u));
					q.erase(*it);
					q.insert(mp(alt,u));
					dist[u] = alt;
					czy[u] = true;
				}
			}
		}
		FOR(i,0,g[v].size()){
			int u = g[v][i].st;
			if(mark[u]) continue;
			lint alt = g[v][i].nd+dist[v];
			if(alt<=dist[u]){
				set< pair<lint,int> >::iterator it = q.find(mp(dist[u],u));
				q.erase(*it);
				q.insert(mp(alt,u));
				dist[u] = alt;
				if(czy[u]==true){
					czy[u] = false;
					ans++;
				}
			}
		}



		
	}
	cout<<ans<<endl;



		
	return 0;
}