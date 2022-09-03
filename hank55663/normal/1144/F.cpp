#include<bits/stdc++.h>
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define cpii const pii
#define cpdd const pdd
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define LL long long 
using namespace std;
vector<int> v[200005];
int color[200005];
void dfs(int x,int col){
	color[x]=col;
	for(auto it:v[x]){
		if(color[it]==-1){
			dfs(it,col^1);
		}
		else if(color[it]==col){
			printf("NO\n");
			exit(0);
		}
	}
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	pii p[200005];
	for(int i =0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		p[i]=mp(x,y);
		v[x].pb(y);
		v[y].pb(x);
	}
	fill(color,color+n+1,-1);
	for(int i =1;i<=n;i++){
		if(color[i]==-1)
		dfs(i,0);
	}
	printf("YES\n");
	for(int i = 0;i<m;i++){
		if(color[p[i].x]){
			printf("1");
		}
		else{
			printf("0");
		}
	}
	printf("\n");
}