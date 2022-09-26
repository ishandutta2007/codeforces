#include<iostream>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
using namespace std;
typedef long long ll;
#define N 1000100
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n;
void Solve_First(){
	printf("First\n");
	fflush(stdout);
	for(int i=1;i<=n;++i)printf("%d ",i);
	for(int i=1;i<=n;++i)printf("%d ",i);
	printf("\n");
	fflush(stdout);
}
vector<int> G[N],p[N];
int col[N];
void dfs(int u){
	for(auto v:G[u]){
		if(~col[v])continue;
		col[v]=col[u]^1;
		dfs(v);
	}
}
void Solve_Second(){
	printf("Second\n");
	fflush(stdout);
	for(int i=1;i<=(n<<1);++i){
		p[read()].push_back(i);
		col[i]=-1;
	}
	for(int i=1;i<=n;++i){
		G[i].push_back(n+i);
		G[n+i].push_back(i);
		G[p[i][0]].push_back(p[i][1]);
		G[p[i][1]].push_back(p[i][0]);
	}
	for(int i=1;i<=(n<<1);++i){
		if(!~col[i]){
			col[i]=0,dfs(i);
		}
	}
	ll myh=0;
	for(int i=1;i<=(n<<1);++i){
		if(!col[i])myh+=i;
	}
	if(myh%(n<<1)==0){
		for(int i=1;i<=(n<<1);++i){
			if(!col[i])printf("%d ",i);
		}
	}
	else{
		for(int i=1;i<=(n<<1);++i){
			if(col[i])printf("%d ",i);
		}
	}
	printf("\n");
	fflush(stdout);
}
int main(){
	n=read();
	if(n&1){
		Solve_Second();
	}
	else{
		Solve_First();
	}
	assert(~read());
	return 0;
}