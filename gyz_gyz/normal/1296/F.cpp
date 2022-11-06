#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int inf=1e9;
int e1[N],e2[N],h[N],a[N],f[N],p1[N],p2[N],w[N];
vector<int>p[N];
void dfs(int x){
	for(auto&i:p[x])if(i!=f[x]){
		h[i]=h[x]+1;f[i]=x;dfs(i);
	}
}
int main(){int n,m;
	scanf("%d",&n);
	rep(i,1,n-1){
		scanf("%d%d",&e1[i],&e2[i]);
		p[e1[i]].push_back(e2[i]);
		p[e2[i]].push_back(e1[i]);
	}
	dfs(1);scanf("%d",&m);
	rep(i,2,n)a[i]=1;
	rep(i,1,m){
		scanf("%d%d%d",&p1[i],&p2[i],&w[i]);
		for(int x=p1[i],y=p2[i];x!=y;x=f[x]){
			if(h[x]<h[y])swap(x,y);
			a[x]=max(a[x],w[i]);
		}
	}
	rep(i,1,m){int r=1e9;
		for(int x=p1[i],y=p2[i];x!=y;x=f[x]){
			if(h[x]<h[y])swap(x,y);
			r=min(r,a[x]);
		}
		if(r>w[i])return printf("-1\n"),0;
	}
	rep(i,1,n-1)printf("%d ",h[e1[i]]>h[e2[i]]?a[e1[i]]:a[e2[i]]);
}