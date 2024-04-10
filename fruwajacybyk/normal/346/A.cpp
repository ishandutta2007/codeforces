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

#define max_n 200005


using namespace std;


int gcd(int a,int b){
	return a==0 ? b : gcd(b%a,a);
}


int main(){
	int n; scanf("%d",&n);
	VI v;
	FOR(i,0,n){
		int a; scanf("%d",&a);
		v.pb(a);
	}
	int d = v[0]; int maxi = v[0];
	FOR(i,0,n){
		d = gcd(d,v[i]);
		maxi = max(maxi,v[i]);
	}
	int ruchy = maxi/d - n;
	if(ruchy&1) printf("Alice\n");
	else printf("Bob\n");


	return 0;
}