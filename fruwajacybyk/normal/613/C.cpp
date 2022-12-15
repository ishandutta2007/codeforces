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

int n;
int ile[26];

int gcd(int a, int b) {
	return a==0 ? b : gcd(b%a, a);
}

char baza[100005];

int main() {
	read(n);
	int sum = 0;
	int ods = 0;
	FOR(i,0,n) {
		make(a); ile[i] = a;
		sum += a;
		if (a%2==1) ods++;
	}
	if(ods > 1) {
		printf("0\n");
		FOR(i,0,n) {
			FOR(j,0,ile[i]) {
				putchar('a'+i);
			}
		}
			printf("\n");
		return 0;

	}
	int ans = 1;
	
	int d = sum;
	FOR(i,0,n) d = gcd(d, ile[i]);
	
	VI divz; 
	FOR(i,1,d+1) {
		if(d%i==0) divz.pb(i);
	}
	int best = sum;
	int dd = 1;
	FOR(j,0,divz.size()) {
		int d = divz[j];
		int ods = 0;
		FOR(i,0,n) {
			if ( (ile[i]/d)%2==1) ods++;	
		}
		if (ods <= 1) {
			best = sum/d;
			dd = d;
		}
	}
	printf("%d\n", d);
	
	int nxt = 0;
	int lod = -1;
	FOR(i,0,n) {
		if( (ile[i]/dd)%2!=1) {
			FOR(j,0,(ile[i]/dd)/2) baza[nxt++] = 'a'+i;
		} else lod = i; 
	}
	int sz = 0;
	if (lod != -1) {
		int start = nxt;
		FOR(j,0,(ile[lod]/dd)) baza[nxt++] = 'a'+lod;
		FOR(i,0,start) {
			baza[nxt+start-1-i] = baza[i];
		}
		sz = nxt+start;
	}
	else {
		FOR(i,0,nxt) {
			baza[2*nxt-1-i] = baza[i];						
		}
		sz = nxt+nxt;
	}
	FOR(i,0,dd) {
		FOR(j,0,sz) putchar(baza[j]);
	}
	printf("\n");
}