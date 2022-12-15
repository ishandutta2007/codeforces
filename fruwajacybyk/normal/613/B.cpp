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

vector<PII> v;

const int max_n = 1e5+5;

int n, A;

lint pref[max_n];
lint suf[max_n];

bool moge(int war, lint zost, int brzeg) {
	int left = 0, right = brzeg;
	while (right - left > 1) {
		int mid = (right + left)/2;
		if (v[mid].st> war) right = mid;
		else left = mid;
	}
	int ans = left;
	if(v[right].st <=war) ans = right;
	if((ans+1)*1LL*war - pref[ans] <= zost) return true;
	else return false;
}

int answ[max_n];

int main() {
	read2(n,A);
	make2(c1,c2);
	lint m; scanf("%I64d",&m);
	FOR(i,0,n) {
		make(a); v.pb(mp(a,i));
	}
	sort(all(v));
	pref[0] = v[0].st;
	FOR(i,1,n) pref[i] = pref[i-1]+v[i].st;
	suf[n-1] = v[n-1].st;
	FORD(i,n-2,0) suf[i] = suf[i+1]+v[i].st;
	
	lint best = 0;
	int dla1 = -1;
	int dla2 = -2;
	FOR(i,0,n+1) {
		lint wyd = i*1LL*A-(i==0 ? 0 : suf[n-i]); 
		if (wyd > m) break;
		int brzeg = n-i-1;
		lint zost = m-wyd;
		int left = 0, right = A;
		while (right - left > 1) {
			int mid = (right+left)/2;
			if( moge(mid, zost, brzeg)) left = mid;
			else right = mid;
		}
		int ans = left;
		if(moge(right, zost, brzeg)) ans = right;
		lint loc = c1*1LL*i + c2*1LL*ans;
		if (loc > best) {
			best = loc;
			dla1 = i;
			dla2 = ans;
		}
	}
	if (n*1LL*A-pref[n-1] <= m) {
		best = (c1*1LL*n + c2*1LL*A);
		dla1 = 0;
		dla2 = A;
	}

	printf("%I64d\n", best);

	FOR(j,0,dla1) v[n-1-j].st = A;
	FOR(j,0,n) if(v[j].st < dla2) v[j].st = dla2;
	FOR(j,0,n) answ[v[j].nd] = v[j].st;
	FOR(j,0,n) printf("%d ",answ[j]);
	printf("\n");
	
}