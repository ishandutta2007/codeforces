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
#define max_n 100005

double dp[5005][5005];
double pom[5005];

vector<PII> songs;

int main(){
	make2(n,T);
	FOR(i,0,n){
		make2(a,b); songs.pb(mp(a,b));
	}
	FOR(i,0,T+1) dp[n][i] = 0.;
	FOR(i,0,n+1) dp[i][0] = 0.;

	FORD(i,n-1,0){
		double p = songs[i].st/100.;
		double q = 1.-p;
		int limit = songs[i].nd;
		if(songs[i].st==100){
			FOR(t,1,T+1)
				dp[i][t] = dp[i+1][t-1]+1.;
		}
		else if(songs[i].st==0){
			FOR(t,1,T+1){
				if(t<limit) dp[i][t] = 0.;
				else dp[i][t] = dp[i+1][t-limit]+1.;	
			}
		}
		else{
			int l = limit;
			double mam = 0.;
			FOR(t,1,limit){
					mam *= q; 
					mam += p*(dp[i+1][t-1]+1.);
					dp[i][t] = mam;
			}
			FOR(t,limit,T+1){
				mam *= q;
				mam += p*(dp[i+1][t-1]+1.);
				mam -= p*pow(q,l-1)*(dp[i+1][t-limit]+1.);
				dp[i][t] = mam+pow(q,l-1)*(1.+dp[i+1][t-limit]);
			}
		}

	}
	printf("%.17lf\n",dp[0][T]);

	return 0;
}