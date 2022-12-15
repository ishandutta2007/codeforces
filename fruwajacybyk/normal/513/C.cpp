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

VI L,R;

double ls(int k, int nr){
	if(k<=L[nr]) return 0.;
	if(k>R[nr]) return 1.;
	int dl = R[nr]-L[nr]+1;
	int ok = k-L[nr];
	return ok*1./dl;
}

double eq(int k, int nr){
	if(k<L[nr] || k > R[nr]) return 0.;
	int dl = R[nr]-L[nr]+1;
	return 1./dl;
}

double gr(int k,int nr){
	if(k<L[nr]) return 1.;
	if(k>=R[nr]) return 0.;
	int dl = R[nr]-L[nr]+1;
	int ok = R[nr]-k;
	return ok*1./dl;
}


int main(){
	make(n); 
	FOR(i,0,n){
		make2(a,b);
		L.pb(a);
		R.pb(b);
	}
	double res = 0.;
	FOR(k,1,10001){
		double p = 0.;
		// X_i > k , X_j = k i j minimalne takie
		FOR(i,0,n){
			FOR(j,0,n){
				if(i!=j){
					double locp = 1.;
					locp *= gr(k,i)*eq(k,j);
					FOR(l,0,j){
						if(l!=i)  locp *= ls(k,l);
					}
					FOR(l,j+1,n){
						if(l!=i) locp *= (ls(k,l)+eq(k,l));
					}
					p += locp;
				}
			}
		}
		// X_i = X_j = k oraz i,j minimalne
		FOR(i,0,n){
			FOR(j,i+1,n){
				double locp = 1.;
				locp *= eq(k,i) * eq(k,j);
				FOR(l,0,j){
					if(l!=i) locp*= ls(k,l);
				}
				FOR(l,j+1,n) locp*= (ls(k,l)+eq(k,l));
				p += locp;
			}
		}

		res += p*k;
	}
	printf("%.17lf\n",res);
}