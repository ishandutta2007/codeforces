#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<cstdlib>
using namespace std;
#define N 200010
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,m,dep[N],len,p[N],cnt,head[N];
struct Edge{
	int to,nxt;
}edge[N<<1];
void add(int a,int b){
	++cnt;
	edge[cnt].to=b;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
vector<int> ans,path;
void dfs(int u){
	path.push_back(u);
	dep[u]=path.size();
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(!dep[v])dfs(v);
		else if(dep[u]-dep[v]>=len-1){
			printf("2\n");
			printf("%d\n",dep[u]-dep[v]+1);
			for(int j=dep[v]-1;j<=dep[u]-1;++j){
				printf("%d ",path[j]);
			}	
			exit(0);
		}
	}
	if(!p[u]){
		ans.push_back(u);
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			p[v]=1;
		}
	}
	path.pop_back();
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	len=ceil(sqrt(n));
	dfs(1);
	printf("1\n");
	for(int i=0;i<len;++i){
		printf("%d ",ans[i]);
	}
	return 0;
}