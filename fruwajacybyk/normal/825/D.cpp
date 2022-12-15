#include <bits/stdc++.h>
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define all(v) (v).begin(),(v).end()
 
#define PII pair<int,int>
#define st first
#define nd second
#define pb push_back
#define lint long long int
#define VI vector<int>

using namespace std;

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream &os, vector<T> V){
  os<<"[";for(auto vv:V)os<<vv<<",";return os<<"]";
} 

template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}


#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)

#define mp make_pair

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

const int max_n = 1e6 + 4;

char s[max_n];
char t[max_n];

int ls[27], lt[27];
int nad = 0;

bool ken(int x) {
	int mynad = nad;
	FOR(i,0,26) {
		mynad += min(ls[i]-x*lt[i], 0);
	}
	if (mynad >= 0) return true;
	return false;
}

int main () {
	scanf("%s", s);
	scanf("%s", t);
	int n = strlen(s);
	int m = strlen(t);
	FOR(i,0,n) {
		if (s[i] != '?') ls[s[i]-'a']++;
		else nad++;
	}
	FOR(i,0,m) {
		lt[t[i]-'a']++;
	}
	int ans = 0;
	while (ken(ans + 1)) {
		ans++;
	}
	int pod[30];
	FOR(j,0,26) {
		ls[j] -= lt[j]*ans;
		if (ls[j] < 0) {
			nad += ls[j];
			pod[j] = -ls[j];
			ls[j] =0;
		} else {
			pod[j] = 0;
		}
	}
	int act = 0;
	FOR(j,0,n) {
		if (s[j]=='?') {
			if (act < 26 && pod[act]!=0) {
				s[j] = 'a' + act;
				pod[act]--;
			} else {
				while (act < 26 && pod[act]==0) act++;
				if (act == 26) {
					s[j] = 'a';
				} else {
					s[j] = 'a' + act;
					pod[act]--;
				}
			}
		}
	}
	printf("%s\n", s);
}