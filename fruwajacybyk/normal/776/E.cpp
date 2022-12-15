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

#define max_n 1000005


int mod = 1e9 + 7;

int sito[max_n];
lint fi2[max_n];
VI primes;

lint fi(lint n) {
	if (n <= 1e6) return fi2[n];
	lint ans = 1;
	FORE(j, primes) {
		int p = *j;
		if (n%p == 0) {
			ans = ans * 1LL * (p-1);
			n = n/p;
			while (n%p == 0) {
				ans = ans * 1LL * p;
				n = n/p;
			}
		}
		if (n < 1e6) return (ans*1LL*fi2[n]);
	}
	if (n!=1) {
		return (n-1)*1LL*ans;
	} else return ans;
}

int main() {
	FOR(i,0,1e6+1) {
		sito[i] = i;
	}
	FOR(i,2,1e6+1) {
		if (sito[i] == i) {
			for( int j = 2*i; j<=1e6; j+=i) {
				sito[j] = i;
			}
		}
	}
	fi2[1] = 1;
	FOR(i,2,1e6+1) {
		if(sito[i] == i) {
			primes.pb(i);
			fi2[i] = i-1;
		} else {
			int x = i/sito[i];
			int y = sito[i] - 1;
			while (x%sito[i]==0) {
				x=x/sito[i];
				y = y*sito[i];
			}
			fi2[i] = y*fi2[x];
		}
	}

	lint n, k;
	scanf("%lld %lld", &n, &k);
	k = (k+1)/2;
	while (k--) {
		n = fi(n);
		if (n==1) break;
	}
	printf("%lld\n", n%mod);
}