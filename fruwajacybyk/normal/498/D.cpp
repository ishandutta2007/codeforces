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

VI a;
int n;
VI rt[4*max_n];
int res;

void rob(int v, int x, int y, int l, int r){
	if(l > r) return ;
	if( l == x &&  r == y){
		res+=rt[v][res%60];
		return ;
	}
	int mid = (x+y)/2;
	rob(2*v,x,mid,l,min(r,mid));
	rob(2*v+1,mid+1,y,max(l,mid+1),r);
}

int main(){
	read(n);
	FOR(i,0,n){
		make(x); a.pb(x);
	}
	int N; for(N=1; N<n; N<<=1);

	FOR(i,1,2*N) rt[i] = VI(60);

	FOR(i,0,n)
		FOR(j,0,60)
			rt[i+N][j] = ( j%a[i]==0 ? 2 : 1);
	
	FOR(i,n,N) FOR(j,0,60) rt[i+N][j] = 0;

	FORD(i,N-1,1){
			FOR(j,0,60){
				int l = rt[2*i][j];
				int p = rt[2*i+1][(j+l)%60];
				rt[i][j] = l+p;
			}
	}

	make(q);
	while(q--){

		char C='U'; while(C!='A' && C!='C') C = getchar();
		if(C=='C'){
			make2(x,y);
			x--;
			a[x] = y;
			FOR(j,0,60) rt[x+N][j] = (j%a[x]==0) ? 2 : 1;
			int u;
			for(u = x+N	; u>1 ;){
				u = u/2;
				FOR(j,0,60){
					int l = rt[2*u][j];
					int p = rt[2*u+1][(j+l)%60];
					rt[u][j] = l+p;
				}
			}
		}
		else{
			make2(x,y);
			x--; y--; y--;
			res = 0;
			rob(1,0,N-1,x,y);
			printf("%d\n",res);
		}
	}
	






	return 0;
}