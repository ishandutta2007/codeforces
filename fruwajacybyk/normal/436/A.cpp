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

int type[max_n];
int h[max_n];
int m[max_n];
int eaten[max_n];
int n;

int get(int typ, int skok){
	int ja = -1;
	int best = -1;
	FOR(i,0,n){
		if(type[i] == typ && eaten[i] == 0 && h[i] <= skok){
			if(m[i]> best){
				best = m[i];
				ja = i;
			}
		}
	}
	return ja;
}

int main(){
	read(n);
	make(x);
	FOR(i,0,n){
		read3(type[i],h[i],m[i]);
		eaten[i] = 0;
	}
	int res1 = 0;
	int typ = 0;
	int locx = x;
	while(1){
		int kto = get(typ, locx);
		if(kto==-1) break;
		eaten[kto] = 1; res1++; typ = 1-typ;
		locx += m[kto];
	}
	int res2 = 0;
	typ = 1;
	locx = x;
	FOR(i,0,n) eaten[i] = 0;
	while(1){
		int kto = get(typ,locx);
		if(kto==-1) break;
		eaten[kto] = 1; res2++; typ = 1-typ;
		locx+= m[kto];
	}

	printf("%d\n",max(res1,res2));
	return 0;
}