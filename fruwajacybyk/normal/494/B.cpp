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
#define max_n 200005

char s[max_n],t[max_n];
int p[max_n];
int good[max_n];
int f[max_n];
int dp[max_n];
int sum[max_n];

int mod = 1e9+7;

int main(){
	scanf("%s",s);
	scanf("%s",t);
	int n = strlen(s);
	int m = strlen(t);
	FORD(i,m,1) t[i] = t[i-1];
	t[m+1] = '#';
	FOR(i,m+2,m+n+2) t[i] = s[i-(m+2)];
	
	p[0] = -1;
	int j = -1;
	FOR(i,1,n+m+2){
		while(j>=0 && t[j+1]!=t[i]) j = p[j];
		j++; p[i] = j;
	}


	FOR(i,1,n+1) 
		if(p[i+(m+1)]==m) good[i+1-m] = 1;
		else good[i] = 0;


	f[n+1] = n+2;
	FORD(i,n,1){
		if(good[i]) f[i] = min(n+1,i+m);
		else f[i] = f[i+1];
	}

	dp[n+2] = 0;
	sum[n+2] = 0;
	dp[n+1] = 1;
	sum[n+1] = 1;

	FORD(i,n,1){
		dp[i] = (dp[i+1]+sum[f[i]])%mod;
		sum[i]=(sum[i+1]+dp[i])%mod;
	}

	printf("%d\n",(dp[1]+mod-1)%mod);
	

	return 0;
}