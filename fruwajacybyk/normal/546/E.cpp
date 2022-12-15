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

#define max_n 224


struct flow{
	struct Edge {
    int v,cap,flow;
    int back_ind;
    Edge *back;
    Edge(int vi, int ci):v(vi),cap(ci){}
	};
	

	int n,s,t;
	int e[max_n],h[max_n];
	vector<Edge> g[max_n];
	vector<Edge>::iterator cur[max_n];
	void bfs(int start, int start_h) {
  	  queue<int> q;
    	h[start] = start_h;
    	for(q.push(start);!q.empty();q.pop()) {
      	  int u = q.front();
        	FORE(i,g[u])
          	  if (i->back->flow < i->back->cap && h[i->v]>h[u]+1) {
            	        h[i->v] = h[u] + 1;
              	      q.push(i->v);
            	}
    	}
	}

	

	int compute_flow() {
    queue<int> q;
    FOR(i,0,n) {
        FORE(j,g[i]) {
            j->flow = 0;
            j->back = &g[j->v][j->back_ind];
        }
        cur[i] = g[i].begin();
        h[i] = e[i] = 0;
    }
    FORE(i,g[s]) {
        i->flow = i->cap;
        i->back->flow = -i->flow;
        if (e[i->v]==0 && i->v!=t) q.push(i->v);
        e[i->v] += i->flow;
    }
    h[s] = n;
    int relabel_counter = 0;
    for(;!q.empty();q.pop()) {
        int u = q.front();
        while (e[u]>0) {
            if (cur[u]==g[u].end()) { // relabel
                relabel_counter++;
                h[u] = 2*n+1;
                FORE(i,g[u]) if(i->flow < i->cap) h[u]=min(h[u],1+h[i->v]);
                cur[u] = g[u].begin(); 
                continue; 
            }
            if (cur[u]->flow < cur[u]->cap && h[u]==h[cur[u]->v]+1) { // push
                int d = min(e[u], cur[u]->cap - cur[u]->flow);
                cur[u]->flow += d;
                cur[u]->back->flow -= d;
                e[u] -= d;
                e[cur[u]->v] += d;
                if (e[cur[u]->v]==d && cur[u]->v!=t && cur[u]->v!=s) q.push(cur[u]->v);
            } else cur[u]++; 
        }
        if (relabel_counter >= n) { 
            FOR(i,0,n) h[i]=2*n+1;
            bfs(t,0);
            bfs(s,n);
            relabel_counter = 0;
        }
    }
    return e[t];
	}
	void add_edge(int a, int b, int c, int c_back=0) {
    	g[a].push_back(Edge(b,c));
    	g[b].push_back(Edge(a,c_back));
    	g[a].back().back_ind = g[b].size()-1;
    	g[b].back().back_ind = g[a].size()-1;
	}
};

int ans[205][205];

int main(){
	make2(n,m);
	makev(c1,n);
	makev(c2,n);
	int s1 = 0, s2 = 0;
	FOR(i,0,n) s1 += c1[i];
	FOR(i,0,n) s2 += c2[i];

	flow F;
	F.n = (n+n+2);
	F.s = 0; F.t = 2*n+1;
	FOR(i,1,n+1){
		F.add_edge(F.s,i,c1[i-1]);
		F.add_edge(i+n,F.t,c2[i-1]);
		F.add_edge(i,i+n,1e6);
	}
	FOR(i,0,m){
		make2(a,b);
		F.add_edge(a,b+n,1e6);
		F.add_edge(b,a+n,1e6);
	}
	if(s1!=s2){
		printf("NO\n");
		return 0;
	}
	else{
		int f = F.compute_flow();
		if(f!=s1) printf("NO\n");
		else{
			printf("YES\n");
			FOR(i,1,n+1) FOR(j,1,n+1) ans[i][j] = 0;
			FOR(i,1,n+1){
				FORE(j,F.g[i]){
					ans[i][(j->v)-n] = j->flow; 
				}
			}
			FOR(i,1,n+1){
				FOR(j,1,n+1) printf("%d ",ans[i][j]);
				printf("\n");
			}	
		}
	}
}