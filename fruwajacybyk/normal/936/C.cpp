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
int n;
char s[2005];
char t[2005];

bool check() {
	map<char, int> m;
	FOR(i,0,n) m[s[i]]++;
	FOR(i,0,n) m[t[i]]--;
	FORE(j, m) {
		if (j->nd != 0) return false;
	}
	return true;
}

char s2[2005];

void ruch(int k) {
	FOR(i,0,n-k) s2[i+k] = s[i];
	for (int i = n-k, j = k-1; i < n; i++,j--) {
		s2[j] = s[i];
	}
	FOR(i,0,n) s[i] = s2[i];
//	debug(k);
	//debug(s);
}

int znajdz(char C, int l) {
	FOR(j,l+1,n) if (s[j]==C) return j;
	return -1;
}


int main() {
	read(n);
	scanf("%s", s);
	scanf("%s", t);
	if (!check()) {
		printf("-1\n");
		return 0;
	}
	VI ans;
	int lewo = n/2;
	int prawo = n/2;
	if (s[0] != t[lewo]) {
		int pos = znajdz(t[lewo], 0);
		ans.pb(n-1-pos);
		ruch(n-1-pos);
		ans.pb(1);
		ruch(1);
		//cout << "USTAWILEM POCZATEK " << endl;
		//cout << endl;
	}
	while (lewo != 0 || prawo != n-1) {
		int len = prawo - lewo + 1;
		int pos = znajdz(t[lewo-1], len - 1);
		ans.pb(n-pos); ruch(n - pos);
		ans.pb(pos-len); ruch(pos-len);
		lewo--;
		//cout << "DOKLEILEM LEWO " << endl;
		//cout << endl;

		if (prawo != n-1) {
			int pos = 0;
			while (s[pos]!=t[prawo+1]) pos++;
			ans.pb(n-1-pos); ruch(n-1-pos);
			ans.pb(1); ruch(1);
			prawo++;
			len = prawo - lewo + 1;
			ans.pb(n-len); ruch(n-len);
			ans.pb(len); ruch(len);
	//	cout << "DOKLEILEM PRAWO" << endl;
		//cout << endl;
		}
	}
	bool ok = true;
	FOR(i,0,n) if (s[i] != t[i]) ok = false;
	if (!ok) {
		ans.pb(0);
		ruch(0);
	}
	printf("%d\n", ans.size());
	FOR(i,0,ans.size()) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}