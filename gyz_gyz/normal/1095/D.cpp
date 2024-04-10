#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 300000
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
vector<int>p[N];int x[N],y[N];bool v[N];
void dfs(int t){
	printf("%d ",t);v[t]=1;
	for(auto i:p[t])if((i==x[t]||i==y[t])&&!v[i])dfs(i);
}
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d",&x[i],&y[i]);
		p[x[i]].pb(y[i]);p[y[i]].pb(x[i]);
	}dfs(1);
}