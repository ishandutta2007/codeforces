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

int a[105][105];

int rows[105];
int cols[105];

int main(){
	IOS;
	make2(n,m);
	FOR(i,0,n)
		FOR(j,0,m){
			make(b); a[i][j] = b;
		}

	FOR(i,0,max(n,m)) rows[i] = cols[i] = 0;

	bool to = false;
	bool tamto = false;

	FOR(i,0,n) FOR(j,0,m){
		if(a[i][j]==1){
			bool row = true, col = true;
			FOR(k,0,m) if(a[i][k]!=1) row = false;
			FOR(k,0,n) if(a[k][j]!=1) col = false;
			if(!row && !col){
				printf("NO\n"); return 0;
			}
			if(row){ rows[i] = 1; to = true;}
			if(col){ cols[j] = 1; tamto = true;}
		}
	}
	if(!to && !tamto){
		printf("YES\n");
		FOR(i,0,n){
			FOR(j,0,m) printf("0 ");
			printf("\n");
		}
		return 0;
	}
	if(!to || !tamto){
		printf("NO\n");
		return 0;
	}
	
	printf("YES\n");
	FOR(i,0,n){
		FOR(j,0,m) printf("%d ", (rows[i]==1 && cols[j]==1) ? 1 : 0);
		printf("\n");
	}



}