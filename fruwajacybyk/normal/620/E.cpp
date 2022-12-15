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

const int max_n = 4e5+5;

int n, m;
lint color[max_n], color1[max_n];;
VI graf[max_n];

int pocz[max_n];
int kon[max_n];
int tme;

void dfs(int v, int p) {
	FORE(i,graf[v]) {
		int w = *i; if(w==p) continue;
		dfs(w, v);
	}
	pocz[v] = kon[v] = tme;
	FORE(i,graf[v]) {
		if(*i!=p) pocz[v] = min(pocz[v], pocz[*i]);
	}
	tme++;
}

vector<lint> rt;
vector<lint> dupa;
int N;

void init() {
	for(N=1; N<n; N<<=1);
	rt = vector<lint>(N<<1);
	dupa = vector<lint> (N<<1);
	FOR(i,0,n) {
		rt[i+N] = color[i];
	}
	FOR(i,n,N) rt[i+N] = 0;
	FORD(i,N-1,1) rt[i] = (rt[2*i]|rt[2*i+1]);
	FOR(i,0,N) dupa[i] = 0;
}

void postaw(int v, int x, int y, int l, int r, lint kolorek) {
	if(dupa[v]!=0 && v<N) {
		rt[2*v] = dupa[v];
		rt[2*v+1] = dupa[v];
		dupa[2*v] = dupa[v];
		dupa[2*v+1] = dupa[v];
		dupa[v] = 0;
	}
	if(l > r) return ;
	if(l==x && r==y) {
		rt[v] = kolorek;
		if(v<N) dupa[v] = kolorek;
		return ;
	} 
	int mid = (x+y)/2;
  postaw(2*v, x, mid, l, min(r, mid), kolorek);
	postaw(2*v+1, mid+1, y, max(l, mid+1), r, kolorek);	
	rt[v] = (rt[2*v]|rt[2*v+1]);
}

lint wez(int v, int x, int y, int l, int r) {
	if(dupa[v]!=0 && v<N) {
			rt[2*v] = dupa[v];
			rt[2*v+1] = dupa[v];
			dupa[2*v] = dupa[v];
			dupa[2*v+1] = dupa[v];
			dupa[v] = 0;
	}
	if(l > r) return 0;
	if(l==x && r==y) {
		return rt[v];
	}
	int mid = (x+y)/2;
	lint x1 = wez(2*v, x, mid, l, min(r, mid));
	lint x2 = wez(2*v+1, mid+1, y, max(l, mid+1), r);	
	return (x1 | x2);
}


int main() {
	read2(n, m);	
	FOR(i,0,n) {
		make(c); 
		c--;
		color1[i] = (1LL)<<c;
	}
	FOR(i,0,n-1) {
		make2(x,y); x--; y--;
		graf[x].pb(y); graf[y].pb(x);
	}
	tme = 0;
	dfs(0, -1);
	FOR(i,0,n) color[kon[i]] = color1[i];
	init();
	FOR(i,0,m) {
		make(type);
		if(type==1) {
			make2(v,c); v--; c--;
			postaw(1,0,N-1,pocz[v],kon[v],1LL<<c);
		}
		else {
			make(v); v--;		
			lint ans = wez(1,0,N-1,pocz[v],kon[v]);
			int x = __builtin_popcountll(ans);
			printf("%d\n", x);
		}
	}
}