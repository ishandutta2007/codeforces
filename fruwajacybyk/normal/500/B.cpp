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

int A[305][305];
char s[305];

int par[305];

int fuf(int x){
	return x==par[x] ? x : par[x] = fuf(par[x]);
}

void fun(int x,int y){
	int xx = fuf(x); int yy = fuf(y);
	if(xx<yy) par[yy] = xx;
	else par[xx] = yy;
}

int ans[305];


int main(){
	make(n);
	VI v;
	FOR(i,0,n){
		make(a); v.pb(a);
	}
	FOR(i,0,n) par[i] = i;
	FOR(i,0,n){
		scanf("%s",s);
		FOR(j,0,n) A[i][j] = s[j]-'0';
	}

	FOR(i,0,n) FOR(j,0,n){
		if(A[i][j]==1) fun(i,j);
	}

	FOR(i,0,n){
		VI w; VI pos;
		FOR(j,0,n){
			if(fuf(j)==i){
				pos.pb(j); w.pb(v[j]);
			}
		}
		if(w.size()!=0){
			sort(w.begin(),w.end());
			sort(pos.begin(),pos.end());
			FOR(j,0,w.size()){
				ans[pos[j]]=w[j];
			}
		}
	}
	FOR(i,0,n){
		printf("%d ",ans[i]);
	}
	printf("\n");





	

}