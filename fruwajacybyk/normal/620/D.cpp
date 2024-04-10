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


int main() {
	make(n);
	makev(v, n);
	make(m);
	makev(w, m);
	lint s1 = 0;
	lint s2 = 0;
	FOR(i,0,n) s1 += v[i];
	FOR(i,0,m) s2 += w[i];
	lint diff = s1-s2;
	lint best = max(s1-s2, s2-s1);
	vector<PII> dla;

	FOR(i,0,n) FOR(j,0,m) {
		lint d1 = diff+2LL*(w[j]-v[i]);
		d1 = max(d1, -d1);
		if(d1 < best) {
			best = d1;
			vector<PII> loc;
			loc.pb(mp(i,j));
			dla = loc;
		}
	}
	vector<lint > sum1;
	vector<lint > sum2;
	FOR(i,0,n) FOR(j,i+1,n) sum1.pb(v[i]+v[j]);
	FOR(i,0,m) FOR(j,i+1,m) sum2.pb(w[i]+w[j]);
	sort(all(sum1));
	sort(all(sum2));
	pair<lint, lint> dla2 = mp(1e9*1LL*1e9,0);
	bool zm = false;
	FOR(j,0,sum1.size()) {
		 int pz = lower_bound(all(sum2), sum1[j]-diff/2) - sum2.begin();
		 FOR(pos,pz-1,pz+1) {
		 if(pos>=sum2.size()) continue;
		 if(pos<0) continue;
		 else {
			lint x = diff+2LL*(sum2[pos]-sum1[j]);
			x = max(x, -x);
			if (x < best) {
				best = x;
				dla2 = mp(sum1[j], sum2[pos]);
				zm = true;
			}
		 }
		 }
	}
	if(zm) {
		PII p1, p2;
		FOR(i,0,n) FOR(j,i+1,n) if(v[i]+v[j]==dla2.st) p1 = mp(i,j);
		FOR(i,0,m) FOR(j,i+1,m) if(w[i]+w[j]==dla2.nd) p2 = mp(i,j);
		vector<PII> xxx;
		xxx.pb(mp(p1.st, p2.st));
		xxx.pb(mp(p1.nd, p2.nd));
		dla = xxx;
	}
	printf("%I64d\n", best);
	printf("%d\n", dla.size());
	FOR(i,0,dla.size()) {
		printf("%d %d\n", dla[i].st + 1, dla[i].nd + 1);
	}


}