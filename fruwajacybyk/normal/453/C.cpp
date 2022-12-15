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

#define N 100005
#define max_n 100005


using namespace std;

VI g[max_n];
int x[max_n];
VI dzieci[max_n];
int parent[max_n];
int kolejka[10*max_n];
	int start = 5*N; 
	int end = 5*N+1;

void front(int v){
	kolejka[start--] = v;
	x[v] = 1-x[v];
}

void back(int v){
	kolejka[end++] = v;
	x[v] = 1-x[v];
}

void dfs(int v,int p){
	back(v);
	FOR(i,0,g[v].size()){
		if(parent[g[v][i]]==-1){
			parent[g[v][i]]=v;
			dfs(g[v][i],v);		
			if(x[g[v][i]]==1){ 
				back(v);
				back(g[v][i]);
				back(v);
			}
			else back(v);
		}
	}
}

int main(){
	int n,m; 
	scanf("%d%d",&n,&m);
	FOR(i,0,m){
		int a, b;
		scanf("%d%d",&a,&b);
		g[a-1].pb(b-1);
		g[b-1].pb(a-1);
	}
	FOR(i,0,n) scanf("%d",&x[i]);
	int kto = -1;
	FOR(i,0,n) if(x[i]==1) kto = i;

	if(kto==-1){
		printf("0\n");
		return 0;
	}

	FOR(i,0,n) parent[i] = -1;
	dfs(kto,-2); parent[kto] = -2;
	if(x[kto]==1){
		x[kto]=0;
		start++;
	}
	FOR(i,0,n) 
		if(x[i]==1){
			printf("-1\n");
			return 0;
		}
	
	printf("%d\n",end-(start+1));
	FOR(i,start+1,end){
		printf("%d ",kolejka[i]+1);
	}
	printf("\n");


	return 0;
}