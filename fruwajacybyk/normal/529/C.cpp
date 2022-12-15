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

#define max_n 400005

int ans[max_n];
pair<PII,PII> rects[max_n];

int n,N;
VI rt;

void init(){
	for(N=1; N<n; N<<=1);
	rt = VI(N<<1);
	FOR(i,0,N) rt[i+N] = -1;//init
	FORD(i,N-1,1){
		rt[i] = min(rt[i<<1],rt[(i<<1)|1]);
	}
}

// w przedziale x,y reprezentowanym przez v
// szukaj przedziau l,r 
int rob(int v, int x, int y, int l, int r){
	if(l > r) return 1e6 ;
	if( l == x &&  r == y){
		return rt[v];
	}
	int mid = (x+y)/2;
	int u1 = rob(2*v,x,mid,l,min(r,mid));
	int u2 = rob(2*v+1,mid+1,y,max(l,mid+1),r);
	return min(u1,u2);
}

void change(int v, int x){
	rt[v+N] = x;
	for(int j = (v+N)>>1; j ; j>>=1){
		rt[j] = min(rt[j<<1],rt[(j<<1)|1]);
	}
}

vector<PII> v;


int main(){
	make2(n1,m1); make2(k,q);
	n = max(n1+5,m1+5);
	FOR(i,0,k){
		make2(a,b); v.pb(mp(a,b));
	}
	FOR(i,0,q) ans[i] = 2;
	FOR(i,0,q){
		make4(a,b,c,d); rects[i] = mp(mp(a,b),mp(c,d));
	}
	
	FOR(UU,0,2){
		init();
		vector<PII> events;
		FOR(i,0,k) events.pb(mp(v[i].st,-i));
		FOR(i,0,q){
			events.pb(mp(rects[i].nd.st,i+1));
		}
		sort(all(events));
		FOR(i,0,events.size()){
			//debug2(events[i].st,events[i].nd);
			if(events[i].nd <= 0){
				int nr = -events[i].nd;
				change(v[nr].nd,v[nr].st);
			}
			else{
				int nr = events[i].nd-1;
				int alfa = rob(1,0,N-1,rects[nr].st.nd,rects[nr].nd.nd) ;
				//debug(alfa);
				if( alfa < rects[nr].st.st ) ans[nr]--;
			}
		}
		FOR(i,0,k) v[i] = mp(v[i].nd,v[i].st);
		FOR(i,0,q) rects[i] = mp(mp(rects[i].st.nd,rects[i].st.st),mp(rects[i].nd.nd,rects[i].nd.st));
	}
	FOR(i,0,q){
		if(ans[i]) printf("YES\n");
		else printf("NO\n");
	}

}