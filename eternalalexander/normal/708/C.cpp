#include <bits/stdc++.h>
#define maxn 400005

int ch[maxn<<5][2],sum[maxn<<5],size[maxn],dfn[maxn],ref[maxn],fa[maxn],rep[maxn],
root[maxn],vis[maxn],n,rt,u,v,idx,tl;
std::vector<int>E[maxn];

void get_rt(int u,int f){
	int max = 0;
	size[u] = 1;
	for(int v:E[u]){
		if (v==f)continue;
		get_rt(v,u);
		size[u] += size[v];
		max = std::max(max,size[v]);
	}max = std::max(max, n - size[u]);
	if (max <= n/2) rt = u;
}

void dfs(int u,int f,int rp = 0){
	fa[u] = f; dfn[u] = ++idx; 
	ref[idx] = u; size[u] = 1;
	rep[u] = rp;
	for (int v:E[u]) {
		if (v == f) continue;
		dfs(v,u,rp?rp:v);
		size[u] += size[v];
	}
}

void update(int x) { sum[x] = sum[ch[x][0]] + sum[ch[x][1]]; }

int insert(int l,int r,int p,int rt,int nrt) {
	if (!nrt) nrt = ++tl;
	ch[nrt][0] = ch[rt][0]; ch[nrt][1] = ch[rt][1];
	sum[nrt] = sum[rt] + 1;
	if (l == r) return nrt;
	int mid = (l+r)>>1;
	if (p <= mid) ch[nrt][0] = insert(l,mid,p,ch[rt][0],0);
	else ch[nrt][1] = insert(mid+1,r,p,ch[rt][1],0);
	update(nrt);
	return nrt;
}

int qry(int l,int r,int L,int R,int rt){
	if(l>R||r<L||!rt)return 0;
	if (l<=L&&R<=r)return sum[rt];
	return qry(l,r,L,(L+R)>>1,ch[rt][0]) + qry(l,r,((L+R)>>1)+1,R,ch[rt][1]);
}

int query(int vl,int vr,int l,int r){
	return qry(vl,vr,1,n,root[r]) - qry(vl,vr,1,n,root[l-1]);
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<n;++i) {
		scanf("%d%d",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}get_rt(1,0); vis[rt] = 1;
	dfs(rt,0);
	for (int i = 1; i <= n; ++ i) 
		root[i] = insert(1,n,size[ref[i]],root[i-1],0);
	for (int i = 1; i <= n; ++ i) {
		if (i == rt) continue;
		int lb = (n - size[i]) - (n/2);
		if (size[rep[i]] == n - size[rep[i]] || query(lb,n,2,dfn[rep[i]] - 1) || query(lb,n,dfn[rep[i]] + size[rep[i]], n))
			vis[i] = 1;
	}for (int i = 1; i <= n; ++ i) printf("%d ",vis[i]);
	return 0;
}