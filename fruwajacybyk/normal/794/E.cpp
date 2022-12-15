#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
 
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
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue
 
#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
 
using namespace std;
 
const int max_n = 3e5+5;
int n;
int ans[max_n];
VI v;

int rob(int pos) {
	if (pos +1 < 0 || pos +1 >= n) return -1e9;
	if (pos+2>= n) return v[pos+1];
	return min(max(v[pos], v[pos+2]), v[pos+1]);
}
 
int main() {
	read(n);
	FOR(i,0,n) {
		make(a);
		v.pb(a);
	}
	if (n%2==0) {
		int best = v[0];
		int x = n/2;
		ans[0] = max(v[x], v[x-1]);
		best = ans[0];
		int p1 = x-1, p2 = x;
		for(int k = 2; k < n; k+=2) {
			if (p1-1 >= 0) {
				best = max(best, v[p1-1]);
			} 
			if (p2+1 < n) {
				best = max(best, v[p2+1]);
			}
			p1--; p2++;
			ans[k] = best;
		}
		if (n == 2) ans[1] = max(v[0], v[1]);
		else {
			int x = n/2;
			int p1 = x-2;
			int p2 = x-1;
			ans[1] = max(rob(p1),rob( p2));
			int best = ans[1];
			for (int k = 3; k < n; k+=2) {
				if (k==n-1) break;
				best = max(best, max(rob(p1-1),rob( p2+1)));
				ans[k] = best;
				p1--;
				p2++;
			}
			ans[n-1] = v[0];
			FOR(i,0,n) ans[n-1] = max(ans[n-1], v[i]);
		}
	} else {
		if(n==1) ans[0] = v[0];
		else {
			int p1 = n/2 - 1;
			int p2 = n/2 + 1;
			ans[1] = max(max(v[p1], v[p1+1]), v[p2]);
			int best = ans[1];
			for (int k = 3; k<n; k+=2) {
				if (p1-1 >= 0) {
					best = max(best, v[p1-1]);
				} 
				if (p2+1 < n) {
					best = max(best, v[p2+1]);
				}
				
				ans[k] = best;
				p1--;
				p2++;
			}

			p1 = n/2 - 1;
			p2 = n/2 - 1;
			ans[0] = rob(p1);
			best = ans[0];
			for (int k = 2; k < n; k+=2) {
				best = max(best, max(rob(p1-1), rob(p2 + 1)));
				ans[k] = best;
				p1--;
				p2++;
			}
			ans[n-1] = v[0];
			FOR(i,0,n) ans[n-1] = max(ans[n-1], v[i]);

		}
	}
	FOR(i,0,n) {
		printf("%d ", ans[i]);
	}
	printf("\n");
}