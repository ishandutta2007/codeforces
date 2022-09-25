#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define N 400020
typedef long long ll;
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> T[N<<1];
int n,Q,a[N],b[N],f[N],ch[N][2],L[N],R[N],cnt,rt,_l[N],_r[N],siz[N];
ll ans,jb[N][2];
#define ls ch[u][0]
#define rs ch[u][1]
int dfs(int p,int l,int r){
	if(l>r){T[l].insert(a[l]);_l[l]=l,_r[l]=r+1;siz[l]=1;return l;}
	int u=++cnt;
	ls=dfs(L[p],l,p-1);
	rs=dfs(R[p],p+1,r);
	f[ls]=f[rs]=u;
	siz[u]=siz[ls]+siz[rs];
	_l[u]=l,_r[u]=r+1;
	for(int i=_l[u];i<=_r[u];++i)T[u].insert(a[i]);
	for(int i=_l[ls];i<=_r[ls];++i)jb[u][0]+=T[rs].order_of_key(a[i]);
	for(int i=_l[rs];i<=_r[rs];++i)jb[u][1]+=T[ls].order_of_key(a[i]);
	ans+=min(jb[u][0],jb[u][1]);
	return u;
}
void Change(int u,int x,int w){
	int v=0;
	while(u){
		if(w==1)T[u].insert(x);
		else T[u].erase(x);
		if(v){
			int k=ch[u][1]==v;
			ans-=min(jb[u][0],jb[u][1]);
			int d=T[ch[u][k^1]].order_of_key(x);
			jb[u][k]+=w*d;
			jb[u][k^1]+=w*(siz[ch[u][k^1]]-d);
			ans+=min(jb[u][0],jb[u][1]);
		}
		v=u;
		siz[u]+=w;
		u=f[u];
	}	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];	
	}
	for(int i=1;i<n;++i){
		cin>>b[i];
	}
	cin>>Q;
	static int st[N],top;
	for(int i=1;i<n;++i){
		while(top&&b[i]<b[st[top]])L[i]=st[top--];
		if(top)R[st[top]]=i;
		st[++top]=i;
	}
	cnt=n;
	rt=dfs(st[1],1,n-1);
	while(Q--){
		int x,y;
		cin>>x>>y;
		Change(x,a[x],-1);
		Change(y,a[y],-1);
		swap(a[x],a[y]);
		Change(x,a[x],1);
		Change(y,a[y],1);
		cout<<ans<<'\n';
	}
	return 0;
}