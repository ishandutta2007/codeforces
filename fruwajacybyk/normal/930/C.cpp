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

int n, m;
int t[100005];

int l[100005];
int lid[100005];
int p[100005];
int A[100005];
int X[100005];
int Y[100005];

int lisu(int u) {
	FOR(i,0,m) l[i] = lid[i] = p[i] = 0;

 	int lis = 0, lis_end = 0;
  for (int i = 0; i < m; ++i) {
    int pos = upper_bound(l, l + lis, A[i]) - l;
    l[pos] = A[i];
    lid[pos] = i;
    p[i] = pos ? lid[pos - 1] : -1;
    if (pos + 1 > lis) {
      lis = pos + 1;
      lis_end = i;
    }
		if (u == 0) X[i] = lis;
		else Y[i] = lis;
  }
	return lis;
}

int main() {
	read2(n, m);
	FOR(i,0,n) {
		make2(a, b);
		a--; b--;
		t[a]++;
		t[b+1]--;
	}
	int cur = 0;
	FOR(i,0,m) {
		cur += t[i];
		A[i] = cur;
	}
	lisu(0);
	FOR(i,0,m/2) swap(A[i], A[m-1-i]);
	lisu(1);
	int ans = 0;
	FOR(i,0,m) {
		ans = max(X[i] + Y[m-1-i] - 1, ans);
	}
	printf("%d\n", ans);
}