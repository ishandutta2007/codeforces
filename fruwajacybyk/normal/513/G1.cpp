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

int inv(VI v){
	int ans = 0;
	FOR(i,0,v.size())
		FOR(j,i+1,v.size())
			if(v[i]>v[j]) ans++;

	return ans;
}

VI rew(VI v, int p, int k){
	VI res = v;
	int i = p, j = k;
	while(i<j){
		swap(res[i],res[j]);
		i++; j--;
	}
	return res;
}



int main(){
	make2(n,k);
	VI p; FOR(i,0,n){
		make(a); p.pb(a);
	}
	map<VI,int> w;
	w[p] = 1;
	FOR(i,0,k){
		map<VI,int> w2;
		FORE(j,w){
			FOR(i1,0,n) FOR(j1,i1,n){
				VI dupa = rew(j->st,i1,j1);
				if(w2.find(dupa)==w2.end()) w2[dupa] = j->nd;
				else w2[dupa] += j->nd;
			}
		}
		w = w2;
	}
	lint ile = 0;
	int gosci = 0;
	FORE(j,w){
		ile += inv(j->st)*j->nd;
		gosci += j->nd;
	}
	printf("%.17lf\n",ile*1./gosci);
}