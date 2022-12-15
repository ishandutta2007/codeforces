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

#define max_n 200005


int n;
int L[max_n];
int P[max_n];
int ans[max_n];

int getl(int u){
	return L[u]==u ? u : L[u] = getl(L[u]);
}

int getp(int u){
	return P[u]==u ? u : P[u] = getp(P[u]);
}

int main(){
	read(n);
	FOR(i,0,n) L[i] = -1;
	FOR(i,0,n) P[i] = -1;
	FOR(i,0,n) ans[i] = 0;
	vector<PII> v;
	FOR(i,0,n){
		make(a);
		v.pb(mp(a,i));
	}
	sort(all(v));
	FORD(i,n-1,0){
		int act = v[i].nd;
		if(act>0 && L[act-1] >= 0){
			L[act] = act-1;
			getl(act);
		}
		else L[act] = act;
		if(act<n-1 && P[act+1]>=0){
			P[act] = act+1;
			getp(act);
		}
		else P[act] = act;
		

		if(act+1<n && L[act+1]==act+1){
			L[act+1] = L[act];
		}
		if(act>0 && P[act-1]==act-1){
			P[act-1] = P[act];
		}


		int dl = P[act]-L[act];
		//debug2(dl,v[i].st);
		ans[dl] = max(ans[dl],v[i].st);
	}
	FORD(i,n-2,0) ans[i] = max(ans[i],ans[i+1]);
	FOR(i,0,n){
		printf("%d ",ans[i]);
	}
	printf("\n");
}