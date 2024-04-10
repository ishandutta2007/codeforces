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

int r[max_n];

int n,N;
VI rt;

void init(){
	for(N=1; N<n+1; N<<=1);
	rt = VI(N<<1);
	FOR(i,0,N) rt[i+N] = N+1;
	rt[n+N] = 0;
	FORD(i,N-1,1){
		rt[i] = min(rt[i<<1],rt[(i<<1)|1]);
	}
}

// w przedziale x,y reprezentowanym przez v
// szukaj przedziau l,r 
int rob(int v, int x, int y, int l, int r){
	if(l > r) return N+1 ;
	if( l == x &&  r == y){
		return rt[v] ;
	}
	int mid = (x+y)/2;
	int u1 = rob(2*v,x,mid,l,min(r,mid));
	int u2 = rob(2*v+1,mid+1,y,max(l,mid+1),r);
	return min(u1,u2);
}

void change(int v, int x){
	rt[v+N] = x;
	for(int j = ((v+N)>>1); j>=1 ; j>>=1){
		rt[j] = min(rt[j<<1],rt[(j<<1)|1]);
	}
}



int main(){
	read(n);
	make2(s,l);
	VI v;
	FOR(i,0,n){
		make(a); v.pb(a);
	}
	set<PII> s1,s2;
	int rb = n-1;
	FORD(i,n-1,0){
		s1.insert(mp(v[i],i));
		s2.insert(mp(-v[i],i));
		while(s1.begin()->nd > rb) s1.erase(s1.begin());
		while(s2.begin()->nd > rb) s2.erase(s2.begin());	
		while(-s2.begin()->st-s1.begin()->st > s){
			rb = max(s1.begin()->nd-1,s2.begin()->nd-1);
			while(s1.begin()->nd > rb) s1.erase(s1.begin());
			while(s2.begin()->nd > rb) s2.erase(s2.begin());
		}
		r[i] = rb;
	}

	init();

	FORD(i,n-1,0){
		int left = i+(l-1);
		int nowy = rob(1,0,N-1,left+1,r[i]+1);
		change(i,nowy+1);
	}
	printf("%d\n",rt[N]>N ? -1 : rt[N]);


	return 0;
}