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
#define jeb fflush(stdout)

 
using namespace std;

#define max_n 100005


vector<pair<string, string> > names;
int choose[1005];
VI kasuje[1005];

char sss[10];

int main() {
	make(n);
	FOR(i,0,n) {
		string s1, s2;
		scanf("%s", sss);
		s1 = string(sss);
		scanf("%s", sss);
		s2 = string(sss);
		names.pb(mp(s1.substr(0,3), s1.substr(0,2)+s2.substr(0,1)));
	}
	FOR(i,0,n) choose[i] = -1;
	vector<int> banned;
	FOR(i,0,n) FOR(j,i+1,n) {
		if (names[i].st == names[j].st) {
			choose[i] = choose[j] = 2;
		}
	}
	FOR(i,0,n) {
		FOR(j,0,n) {
			if (i!=j && names[i].nd == names[j].st) {
				kasuje[i].pb(j);
			}
		}
	}
	FOR(i,0,n) if (choose[i] == 2) banned.pb(i);
	int j = 0;
	while (j != banned.size()) {
		int kto = banned[j]; j++;
		FORE(u, kasuje[kto]) {
			int ja = *u;
			if (choose[ja] != 2) {
				choose[ja] = 2;
				banned.pb(ja);
			}
		}
	}

	FOR(i,0,n) FOR(j,i+1,n) {
		string s1, s2;
		if (choose[i] == -1) s1 = names[i].st;
		else s1 = names[i].nd;
		if (choose[j] == -1) s2 = names[j].st;
		else s2 = names[j].nd;
		if (s1 == s2) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	FOR(i,0,n) {
		if (choose[i]==-1) {
			FOR(j,0,3) printf("%c", names[i].st[j]);
			printf("\n");
		}
		else {
			FOR(j,0,3) printf("%c", names[i].nd[j]);
			printf("\n");
		}
	}
}