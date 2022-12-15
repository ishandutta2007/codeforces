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
#define IOS ios_base::sync_with_stdio(0)


#define max_n 2000005


using namespace std;

string s="+------------------------+\n|O.O.O.#.#.#.#.#.#.#.#.|D|)\n|O.O.O.#.#.#.#.#.#.#.#.|.|\n|O.......................|\n|O.O.#.#.#.#.#.#.#.#.#.|.|)\n+------------------------+\n";


	

int main(){
	IOS;
	int u = s.length();
	VI pos; pos.pb(28); pos.pb(56); pos.pb(83); pos.pb(110);
	for(int i = 30; i <=48; i+=2){
		pos.pb(i);
		pos.pb(i+28);
		pos.pb(i+82);
	}
	make(k);
	FOR(i,0,pos.size()){
		if(i<k) s[pos[i]] = 'O';
		else s[pos[i]] = '#';
	}
	cout<<s;
	return 0;
}