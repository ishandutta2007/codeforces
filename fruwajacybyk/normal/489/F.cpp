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

map<PII,lint> funkcja;

int mod;

int rob(int u,int v){
	if(funkcja.find(mp(u,v))!=funkcja.end()) return funkcja[mp(u,v)];
	if(u==0 && v==0) return 1;
	if(u < 0 || v < 0) return 0;
	int a1 = (rob(u-2,v)%mod);
	int a2 = (rob(u,v-1)%mod);
	int a3 = (rob(u+2,v-2)%mod);
	int ans = (a1*1LL* (((u*1LL*(u-1))/2)%mod))%mod;
	int ans2 = (((a2*1LL*u)%mod)*v)%mod;
	int ans3 = (a3*1LL* (((v*1LL*(v-1))/2)%mod))%mod;
	ans = (((ans2+ans3)%mod) + ans)%mod;
	funkcja[mp(u,v)] = ans;
	return ans;
}

char s[605];

int main(){
	IOS;
	make2(n,m);
	scanf("%d",&mod);
	int mam[505];
	FOR(i,0,n) mam[i] = 0;
	FOR(i,0,m){
		scanf("%s",s);
		FOR(j,0,n) if(s[j]=='1') mam[j]++; 
	}
	int x = 0, y = 0;
	FOR(j,0,n){
		if(mam[j]==0) y++;
		if(mam[j]==1) x++;
	}
	printf("%d\n",rob(x,y));
}