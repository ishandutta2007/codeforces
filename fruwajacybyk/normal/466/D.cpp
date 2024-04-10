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


#define max_n 2000005


using namespace std;

int mod = 1e9+7;
lint dp[2005][2005];

int main(){
	IOS;
	make2(n,h);
	VI v; FOR(i,0,n){ make(a); v.pb(a);}
	FOR(i,0,2002) dp[n][i] = 0;
	dp[n][0]=1; dp[n][1]=1;
	if(n==1){
		if(v[0]==h || v[0]==h-1) cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}

	FORD(i,n-1,0){
		int u = h-v[i]; if(u<0){ cout<<"0"<<endl; return 0;}
		FOR(j,0,2002) dp[i][j] = 0;

		dp[i][u] = ((u+1)*1LL*dp[i+1][u])%mod;
		if(u>0) dp[i][u-1]=dp[i+1][u];
		dp[i][u+1] = ((u+1)*1LL*dp[i+1][u])%mod; 
		
	}
	if(v[0]==h) cout<<dp[1][0]<<endl;
	else if(v[0]==h-1) cout<<dp[1][1]<<endl;
	else cout<<0<<endl;

	return 0;
}