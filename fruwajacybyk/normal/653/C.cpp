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

int n;
VI v;

bool real_check(int w) {
	if(w<0 || w>=n-1) return true;
	if(w%2==0 && v[w]>=v[w+1]) return false;
	if(w%2==1 && v[w]<=v[w+1]) return false;
	return true;
}

bool check(int i) {
 return (real_check(i) && real_check(i+1) && real_check(i-1));	
}

int main() {
	scanf("%d", &n);
	FOR(i,0,n) {
		make(a); v.pb(a);
	}
	VI zle;
	FOR(i,0,n-1) {
		if (i%2==0 && v[i] >= v[i+1]) zle.pb(i);
		if (i%2==1 && v[i] <= v[i+1]) zle.pb(i);
	}
	if (zle.size() > 6) {
		printf("0\n"); 
		return 0;
	} else {
		int ans = 0;
		int x = zle[0];
		FOR(i,0,n) {
			if(x==i) continue;
			swap(v[x], v[i]);
			bool ok = true;
			FOR(j,0,zle.size()) if(!check(zle[j])) ok = false;
			if(!check(i)) ok = false;
			swap(v[x], v[i]);
			if(ok) ans++;
		}
		x= zle[0]+1;
		FOR(i,0,n) {
			if(x>=n) continue;
			if(x==i || i+1==x) continue;
			swap(v[x], v[i]);
			bool ok = true;
			FOR(j,0,zle.size()) if(!check(zle[j])) ok = false;
			if(!check(i)) ok = false;
			swap(v[x], v[i]);
			if(ok) ans++;
		}
		printf("%d\n", ans);
	}
}