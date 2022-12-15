#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

#define VI vector<int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int
#define PII pair<lint,lint>

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


int init[max_n];
vector<PII> add[max_n];
PII fix[max_n];
vector<pair<PII,int> > mult;

bool cmp(pair<PII,int> p1, pair<PII,int> p2){
	if(p1.st.st*1./p1.st.nd - p2.st.st*1./p2.st.nd >1e-12) return true;
	if(p1.st.st*1./p1.st.nd - p2.st.st*1./p2.st.nd < -1e-12) return false;
	return false;
}


int decode(int k){
	if(k<=-1e6) return -(k+1e6);
	if(k<=0) return -k;
	return k;
}

int main(){
	make3(k,n,m);
	FOR(i,0,k){
		make(a); init[i+1] = a;
	}
	FOR(i,0,k+1) fix[i] = mp(-1,-1);

	FOR(i,1,n+1){
		make3(a,b,c);
		if(a==1){
			if(fix[b].st < c) fix[b] = mp(c,i);
		}
		if(a==2){
			add[b].pb(mp(c,-i));
		}
		if(a==3){
			if(c!=1) mult.pb(mp(mp(c,1),i));
		}
	}
	FOR(i,1,k+1) 
		if(fix[i].st > init[i]) 
			add[i].pb(mp(fix[i].st-init[i],-fix[i].nd-1e6));
		
	FOR(i,1,k+1){
		sort(all(add[i]),greater<PII>());
		lint alfa = init[i];
		FOR(j,0,add[i].size()){
			mult.pb(mp(mp(alfa+add[i][j].st*1LL,alfa),add[i][j].nd));
			alfa += add[i][j].st*1LL;
		}
	}
	sort(all(mult),cmp);
	
	VI res;
	if(mult.size()<m){
		FORE(i,mult) res.pb(i->nd);
	}	
	else{
		FOR(i,0,m) res.pb(mult[i].nd);
	}
	sort(all(res));
	printf("%d\n",res.size());
	FOR(i,0,res.size()){
		printf("%d ",decode(res[i]));
	}
	printf("\n");


}