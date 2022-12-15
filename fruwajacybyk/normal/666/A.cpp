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
#define REP(i,n) FOR(i,0,(n))
 
using namespace std;

const int max_n = 1e5;
char s[max_n];
int dasie2[max_n];
int dasie3[max_n];

int main() {
	IOS;
	scanf("%s", s);
	int n = strlen(s);
	set<string> ans;
	FOR(i,0,n+1) dasie2[i] = dasie3[i] = 0;
	dasie2[n-2] = 1;
	dasie3[n-3] = 1;
	FORD(i,n-3,0) {
		if (dasie2[i+2]==1 && (s[i]!=s[i+2] || s[i+1]!=s[i+3])) dasie2[i] = 1;
		if (dasie3[i+2]==1) dasie2[i] = 1;
		if (dasie3[i+3]==1 && (s[i]!=s[i+3] || s[i+1]!=s[i+4] || s[i+2]!=s[i+5])) dasie3[i] = 1;
		if (dasie2[i+3]==1) dasie3[i] = 1;
	}
	FOR(i,5,n) {
		if (dasie2[i]) {
			string u = "";
			u += s[i];
			u += s[i+1];
			ans.insert(u);
		} 
		if (dasie3[i]) {
			string u ="";
			u += s[i];
			u += s[i+1];
			u += s[i+2];
			ans.insert(u);
		}
	}
	cout << ans.size() << endl;
	FORE(i, ans) {
		cout << *i << endl;
	}
}