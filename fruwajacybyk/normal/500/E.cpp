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

int n,N;
VI pp,l;
int zasieg[max_n];
int dokonca[max_n];
set<PII> kju;

VI rt;

void init(){
	for(N=1; N<n; N<<=1);
	rt = VI(N<<1);
	FOR(i,0,N) rt[i+N] = 1e9;
	FORD(i,N-1,1){
		rt[i] = min(rt[i<<1],rt[(i<<1)|1]);
	}
}

// w przedziale x,y reprezentowanym przez v
// szukaj przedziau l,r 
int rob(int v, int x, int y, int l, int r){
	if(l > r) return 1e9;
	if( l == x &&  r == y){
		return rt[v];
	}
	int mid = (x+y)/2;
	int a = rob(2*v,x,mid,l,min(r,mid));
	int b = rob(2*v+1,mid+1,y,max(l,mid+1),r);
	return min(a,b);
}

void change(int v, int x){
	rt[v+N] = x;
	for(int j = (v+N)>>1; j ; j>>=1){
		rt[j] = min(rt[j<<1],rt[(j<<1)|1]);
	}
}



int main(){
	read(n);
	FOR(i,0,n){
		make2(a,b); pp.pb(a); l.pb(b);
	}
	FOR(i,0,n) l[i] = min(l[i], pp[n-1]-pp[i]);

	zasieg[n-1] = pp[n-1]+l[n-1];
	kju.insert(mp(pp[n-1],pp[n-1]+l[n-1]));
	dokonca[n-1] = 0;

	FORD(i,n-2,0){
		int act = pp[i]+l[i];
		while(kju.size()>0){
			PII ktos = *kju.begin();
			if(ktos.st <= act){
				act = max(act,ktos.nd);
				kju.erase(*kju.begin());
			}
			if(ktos.st > act) break;
		}
		zasieg[i] = act;
		int j = lower_bound(pp.begin(),pp.end(),zasieg[i])-pp.begin();
		dokonca[i] = pp[j]-zasieg[i]+dokonca[j];
		kju.insert(mp(pp[i],zasieg[i]));
	}
	
	init();
	FOR(i,0,n){
		change(i,dokonca[i]);
	}

	make(q);
	while(q--){
		make2(x,y);
		x--; y--;
		printf("%d\n",dokonca[x]-rob(1,0,N-1,x,y));
	}
}