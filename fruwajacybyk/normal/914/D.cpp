#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

#define PII pair<int,int>
#define mp make_pair
#define st first
#define nd second
#define pb push_back
#define lint long long int
#define VI vector<int>

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

int n,N;
VI rt;
vector<int> A;

int gcd(int a, int b) {
	return (a == 0) ? b : gcd(b%a, a);
}

void init(){
	for(N=1; N<n; N<<=1);
	rt = VI(N<<1);
	FOR(i,0,N) {
		if (i < n) rt[i+N] = A[i];
		else rt[i+N] = 0;
	}
	FORD(i,N-1,1){
		rt[i] = gcd(rt[i<<1],rt[(i<<1)|1]);
	}
}

bool lok;
int gv, gx, gy;

int ask(int v, int x, int y, int l, int r, int xxx){
	if(l > r) return 0;
	if(l == x &&  r == y){
		if (rt[v]%xxx != 0) {
			gv = v; gx = x; gy = y; 
		}
		return rt[v];
	}
	int mid = (x+y)/2;
	int a = ask(2*v,x,mid,l,min(r,mid),xxx);
	int b = ask(2*v+1,mid+1,y,max(l,mid+1),r,xxx);
	if (a%xxx != 0 && b%xxx != 0) lok = false;
	return gcd(a, b);
}

int lask(int x, int y, int xxx) {
	return ask(1, 0, N-1, x, y, xxx);
}
void change(int v, int x){
	rt[v+N] = x;
	for(int j = (v+N)>>1; j ; j>>=1){
		rt[j] = gcd(rt[j<<1],rt[(j<<1)|1]);
	}
}

bool query(int l, int r, int x) {
	if (r==l) {
		return true;
	}
	lok = true;
	int d = lask(l, r, x);
	if (d%x == 0) return true;
	if (!lok) return false;
	int ll = gx; int rr = gy; int mid = (ll+rr)/2; 
	while (1) {
		if (ll == rr) return true;
		if (rt[2*gv]%x !=0 && rt[2*gv+1]%x!=0) return false;
		if (rt[2*gv]%x !=0) {
			gv = 2*gv;
			rr = mid;
			mid = (ll+rr)/2;
		} else {
			gv = 2*gv+1;
			ll = mid + 1;
			mid = (ll + rr)/2;
		}
	}
}

int main() {
	read(n);
	readv(A, n);
	init();
	make(q);
	while (q--) {
		make(type);
		if (type == 1) {
			make3(l, r, x);
			l--; r--;
			if (query(l, r, x)) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		} else {
			make2(a, y);
			a--;
			change(a, y);
		}
	}
}