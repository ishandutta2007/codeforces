#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define fr first
#define sc second
#define ll long long
#define N 400000
#define mo 998244353
#define inf 1000000000
#define Inf 5000000000000000000ll
using namespace std;
int T,x,y,n,m,k,v[N];bool t[N];
vector<int>p[N];
int dfs(int x){
	if(v[x]==2)return x;v[x]=0;
	for(auto i:p[x])if(v[i]){
		int r=dfs(i);
		if(r)return r;
	}return 0;
}
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%d",&n);
		rep(i,1,n){
			p[i].clear();t[i]=0;v[i]=1;
		}
		rep(i,1,n-1){
			scanf("%d%d",&x,&y);
			p[x].pb(y);p[y].pb(x);
		}
		scanf("%d",&m);
		rep(i,1,m){
			scanf("%d",&x);v[x]=2;
		}
		scanf("%d",&k);
		rep(i,1,k){
			scanf("%d",&x);t[x]=1;
		}
		printf("B %d\n",x);fflush(stdout);
		scanf("%d",&x);x=dfs(x);
		printf("A %d\n",x);fflush(stdout);
		scanf("%d",&y);
		if(t[y])printf("C %d\n",x);else printf("C -1\n");
		fflush(stdout);
	}
}