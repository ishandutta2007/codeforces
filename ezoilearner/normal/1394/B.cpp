#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int Ans=0;
int n,m,k;
#define Maxn 200010

int a[12];

struct Edge{
	int to,t;
	Edge(){to=t=0;}
	Edge(int _to,int _t){to=_to;t=_t;}
	bool operator <(const Edge &z)const{return t<z.t;}
};
vector<Edge> vec[Maxn];
int in[Maxn][12][12];
bool rel[12][12][12][12];

void dfs(int u){
	if(u==k+1){
		for(int i=1;i<=k;++i)
		    for(int j=1;j<=k;++j)
		        if(rel[i][a[i]][j][a[j]])return;
		Ans++;
		return;
	}
	for(int i=1;i<=u;++i){
		a[u]=i;
		dfs(u+1); 
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	int s,e,t;
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&s,&e,&t);
		vec[s].push_back(Edge(e,t));
	}
	for(int i=1;i<=n;++i){
		sort(vec[i].begin(),vec[i].end());
		for(int j=0;j<vec[i].size();++j)in[vec[i][j].to][vec[i].size()][j+1]++;
	}
	for(int i=1;i<=n;++i)
	    for(int j=0;j<vec[i].size();++j)
	        for(int t=1;t<=k;++t)
	            for(int l=1;l<=k;++l)
	                if(in[vec[i][j].to][t][l]){
					    if(t!=vec[i].size())rel[vec[i].size()][j+1][t][l]=true;
					    else if(in[vec[i][j].to][t][l]>1)rel[vec[i].size()][j+1][t][l]=true;
					}
	dfs(1);
	printf("%d\n",Ans);
	return 0;
}