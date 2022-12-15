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

char s[5005];

int dp[5005][5005];
int dp2[5005][5005];

int mod = 1e9+7;
int n;

int h1[5005][5005];
int h2[5005][5005];

lint p1 = 1e9+9;
int q1 = 11;
lint p2 = 10000169;
int q2 = 13;

// czy slowo s[i...i+k-1] < s[i+k...i+2k-1]
bool check(int i, int k) {
	if(h1[i][i+k-1]==h1[i+k][i+k+k-1] && h2[i][i+k-1]==h2[i+k][i+k+k-1]) return false;
	if(s[i] < s[i+k]) return true;
	int left = 0, right = k-1;
	while(right - left > 1) {
		int mid = (left+right)/2;
		if(h1[i][i+mid]==h1[i+k][i+k+mid] && h2[i][i+mid]==h2[i+k][i+k+mid]) left = mid;
		else right = mid;
	}
	int roz = left;
	if(h1[i][i+left] == h1[i+k][i+k+left] && h2[i][i+left] == h2[i+k][i+k+left]) roz = right;
	if(s[i+roz] < s[i+k+roz]) return true;
	else return false;
}

int main() {
	read(n);
	scanf("%s", s);
	FOR(i,0,n) FOR(j,i,n) {
		if(i==j) h1[i][j] = s[i]-'0', h2[i][j] = s[i]-'0';
		else {
			h1[i][j] = ((h1[i][j-1]*1LL*q1)%p1 + (s[j]-'0'))%p1;
			h2[i][j] = ((h2[i][j-1]*1LL*q1)%p2 + (s[j]-'0'))%p2;
		}
	}
	FOR(i,0,n+1) FOR(j,0,n+1) dp[i][j] = dp2[i][j] = 0;

	for(int i = n-1; i>=0;i--) {
		for(int j = n-i; j>=1;j--) {
			if(i+j==n) dp[i][j] = 1, dp2[i][j] = 1;
			else {
				dp[i][j] = dp2[i+j][j+1];
				if(i+2*j<=n && check(i,j)) dp[i][j] += dp[i+j][j];
				dp[i][j] %= mod;
				if(s[i+j]=='0') dp[i][j] = 0;
				dp2[i][j] = (dp[i][j] + dp2[i][j+1])%mod;
			}
		}
	}
	printf("%d\n", dp2[0][1]);
}