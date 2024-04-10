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
#define max_n 5005

VI skad;
VI co;

int jest[105][105];

VI primes;

struct matching{
	int n1,n2;          
	vector<int> g[max_n];   
	VI lewo;
	int m1[max_n], m2[max_n];   
	bool c[max_n];

	bool dfs(int u) {
    if (u<0) return true;
    if (c[u]) return false; else c[u]=true;
    FORE(v, g[u]) 
        if (dfs(m2[*v])) { m1[u] = *v; m2[*v] = u; return true; }
    return false;
	}

	int matchin() {
    FOR(i,0,n1+n2) m1[i]=-1;
    FOR(i,0,n2+n1) m2[i]=-1;
    bool changed;
    do {
        changed = 0;
        FOR(i,0,n1) c[lewo[i]]=false;
        FOR(i,0,n1) if (m1[lewo[i]]<0) changed |= dfs(lewo[i]);
    } while(changed);
    int siz = 0;
    FOR(i,0,n1) siz += (m1[lewo[i]]!=-1);
    return siz;
	}
};

int main(){
	primes.pb(2);
	for(int i=3; i*i<1e9;i+=2){
		bool pr = true;
		FORE(j,primes){
			if(i%(*j)==0){
				pr=false; break;
			}
			if((*j)*(*j)>i) break;
		}
		if(pr) primes.pb(i);
	}

	make2(n,m);
	FOR(i,0,n){
		make(a);
		FOR(j,0,primes.size()){
			while(a%primes[j]==0){
				skad.pb(i);
				co.pb(primes[j]);
				a = a/primes[j];
			}
		}
			if(a!=1){
				skad.pb(i);
				co.pb(a);
			}
	}

	FOR(i,0,n) FOR(j,0,n) jest[i][j] = 0;
	FOR(i,0,m){
		make2(a,b);
		a--; b--; 
		jest[a][b] = jest[b][a] = 1;
	}
	matching match;
	match.n1 = 0;
	match.n2 = 0;
	FOR(i,0,skad.size()){
		if(skad[i]%2==0){
			match.n1++;
			match.lewo.pb(i);
		}
		else match.n2++;
	}
	
	

	FOR(i,0,skad.size()){
		FOR(j,i+1,skad.size()){
			if(jest[skad[i]][skad[j]] && co[i]==co[j]){
				match.g[i].pb(j);
				match.g[j].pb(i);
			}
		}
	}
	
	printf("%d\n", match.matchin());


	return 0;
}