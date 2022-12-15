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


#define max_n 1000005


using namespace std;

int pre[2005];
int dp[2005][2005];
string s,p;

int main(){
	IOS;
	cin>>s>>p;
	int n,k;
	n = s.length();
	k = p.length();
	if(k>n){
		FOR(i,0,n+1) printf("0 ");
		printf("\n");
		return 0;
	}
	FORD(i,n-1,0){
		if(s[i]==p[0]){
			pre[i] = -1;
			int j = 0;
			int usuwam = 0;
			int akt = i;
			while(akt<n){
				if(p[j]==s[akt]){
					j++; akt++;
					if(j==k){
						pre[i] = usuwam;
						break;
					}
				}
				else{
					usuwam++;
					akt++;
				}
			}
		}
		else{
			if(pre[i+1]==-1 || i==n-1)
				pre[i] = -1;
			else pre[i] = pre[i+1]+1;
		}
	}

	FOR(i,0,n+1) FOR(j,0,n+1){
		if(j>n-i) dp[j][i] = -1e9; 
		else dp[j][i] = 0;
	}
	
	dp[n][0] = 0;
	FORD(i,n-1,0){
		if(pre[i]==0) dp[i][0] = dp[i+k][0]+1;
		else dp[i][0] = dp[i+1][0];
	}
	

	FORD(j,n-1,0){
		FOR(i,1,n-j+1){
			dp[j][i] = max(dp[j+1][i], (j>0 ?  dp[j+1][i-1] : 0) );
			if(pre[j]!=-1){
				if(i>= pre[j]) dp[j][i] = max(dp[j][i], dp[j+k+pre[j]][i-pre[j]]+1);
			}
		}
	}
	FOR(i,0,n+1) printf("%d ",dp[0][i]);
	printf("\n");
	return 0;

}