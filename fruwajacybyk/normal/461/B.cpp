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
#define IOS ios_base::sync_with_stdio(0);


#define max_n 100005


using namespace std;

lint mod = 1e9+7;

lint power(lint x,int m){
	if(m==0) return 1LL;
	lint y = power(x,m/2);
	if(m%2==0) return (y*y)%mod;
	else return (((y*y)%mod)*x)%mod;
}

VI childs[max_n];
int parent[max_n];
int color[max_n];

lint resB[max_n];
lint resC[max_n];

lint dfsB(int v);
lint dfsC(int v);

lint dfsB(int v){
	if(resB[v]!=-1) return resB[v];
	if(color[v]==1) return 0;
	
	lint res = 1LL;

	FOR(i,0,childs[v].size()){
		lint x = dfsB(childs[v][i]);
		lint y = dfsC(childs[v][i]);
		res = (res*((x+y)%mod))%mod;
	}
	resB[v] = res;
	return res;
}

lint dfsC(int v){
	if(resC[v]!=-1) return resC[v];
	
	if(color[v]==1){
		lint res = 1LL;
		FOR(i,0,childs[v].size()){
			lint x = dfsB(childs[v][i]);
			lint y = dfsC(childs[v][i]);
			res = (res*((x+y)%mod))%mod;
		}
		resC[v] = res;
		return res;
	}
	else{
		lint sum = 0LL;
		lint prod = 1LL;
		FOR(i,0,childs[v].size()){
			lint x = dfsB(childs[v][i]);
			lint y = dfsC(childs[v][i]);
			sum = ( sum + (y* power((x+y)%mod,mod-2))%mod)%mod;
			prod = (prod*((x+y)%mod))%mod;
		}
		resC[v] = (prod*sum)%mod;
		return (prod*sum)%mod;
	}
}

int main(){
	IOS;
	make(n);
	FOR(i,0,n-1){
		make(p);
		childs[p].pb(i+1);
		parent[i+1] = p;
	}
	FOR(i,0,n){
		make(a); color[i] = a;
	}
	FOR(i,0,n) resB[i] = resC[i] = -1LL;
	cout<<dfsC(0)<<endl;
	
	return 0;
}