#include <bits/stdc++.h>
#define maxn 100005
#define ll long long
#define int ll

int n,m,q,u,v,size[maxn],vis[maxn],d[maxn],f[maxn],st,tl,diam[maxn];
std::vector<int>A[maxn],ch[maxn];
std::vector<ll>suf[maxn];
std::map<int,double>rec[maxn];

void dfs(int u,int fa,int mark){
	d[u]=d[fa]+1;
	f[u]=std::max(f[u],d[u]);
	if(d[u]>d[st])st=u;
	vis[u]=mark;
	f[u]=std::max(f[u],d[u]);
	for(int v:ch[u])if(v!=fa)dfs(v,u,mark);
}

void work(int x){
	st=x;
	dfs(st,0,++tl);
	dfs(st,0,tl);
	dfs(st,0,tl);
}

int cmp(int a,int b){return f[a]<f[b];}



signed main(){
	f[0]=d[0]=-1;
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=m;++i){
		scanf("%lld%lld",&u,&v);
		ch[u].push_back(v);
		ch[v].push_back(u);
	}for(int i=1;i<=n;++i)
		if(!vis[i])work(i);
	for(int i=1;i<=n;++i){
		size[vis[i]]++;
		A[vis[i]].push_back(i);
		diam[vis[i]]=std::max(diam[vis[i]],f[i]);
	}for(int i=1;i<=tl;++i)std::sort(A[i].begin(),A[i].end(),cmp);
	for(int i=1;i<=tl;++i){
		suf[i].resize(size[i]+1);
	//	printf("%d : (%d) \n",i,size[i]);
		for(int j=size[i]-1;j>=0;j--)
			suf[i][j]=suf[i][j+1]+f[A[i][j]];
		//for(int v:A[i]) printf("%d ",v);puts("");
	}
//	for(int i=1;i<=n;++i) printf("%d ",f[i]);puts("");
	while(q--){
		int a,b;
		scanf("%lld%lld",&a,&b);
		a=vis[a];b=vis[b];
		if(a==b) {puts("-1");continue;}
		if(size[a]>size[b])std::swap(a,b);
		if (rec[a].find(b)!=rec[a].end()){printf("%.8f\n",rec[a][b]);continue;}
	//	printf(">%d %d\n",a,b);
		ll sum = size[a] * size[b];
		ll now = 0;
		ll tot = 0;
		int d = std::max ( diam[a], diam[b] );
		for (int i : A[a]) {
			int l = 0, r = A[b].size()-1, ans = A[b].size();
			while (l <= r) {
				int mid = (l+r) >> 1;
				if (f[A[b][mid]] + f[i] + 1 <= d) l=mid+1;
				else {ans = mid; r = mid - 1;}
			} 
			int cnt = A[b].size() - ans;
		//	printf("-> %d %lld\n",cnt,suf[b][ans]);
			tot += (ll)cnt * (f[i] + 1) + (ans < A[b].size() ? suf[b][ans] : 0);
			now += cnt;
		} assert(sum >= now); 
		tot += (sum - now) * d;
		double answ =  tot / (double) sum;
		rec[a][b] = rec[b][a] = answ;
		//printf("%lld / %lld\n",tot,sum);
		printf("%.8f\n",answ);
	} return 0;
}