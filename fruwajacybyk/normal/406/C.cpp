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

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int
#define max_n 100005

using namespace std;

int n,m;
VI g[max_n];
int depth[max_n];
VI wiszace[max_n];

vector<pair<PII,int> > sol;

int dfs(int v,int d){
		depth[v] = d;
		FOR(i,0,g[v].size()){
			int w = g[v][i];
			if(depth[w]==-1){
				int x = dfs(w,d+1);
				if(x!=-1){
					sol.pb(mp(mp(x,w),v));
				}
				else wiszace[v].pb(w);
			}
			else if(depth[w]==depth[v]-1) continue;
			else if(depth[w]<depth[v]) wiszace[w].pb(v);
		}
		for(int i = 0; i+1<wiszace[v].size();i+=2){
			sol.pb(mp(mp(wiszace[v][i],v),wiszace[v][i+1]));	
		}
		if(wiszace[v].size()%2==0) return -1;
		else return wiszace[v].back();
}

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,0,m){
		int a,b; 
		scanf("%d%d",&a,&b);
		g[a-1].pb(b-1);
		g[b-1].pb(a-1);
	}
	if(m%2!=0){
		printf("No solution\n");
		return 0;
	}
	FOR(i,0,n) depth[i] = -1;
	dfs(0,0);
	FOR(i,0,sol.size()){
		printf("%d %d %d\n",sol[i].st.st+1,sol[i].st.nd+1,sol[i].nd+1);
	}

	return 0;
}