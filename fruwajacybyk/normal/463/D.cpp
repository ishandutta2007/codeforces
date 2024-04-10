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
#define IOS ios_base::sync_with_stdio(0)

#define heap priority_queue

#define max_n 1005


using namespace std;

VI g[max_n];

int pos[max_n][6];
int degree[max_n];
VI sorted;
int used[max_n];

int main(){
	IOS;
	make2(n,k);
	FOR(i,0,k) FOR(j,0,n){
		make(a); 
		pos[a-1][i] = j;
	}

		

	FOR(i,0,n) degree[i] = n+1;
	FOR(i,0,n) FOR(j,0,n){
		if(i==j) continue;
		bool flaga = true;
		FOR(u,0,k) if(pos[i][u]>pos[j][u]) flaga = false;
		if(flaga){
			g[i].pb(j);
			degree[j]--;
		}
	}


	FOR(i,0,n) used[i] = 0;

	heap<PII>  Q;
	FOR(i,0,n) Q.push(mp(degree[i],i));

	
	while(sorted.size()!=n){
		int u = Q.top().nd; Q.pop();
		if(used[u]) continue;
		sorted.pb(u);
		FORE(i,g[u]){
			int v = *i;
			degree[v]++;
			Q.push(mp(degree[v],v));
		}
		used[u] = 1;
	}


	int dp[max_n];
	FOR(i,0,n) dp[i] = 1;
	FORD(i,n-1,0){
		int akt = sorted[i];
		FORE(j,g[akt]) dp[akt] = max(dp[akt],1+dp[*j]);
	}
	int res = 0;
	FOR(i,0,n) res = max(res,dp[i]);
	cout<<res<<endl;




	return 0;
}