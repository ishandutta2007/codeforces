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

lint gcd(lint a, lint b){
	return a==0 ? b : gcd(b%a, a);
}

lint t[105][105];
lint A[105], B[105];
lint bound = 0;


int main(){
	make2(n,m);
	FOR(i,0,n) FOR(j,0,m){
		make(a); t[i][j] = a;
		bound = max(bound,a*1LL+1);
	}
	vector<lint> w;
	FOR(i,0,n) FOR(j2,1,m)
		w.pb(t[i][0]-t[0][0]-t[i][j2]+t[0][j2]);
	FOR(j,0,m) FOR(i2,1,n)
		w.pb(t[0][j]-t[0][0]-t[i2][j]+t[i2][0]);
	sort(all(w));
	lint k = 0;
	FOR(i,0,w.size()){
		if(w[i]==0) continue;
		if(w[i]<0) w[i] = -w[i];
		k = gcd(k,w[i]);
	}
	if(k!=0 && k < bound){
		printf("NO\n"); return 0;
	}
	if(k==0) k = 1e9+7;
	B[0] = 0;
	FOR(i,0,n) A[i] = t[i][0];
	FOR(j,0,m) B[j] = ((t[0][j]-A[0])+k)%k;
	printf("YES\n");
	printf("%I64d\n",k);
	FOR(i,0,n) printf("%I64d ",A[i]); 
	printf("\n");
	FOR(i,0,m) printf("%I64d ",B[i]); 
	printf("\n");
	

}