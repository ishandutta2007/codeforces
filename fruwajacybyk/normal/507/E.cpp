#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define makev(v,n) VI (v); FOR(i,0,(n)) { make(a); (v).pb(a);} 
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define readv(v,n) FOR(i,0,(n)) { make(a); (v).pb(a);}

using namespace std;
#define max_n 100005

int n,m;
int stan[max_n];
vector<PII> g[max_n];
int dist[max_n], bad[max_n], prev[max_n],prev2[max_n];
int nadrodze[max_n];
vector<PII> kraw;

int main(){
	read2(n,m);
	FOR(i,0,m){
		make3(a,b,z);
		a--,b--; 
		stan[i] = 1-z;
		g[a].pb(mp(b,i));
		g[b].pb(mp(a,i));
		kraw.pb(mp(a,b));
	}
	FOR(i,0,n) dist[i] = 1e9, bad[i] = 0;
	dist[0] = bad[0] = 0;
	VI v; v.pb(0);
	while(1){
		VI w; 
		FOR(i,0,v.size()){
			int act = v[i];
			FORE(j,g[act]){
				if(dist[j->st]>dist[act]+1){
					dist[j->st] = dist[act]+1;
					prev[j->st] = act;
					prev2[j->st] = j->nd;
					bad[j->st] = bad[act]+stan[j->nd];
					w.pb(j->st);
				}
				if(dist[j->st]==dist[act]+1){
					if(bad[j->st] > bad[act]+stan[j->nd]){
						prev[j->st] = act;
						prev2[j->st] = j->nd;
						bad[j->st] = bad[act]+stan[j->nd];
					}
				}
			}
		}
		v = w;
		if(w.size()==0) break;
	}
	FOR(i,0,m) nadrodze[i] = 0;
	int x = n-1;
	while(x!=0){
		nadrodze[prev2[x]] = 1;
		x = prev[x];	
	}
	int ans = 0;
	FOR(i,0,m){
		if(nadrodze[i]==1 && stan[i]==1) ans++;
		if(nadrodze[i]==0 && stan[i]==0) ans++;
	}
	printf("%d\n",ans);
	FOR(i,0,m){
		if(nadrodze[i]==1 && stan[i]==1){
			printf("%d %d 1\n",kraw[i].st+1,kraw[i].nd+1);
		}
		if(nadrodze[i]==0 && stan[i]==0){
			printf("%d %d 0\n",kraw[i].st+1,kraw[i].nd+1);
		}
	}

}