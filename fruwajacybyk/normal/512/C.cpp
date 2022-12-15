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
#define max_n 205

struct flow{
	int n;
	int c[max_n][max_n];
	int f[max_n][max_n];
	flow(int u){
		n = u;
		FOR(i,0,n) FOR(j,0,n) c[i][j] = f[i][j] = 0;
	}
	
	void add_edge(int u,int v, int cap){
		c[u][v]+=cap;
	}

	int compute_flow(int s,int t){
		int res = 0;
		int p[max_n],q[max_n]; 
		while(1){
			FOR(i,0,n) p[i] = -1;
			int b = 0, e = 0;
			q[0] = s; 
			while(b <= e){
				FOR(i,0,n){
					if(f[q[b]][i] < c[q[b]][i] && p[i] < 0){
						q[++e] = i;
						p[i] = q[b];
					}
				}
				b++;
			}
			if(p[t]<0) break;
			int d = c[p[t]][t]-f[p[t]][t];
			for(int i = p[t]; i!=s; i=p[i]) d = min(d, c[p[i]][i]-f[p[i]][i]);
			for(int i = t; i !=s; i=p[i]){
				f[p[i]][i] += d;
				f[i][p[i]] -= d;
			}
			
			res+=d;
		}
		return res;
	}

};


int prime[20005];
VI graf[205];
int col[205];
VI act;
vector<VI> ans;

void dfs(int v){
	act.pb(v);
	col[v] = 1;
	FORE(i,graf[v]){
		if(col[*i]==0) dfs(*i);
	}
}

int main(){
	FOR(i,0,20005) prime[i] = 1;
	FOR(i,2,20002){
		if(prime[i]==1){
			for(int j=2*i; j<20005; j+=i)
				prime[j] = 0;
		}
	}
	make(n);
	makev(v,n);
	flow F(n+2);
	int s = n;
	int t = n+1;
	FOR(i,0,v.size()){
		if(v[i]%2==0)
			F.add_edge(s,i,2);
		else
			F.add_edge(i,t,2);
	}
	FOR(i,0,v.size()){
		FOR(j,0,v.size()){
			if(v[i]%2==0 && v[j]%2==1 && prime[v[i]+v[j]]==1){
				F.add_edge(i,j,1);
			}
		}
	}
	int fl = F.compute_flow(s,t);
	if(fl!=n){
		printf("Impossible\n");
		return 0;
	}
	int cyc = 0;
	FOR(i,0,n){
		FOR(j,0,n){
			if(v[i]%2==0 && v[j]%2==1 && F.f[i][j]==1){
				graf[i].pb(j);
				graf[j].pb(i);
			}
		}
	}
	FOR(i,0,n){
		col[i] = 0;
	}
	FOR(i,0,n){
		act.clear();
		if(col[i]==0){
			dfs(i);
			ans.pb(act);
		}
	}
	printf("%d\n",ans.size());
	FOR(i,0,ans.size()){
		printf("%d ",ans[i].size());
		FOR(j,0,ans[i].size())
			printf("%d ",ans[i][j]+1);
		printf("\n");
	}
}