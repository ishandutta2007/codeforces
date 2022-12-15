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



int main(){
	IOS;
	make2(n,s);
	int l = 0, r = 0;
	if(n==1){
		if(s<=9) printf("%d %d\n",s,s);
		else printf("-1 -1\n");
		return 0;
	}
	if(s==0 || s>9*n){
		printf("-1 -1\n");
		return 0;
	}
	VI v1,v2;
	int t = s;
	FOR(i,0,n){
		if(s>=9) {v1.pb(9); s-=9;}
		else{
			v1.pb(s); s-=s;
		}
	}
	if((n-1)*9+1 >= t){
		v2.pb(1);
		t -=1;
	}
	else{
		v2.pb(t-9*(n-1));
		t = 9*(n-1);
	}
	FOR(i,1,n){
		int dop = max(0,t-9*(n-i-1));
		v2.pb(dop);
		t-=dop;
	}
	FOR(i,0,n) printf("%d",v2[i]);
	printf(" ");
	FOR(i,0,n) printf("%d",v1[i]);
	printf("\n");
}