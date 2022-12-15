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
#define sz(x) ((int)(x).size())
#define all(x) x.begn(),x.end()

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
#define IOS ios_base::sync_with_stdio(0);


#define max_n 200005


using namespace std;

VI primes;

int n;
int dp[105][ (1<<16) + 10];
int dla[105][(1<<16) + 10];
int wstecz[105][(1<<16)+10];

int divs[65];
VI dobre[65];

VI a;

int abs(int x){
	return max(x,-x);
}



int main(){
	FOR(i,2,55){
		bool flaga = true;
		FOR(j,2,i-1)
			if(i%j==0) flaga = false;
		if(flaga) primes.pb(i);
	}

	FOR(i,1,55) FOR(j,0,primes.size()){
		if(i%primes[j]==0) divs[i]+=(1<<j);
	}

	a.clear();
	scanf("%d",&n);
	FOR(i,0,n){
		make(x); a.pb(x);
	}
	FOR(i,0,n) FOR(j,0,1<<16) dp[i][j] = 1e7;
	FOR(j,1,55){
		if(dp[0][divs[j]] > abs(a[0]-j)){
			dp[0][divs[j]] = abs(a[0]-j);
			dla[0][divs[j]] = j;
		}
	}

	FOR(j,1,55) FOR(k,0,1<<16) if((divs[j]&k) == 0) dobre[j].pb(k);

	FOR(i,1,n){
		FOR(j,1,55){
			FORE(u,dobre[j]){
				int k = *u;
				if(dp[i][k + divs[j]] > dp[i-1][k] + abs(a[i]-j)){
					dp[i][k+divs[j]] = dp[i-1][k]+abs(a[i]-j);
					dla[i][k+divs[j]] = j;
					wstecz[i][k+divs[j]] = k;
				}
			}
		}
	}

	VI ans; 
	int start;
	int mini = 1e9;
		FOR(j,0,1<<16){
			if(dp[n-1][j]<mini){
				mini = dp[n-1][j];
				start = j;
			}
		}
	ans.pb(dla[n-1][start]);
	FORD(i,n-2,0){
		start = wstecz[i+1][start];
		ans.pb(dla[i][start]);
	}
	FORD(i,n-1,0){
		printf("%d ",ans[i]);
	}
	printf("\n");
	
	

	
				

	return 0;
}