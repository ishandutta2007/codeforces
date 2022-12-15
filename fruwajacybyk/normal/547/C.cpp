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

#define max_n 1000005


int minp[max_n];
int mu[max_n];

vector<VI> divs;

lint po2(int x){
	return (x*1LL*(x-1))/2LL;
}

int ile[max_n];
int jest[max_n];

int main(){
	FOR(i,0,500001) minp[i] = i;
	FOR(i,2,500005){
		if(minp[i]==i){
			for(int j = 2*i; j<=500001; j+=i) minp[j] = i;
		}
	}
	mu[1] = 1;
	FOR(i,2,500001){
		int p = minp[i];
		if((i/p)%p==0) mu[i] = 0;
		else mu[i] = -mu[i/p];
	}
	
	make2(n,q);
	makev(v,n);
	FOR(i,0,500001) ile[i] = 0;
	int maxi = 0;
	FOR(i,0,n){
		int a = v[i];
		maxi = max(a,maxi);
		VI w;
		for(int j=1; j*j<=a; j++){
			if(a%j==0){
				ile[j]++; w.pb(j);
				if(j!=(a/j)) { ile[a/j]++; w.pb(a/j);}
			}
		}
		divs.pb(w);
	}
	//debug(maxi);
	lint act = 0;
	FOR(i,1,maxi+1){
		//debug2(mu[i],ile[i]);
		act += mu[i]*1LL*po2(ile[i]);
	}
	FOR(i,0,n) jest[i] = 0;
	act = 0;
	FOR(i,0,maxi+1) ile[i] = 0;
//	debug(act);

	while(q--){
		make(x); x--;
		FORE(j,divs[x]){
			int kk = *j;
			if(jest[x]){
				act += mu[kk]*1LL*(po2(ile[kk])-po2(ile[kk]-1));
				ile[kk]--;
			}
			else{
				act += mu[kk]*1LL*(po2(ile[kk])-po2(ile[kk]+1));	
				ile[kk]++;
			}
		}
		jest[x] = 1-jest[x];
		printf("%I64d\n",-act);
	}

	

}