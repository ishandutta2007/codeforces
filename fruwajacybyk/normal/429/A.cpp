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

VI g[max_n];
VI goal;

int dist[max_n];
int Even = 0;
int Odd = 0;
int ans =0;
VI w;

int dfs(int v,int d){
	int old;
	if(d%2==0){
		old = Even;
		if(Even != goal[v]){ Even=1-Even; ans++; w.pb(v+1);}
		dist[v]=d;
		FORE(i,g[v])
			if(dist[*i]==-1) dfs(*i,d+1);
		Even = old;
	}
	else{
		old = Odd;
		if(Odd != goal[v]){ Odd=1-Odd; ans++; w.pb(v+1);}
		dist[v]=d;
		FORE(i,g[v])
			if(dist[*i]==-1) dfs(*i,d+1);
		Odd = old;
	}
}

int main(){
	int n; scanf("%d",&n);
	FOR(i,0,n-1){
		int a,b; scanf("%d%d",&a,&b); a--; b--;
		g[a].pb(b); g[b].pb(a);
	}
	FOR(i,0,n){
		int a; scanf("%d",&a); goal.pb(a);
	}
	FOR(i,0,n){
		int a; scanf("%d",&a); goal[i]=(goal[i]+a)%2;
	}
	FOR(i,0,n) dist[i] = -1;
	dfs(0,0);
	printf("%d\n",ans);
	FOR(i,0,ans) printf("%d\n",w[i]);

	return 0;
}