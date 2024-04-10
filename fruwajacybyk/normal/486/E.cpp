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
#define max_n 100015

VI dl,dl2;
int f1[max_n];
int f2[max_n];
int ans[max_n];
int ile[max_n];

int main(){
	IOS;
	make(n);
	VI v; 
	FOR(i,0,n){
		make(a); v.pb(a);
	}
	dl.clear(); dl2.clear();


	dl.pb(0);

	FOR(i,0,n){
		VI::iterator j = lower_bound(dl.begin(),dl.end(),v[i]);
		f1[i] = j-dl.begin();
		if(j==dl.end()) dl.pb(v[i]);
		else *j = v[i];

	}

	dl2.pb(-1e6);
	FOR(i,0,n){
		VI::iterator j = lower_bound(dl2.begin(), dl2.end(),-v[n-1-i]);
		f2[n-1-i] = j-dl2.begin();
		if(j==dl2.end()) dl2.pb(-v[n-1-i]);
		else *j = -v[n-1-i];
	}


	FOR(i,0,n+3) ile[i] = 0;
	int res = dl.size()-1;
	FOR(i,0,n){
		if(f1[i]+f2[i]!=res+1) ans[i] = 1;
		else{
			ans[i] = 2;
			ile[f1[i]]++;
		}
	}
	FOR(i,0,n){
		if(ans[i]==2 && ile[f1[i]]==1) ans[i]=3;	
	}
	FOR(i,0,n)
		printf("%d",ans[i]);
	printf("\n");
	
}