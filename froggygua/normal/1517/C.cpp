#include<bits/stdc++.h>
using namespace std;
#define N 505
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
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
int n,p[N],a[N][N],tmp[N];
vector<int> g[N];
int L;
void dfs(int x,int y,int u){
	a[x][y]=tmp[u];
	g[y].pop_back();
	--p[u];
	L=y;
	if(!p[u])return;
	if(y==1)return;
	if(!a[x][y-1]){
		dfs(x,y-1,u);
	}
	else{
		dfs(x+1,y,u);
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		p[i]=tmp[i]=read();
		for(int j=n;j>=i;--j){
			g[i].push_back(j);
		}
	}
	for(int i=1;i<=n;++i){
		dfs(i,i,i);
		for(int j=L;j<=i;++j){
			while(p[i]&&!g[j].empty())a[g[j].back()][j]=tmp[i],g[j].pop_back(),--p[i];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}