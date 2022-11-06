#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define pb push_back
#define fr first
#define sc second
#define N 200010
using namespace std;
typedef pair<int,int> pii;
vector<int>p[N];bool v[N];int a[N],ans;
pii dfs(int x,int y,int d,bool c){
	pii r={d,x};v[x]^=1;
	if(c)while(!(a[x]%y))a[x]/=y;
	for(auto i:p[x])if(v[i]==c&&!(a[i]%y))r=max(r,dfs(i,y,d+1,c));
	return r;
}
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n-1){int x,y;
		scanf("%d%d",&x,&y);
		p[x].pb(y);p[y].pb(x);
	}
	rep(i,1,n){
		rep(j,2,a[i]){
			if(j*j>a[i])break;
			if(!(a[i]%j))ans=max(ans,dfs(dfs(i,j,1,0).sc,j,1,1).fr);
		}
		if(a[i]>1)ans=max(ans,dfs(dfs(i,a[i],1,0).sc,a[i],1,1).fr);
	}
	printf("%d\n",ans);
}