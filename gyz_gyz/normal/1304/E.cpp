#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int mo=1e9+7;
const int inf=1e9;
int f[18][N],h[N];vector<int>p[N];
void dfs(int x){
	for(auto&i:p[x])if(i!=f[0][x]){
		f[0][i]=x;h[i]=h[x]+1;dfs(i);
	}
}
int lca(int x,int y){
	if(h[x]<h[y])swap(x,y);
	dep(i,17,0)if((h[x]-h[y])>>i)x=f[i][x];
	if(x==y)return x;
	dep(i,17,0)if(f[i][x]!=f[i][y])x=f[i][x],y=f[i][y];
	return f[0][x];
}
int dis(int x,int y){
	return h[x]+h[y]-h[lca(x,y)]*2;
}
bool ok(int x,int y){
	return y>=x&&x%2==y%2;
}
int main(){int n,q;
	scanf("%d",&n);
	rep(i,2,n){int x,y;
		scanf("%d%d",&x,&y);
		p[x].push_back(y);
		p[y].push_back(x);
	}dfs(1);
	rep(i,1,17)rep(j,1,n)f[i][j]=f[i-1][f[i-1][j]];
	scanf("%d",&q);
	rep(i,1,q){int x,y,a,b,k;
		scanf("%d%d%d%d%d",&x,&y,&a,&b,&k);
		printf("%s\n",(ok(dis(a,b),k)||
		ok(dis(a,x)+dis(b,y)+1,k)||
		ok(dis(a,y)+dis(b,x)+1,k))?"YES":"NO");
	}
}