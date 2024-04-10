#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 200000
#define ll long long
#define mo 2147483647
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,m,q,x,y,ans;
int H[N],h[N],F[N],f[N][18];
vector<int>P[N];map<int,bool>p[N];
void bd(int x){
	for(auto i:P[x])if(i!=F[x]){
		if(!H[i]){H[i]=H[x]+1;F[i]=x;bd(i);}
		if(H[i]<H[f[x][0]])f[x][0]=i;
		if(H[x]<H[f[i][0]])f[i][0]=x;
	}
}
void dfs(int x){h[x]=h[f[x][0]]+1;
	for(auto i:P[x])if(!h[i])dfs(i);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,n)f[i][0]=i;
	rep(i,1,m){
		scanf("%d%d",&x,&y);
		P[x].pb(y);P[y].pb(x);p[x][y]=1;p[y][x]=1;
	}
	H[1]=1;f[1][0]=1;bd(1);dfs(1);
	rep(j,1,17)rep(i,1,n)f[i][j]=f[f[i][j-1]][j-1];
	rep(i,1,q){ans=0;
		scanf("%d%d",&x,&y);if(h[x]<h[y])swap(x,y);
		dep(j,17,0)if(h[x]-(1<<j)>=h[y])ans+=1<<j,x=f[x][j];
		dep(j,17,0)if(f[x][j]!=f[y][j])ans+=1<<(j+1),x=f[x][j],y=f[y][j];
		if(x!=y){
			if(p[x].count(y))ans++;else ans+=2;
		}
		printf("%d\n",ans);
	}
}