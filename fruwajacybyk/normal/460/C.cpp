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

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;

#define max_n 200005


using namespace std;

VI v;
int n,m,w;
int pokon[1000005]; 

bool check(int h){
	int mam = m;
	int akt = 0;
	FOR(i,0,n) pokon[i] = 0;
	FOR(i,0,n){
		akt +=pokon[i];
		if(v[i]+akt>=h) continue;
		int potrzeba = h-(v[i]+akt);
		akt+= potrzeba; mam-=potrzeba; if(mam<0) return false;
		if(i+w<n)  pokon[i+w]-=potrzeba;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>w;
	FOR(i,0,n){
		make(int,a); v.pb(a);
	}
	int mini = 1e9; FOR(i,0,n) mini = min(mini,v[i]);
	int lb=mini;
	int ub=mini+m;
	while(ub-lb>1){
		int sr = (ub+lb)/2;
		if(check(sr)) lb = sr;
		else ub = sr;
	}
	if(check(ub)) cout<<ub<<endl;
	else cout<<lb<<endl;
	
	
	return 0;
}