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

#define max_n 100005


using namespace std;


int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	VI a; VI b;
	FOR(i,0,n){
		int u; scanf("%d",&u); a.pb(u);
	}
	FOR(i,0,m){
		int u; scanf("%d",&u); b.pb(u);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	lint sa = 0;
	lint sb = 0;
	FOR(i,0,n) sa+=a[i];
	FOR(i,0,m) sb+=b[i];
	
	
	
	lint x1 = sa;
	FOR(i,0,m-1){
		if(sa>b[i]) x1+=b[i];
		else x1+=sa;
	}

	lint x2 = sb;
	FOR(i,0,n-1){
		if(sb>a[i]) x2+=a[i];
		else x2 +=sb;
	}
	
	cout<<min(x1,x2)<<endl;
	

	return 0;
}