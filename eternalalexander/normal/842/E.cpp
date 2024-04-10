#include <bits/stdc++.h>

const int maxn = 5e5 + 7;

namespace QuickLCA { //https://blog.csdn.net/stone41123/article/details/79695232
	
	const int N=1e6+5;
	int n,m,s,tot,cnt;
	int head[N],to[N],Next[N],Log[N];
	inline void addedge(int x,int y){to[++tot]=y;Next[tot]=head[x];head[x]=tot;}
	int a[N],dep[N],mn[21][N],p[N];
	inline void dfs(int x,int fa){
	    a[++cnt]=x;p[x]=cnt;dep[x]=dep[fa]+1;
	    for(int i=head[x];i;i=Next[i]){
	        int u=to[i];
	        if(u==fa)continue;
	        dfs(u,x);
	        a[++cnt]=x;
	    }
	}
	inline int LCA(int x,int y) {
		if(p[x]>p[y])std::swap(x,y);
	       int k=Log[p[y]-p[x]+1],ans;
	       if(dep[mn[k][p[x]]]<dep[mn[k][p[y]-(1<<k)+1]])
	           ans=mn[k][p[x]];
	       else ans=mn[k][p[y]-(1<<k)+1];
	    	return ans;
	}
	int prework(int n){
	    Log[0]=-1;
	   // for(int i=1;i<n;++i){
	     //   int x=read(),y=read();
	        //addedge(x,y);addedge(y,x);
	    //}
	    dfs(1,0);
	    for(int i=1;i<=cnt;++i)mn[0][i]=a[i];
	    for(int i=1;i<=20;++i)
	        for(int j=1;j+(1<<i)<=cnt;++j)
	            if(dep[mn[i-1][j]]<dep[mn[i-1][j+(1<<(i-1))]])
	                mn[i][j]=mn[i-1][j];
	            else mn[i][j]=mn[i-1][j+(1<<(i-1))];
	    for(int i=1;i<=cnt;++i)Log[i]=Log[i>>1]+1;
	    return 0;
	}
}

int n,dp[maxn],fa[maxn],d[maxn],x[maxn],y[maxn],len[maxn];
std::vector<int>ch[maxn];

int dis(int x,int y) { return dp[x] + dp[y] - 2 * dp[QuickLCA::LCA(x,y)]; }
int diam(int u,int p) { return std::max ( dis(u,x[p]), dis(u,y[p]) ); }

int main() {
	scanf("%d",&n); n ++;
	for (int i = 2; i <= n; ++ i) {
		scanf("%d",&fa[i]);
		dp[i] = dp[fa[i]] + 1;
		ch[fa[i]].push_back(i);
		QuickLCA::addedge(i,fa[i]);
		QuickLCA::addedge(fa[i],i);
	} QuickLCA::prework(n);
	x[1] = y[1] = 1;
	for (int i = 2; i <= n; ++ i) {
		int d1 = len[i-1], d2 = dis(x[i-1],i), d3 = dis(y[i-1],i);
		len[i] = std::max( { d1,d2,d3 } );
		if (len[i] == d1) { x[i] = x[i-1]; y[i] = y[i-1]; }
		if (len[i] == d2) { x[i] = x[i-1]; y[i] = i; }
		if (len[i] == d3) { x[i] = y[i-1]; y[i] = i; }
	}
	for (int i = 1; i <= n; ++ i) {
		int l = i, r = n, p = i - 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (diam(i,mid) == len[mid]) { p = mid; l = mid + 1; }
			else r = mid - 1;
		} d[i] ++; d[p + 1] --;
	} for (int i = 2; i <= n; ++ i) {
		d[i] += d[i-1];
		printf("%d\n",d[i]);
	}
	return 0;
}