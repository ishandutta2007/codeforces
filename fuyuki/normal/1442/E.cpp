#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=2e5+1;
vector<int>e[N];
int T,n,rt,rtw,ans,a[N];
int cmax(int&x,int y){return(x-y>>31)&&(x=y);}
void dfs(int u,int now,int fa=0,int dis=0){
	if(cmax(ans,dis)||!rtw)rt=u,rtw=now;
	for(int v:e[u])if(v!=fa)dfs(v,a[v]?:now,u,dis+(now!=a[v]&&now&&a[v]));
}
int main(){
	for(int x,y=scanf("%d",&T);T--;ans=rtw=0){
		scanf("%d",&n);
		FOR(i,1,n)scanf("%d",a+i),e[i].clear();
		FOR(i,2,n)scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
		dfs(1,a[1]),dfs(rt,rtw),cout<<(ans+3)/2<<'\n';
	}
	return 0;
}