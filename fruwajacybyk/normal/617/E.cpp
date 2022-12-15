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

int n, k;

const int max_n = 1e5+5;

int table[max_n];

vector< pair<PII, int> > queries;
lint ANS[max_n];

int CHK = 450;

bool cmp(const pair<PII, int>& p1, const pair<PII, int>& p2) {
	return (p1.st.st/CHK < p2.st.st/CHK) || (p1.st.st/CHK == p2.st.st/CHK && p1.st.nd < p2.st.nd);
}

lint loc;
int mapka[2000005];

void dodaj(int i) {		
		int x = table[i];
		loc += mapka[x^k];
		mapka[x]++;
}

void zabierz(int i) {
	int x = table[i];
		if (k != 0) loc -= mapka[x^k];
		else loc -= (mapka[x^k]-1);
		mapka[x]--;
}

int main() {
	read(n);
	make(m);
	read(k);
	table[0] = 0;
	FOR(i,0,n) {
		make(a); table[i+1] = a;
	}
	FOR(i,1,n+1) table[i] = table[i]^table[i-1];
	FOR(i,0,2e6) mapka[i] = 0;
	FOR(i,0,m) {
		make2(a,b);
		a--;
		queries.pb(mp(mp(a,b),i));
	}
	sort(all(queries), cmp);
	FOR(i,queries[0].st.st, queries[0].st.nd+1) {
		lint loc = 0;
		dodaj(i);
	}
	int left = queries[0].st.st, right = queries[0].st.nd;
	ANS[queries[0].nd] = loc;
	FOR(i,1,queries.size()) {
		int nleft = queries[i].st.st, nright = queries[i].st.nd;
		while (left  > nleft) {
			left--;
			dodaj(left);
		}
		while (right < nright) {
			right++;
			dodaj(right);
		}
		while (left < nleft) {
			zabierz(left);
			left++;
		}
		while (right > nright) {
			zabierz(right);
			right--;
		}
		ANS[queries[i].nd] = loc;
	}
	FOR(i,0,m) {
		printf("%I64d\n", ANS[i]);
	}

}