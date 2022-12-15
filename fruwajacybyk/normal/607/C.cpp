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

const int max_n = 1e6+5;

int n;
char s1[max_n], s2[max_n];
int h1[max_n], h2[max_n];
int h3[max_n], h4[max_n];

int p = 7919;
int mod1 = 1e9+7;

int q = 10000169;
int mod2 = 1e9+9;

int powmod(int a, int b, int mod) {
	if(b==0) return 1;
	int sq = powmod(a,b/2,mod);
	sq = (sq*1LL*sq)%mod;
	if(b%2==0) return sq;
	else return (sq*1LL*a)%mod;
}

int main() {
	read(n);
	scanf("%s",s1);
	scanf("%s",s2);
	n--;
	FOR(i,0,n) {
		if(s2[i]=='E') s2[i] = 'W';
		else if(s2[i]=='S') s2[i] ='N';
		else if(s2[i]=='N') s2[i] ='S';
		else if(s2[i]=='W') s2[i] = 'E';
	}
	
	h1[n-1] = (int) s1[n-1];
	FORD(i,n-2,0) 
		h1[i] = ((h1[i+1]*1LL*p)%mod1+s1[i])%mod1;
	h2[n-1] = (int) s2[n-1];
	FORD(i,n-2,0) h2[i] = ((powmod(p,n-1-i,mod1)*1LL*s2[i])%mod1+h2[i+1])%mod1;

	h3[n-1] = (int) s1[n-1];
	FORD(i,n-2,0) h3[i] = ((h3[i+1]*1LL*q)%mod2+s1[i])%mod2;
	h4[n-1] = (int) s2[n-1];
	FORD(i,n-2,0) h4[i] = ((powmod(q,n-1-i,mod2)*1LL*s2[i])%mod2+h4[i+1])%mod2;
	
	bool ok = true;
	FOR(i,0,n) {
		if(h1[i]==h2[i] && h3[i]==h4[i]) ok = false;
//		debug2(h1[i],h2[i]);
	//	debug2(h3[i],h4[i]);
	}
	if(ok) printf("YES\n");
	else printf("NO\n");

}