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

#define max_n 300005


using namespace std;

int fuparent[max_n];
int sciezka[max_n];

int fufind(int x){
	if(fuparent[x]==x) return x;
	int y = fufind(fuparent[x]);
	fuparent[x] = y;
	return y;
}

int funion(int x,int y){
	fuparent[y] = x;
	int newd = (sciezka[x]+2)/2 + (sciezka[y]+2)/2;
	newd = max(newd,max(sciezka[x],sciezka[y]));
	sciezka[x] = newd;
	
	return x;

}

VI g[max_n];
set<int> zrobione;
int kolor[max_n];

PII najdalszy(int u,int p){
	PII para = mp(u,0);
	FOR(i,0,g[u].size()){
		int v = g[u][i];
		if(v!=p){
			PII res = najdalszy(v,u);
			res.nd++;
			if(res.nd > para.nd)
				para = res;
		}
	}
	return para;
}

bool rob(int v,int p,int y,int komu){
	if(v==y){
		sciezka[komu]++;
		return true;
	}
	FOR(i,0,g[v].size()){
		int u = g[v][i];
		if(u!=p){
			if(rob(u,v,y,komu)){
				sciezka[komu]++;
				return true;
			}
		}
	}
	return false;
}




int main(){
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	FOR(i,0,n) fuparent[i] = i;
	FOR(i,0,m){
		int a,b;
		scanf("%d%d",&a,&b); a--; b--;
		funion(fufind(a),fufind(b));
		g[a].pb(b);
		g[b].pb(a);
	}
	FOR(i,0,n) kolor[i] = -1;
	FOR(i,0,n) sciezka[i] = 0;
	FOR(i,0,n){
		int sk = fufind(i);
		if(zrobione.find(sk)!=zrobione.end()) continue;
		zrobione.insert(sk);
		PII aa = najdalszy(sk,-1);
		PII bb = najdalszy(aa.st,-1);
		int x = aa.st, y = bb.st;
		rob(x,-1,y,sk);		
	}

	FOR(i,0,q){
		int a,b,c;
		scanf("%d",&a);
		if(a==1){
			scanf("%d",&b); b--;
			int sk = fufind(b);
			printf("%d\n",sciezka[sk]-1);
		}
		if(a==2){
			scanf("%d%d",&b,&c); b--; c--;
			int bb = fufind(b);
			int cc = fufind(c);
			if(bb!=cc){
				funion(bb,cc);
			}
		}
	}
	



}