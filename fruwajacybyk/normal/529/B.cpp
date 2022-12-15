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

int main(){
	make(n);
	vector<PII> v;
	int h = 0;
	int d = 0;
	FOR(i,0,n){
		make2(a,b); v.pb(mp(a,b));
		d += a;
		h = max(h,b);
	}
	int moge = n/2;
	int best = h * d;
	FOR(i,1,1002){
		VI ulep; 
		int mam = 0;
		int zm = 0;
		bool ok = true;
		FOR(j,0,n){
			if(v[j].st > i && v[j].nd > i){
			 ok = false;
			 break;
			}
			else if(v[j].st > i){
				mam += v[j].st;
			}
			else if(v[j].nd > i){
				zm++;
				mam += v[j].nd;
			}
			else{
				if(v[j].st > v[j].nd){
					ulep.pb(v[j].nd-v[j].st);
				}
				mam += v[j].st;
			}
		}
		if(!ok) continue;
		if( zm > moge) continue;
	  sort(all(ulep));
		FOR(j,zm,moge){
			if(j-zm == ulep.size()) break;
			mam += ulep[j-zm];
		}
	  best = min(best,i*mam);	
	}
	printf("%d\n",best);
}