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
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));

using namespace std;

#define max_n 100005

int v[max_n];
vector<PII> interv;
VI q;
VI events[max_n];

int main(){
	make2(n,m);
	FOR(i,0,n) events[i].clear();
	q.clear(); q.pb(0);
	FOR(i,0,m){
		make3(a,b,c); a--; b--;
		interv.pb(mp(a,b));
		q.pb(c);
		events[a].pb(i+1);
		events[b+1].pb(-(i+1));
	}
	FOR(i,0,n+1) sort(events[i].begin(),events[i].end());
	
	FOR(i,0,n) v[i] = 0;
	
	FOR(k,0,30){
		int akt = 0;
		int mask = 1<<k;
		int mus = 0;
		int dokad = n+5;
		FOR(i,0,n){
			FOR(j,0,events[i].size()){
				int nr = events[i][j];
				int absNr = max(nr,-nr);
				if(q[absNr] & mask){
					if(nr> 0) akt++; 
					if(nr< 0) akt--;
				}
				else{
					mus = 1;
					dokad = min(dokad, interv[absNr-1].nd);
				}
			}

			if(akt>0){
				v[i]+=mask;
				if(mus && dokad==i){
					printf("NO\n");
					return 0;
				}
			}
			else{
				mus = 0;
				dokad = n+5;
			}
		}
	}
	printf("YES\n");
	FOR(i,0,n) printf("%d ",v[i]);
	printf("\n");



}