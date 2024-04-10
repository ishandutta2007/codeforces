#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define N 100010
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
int n;
double ans;
vector<int> G[N];
void dfs(int u,int fa,int dep){
	ans+=1.0/dep;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u,dep+1);
	}
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0,1);
	printf("%.10lf\n",ans);
	return 0;
}