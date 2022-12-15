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

using namespace std;


int m[2005][2005];
int color[2005];
int n;

void dfs1(int v){
	if(color[v]==0){
		color[v] = 1;
		FOR(i,0,n) if(m[v][i]) dfs1(i);
	}
}

void dfs2(int v){
	if(color[v]==0){
		color[v] = 1;
		FOR(i,0,n) if(m[i][v]) dfs2(i);
	}
}

int main(){
	scanf("%d",&n);
	FOR(i,0,n) FOR(j,0,n) scanf("%d",&m[i][j]);
	
	FOR(j,0,n) color[j] = 0;
	dfs1(0);
	FOR(j,0,n) if(color[j]==0){ printf("NO\n"); return 0;}
	
	FOR(j,0,n) color[j] = 0;
	dfs2(0);
	FOR(j,0,n) if(color[j]==0){ printf("NO\n"); return 0;}

	printf("YES\n");


	
	return 0;
}