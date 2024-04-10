#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef pair<int,int> pii;
typedef long long ll;
int n,f[N],rt,siz[N],ans[N],s[N];
pii mn[N],mx[N],se[N];
vector<int> G[N];
inline void Ins(int u,pii tmp){
	if(tmp>mx[u])se[u]=mx[u],mx[u]=tmp;
	else se[u]=max(tmp,se[u]);
	mn[u]=min(mn[u],tmp);
}
void dfs1(int u){
	siz[u]=1;
	mn[u]=make_pair(n+1,n);
	for(auto v:G[u]){
		dfs1(v);
		siz[u]+=siz[v];
		Ins(u,make_pair(siz[v],v));
	}
}
class Segment_Tree{
	int cnt;
	struct node{
		int ch[2],siz;
	}t[N<<5];
	#define ls t[u].ch[0]
	#define rs t[u].ch[1]
public:
	int rt[N];
	void Insert(int &u,int L,int R,int x,int w){
		if(!u){u=++cnt;}
		t[u].siz+=w;
		if(L==R)return;
		int mid=(L+R)>>1;
		x<=mid?Insert(ls,L,mid,x,w):Insert(rs,mid+1,R,x,w);
	}
	void Merge(int &u,int v,int L,int R){
		if(!u||!v){u|=v;return;}
		int mid=(L+R)>>1;
		t[u].siz+=t[v].siz;
		Merge(ls,t[v].ch[0],L,mid);
		Merge(rs,t[v].ch[1],mid+1,R);
	}
	int QueryL1(int u,int L,int R,int lim){
		if(!u||!t[u].siz)return -1;
		if(L==R)return L;
		int mid=(L+R)>>1;
		if(lim<=mid)return QueryL1(ls,L,mid,lim);
		int tmp=QueryL1(rs,mid+1,R,lim);
		if(~tmp)return tmp;
		return QueryL1(ls,L,mid,lim);
	}
	int QueryL2(int u,int v,int L,int R,int lim){
		if(!(s[R]-s[max(0,L-1)]-t[u].siz-t[v].siz))return -1;
		if(L==R)return L;
		int mid=(L+R)>>1;
		if(lim<=mid)return QueryL2(ls,t[v].ch[0],L,mid,lim);
		int tmp=QueryL2(rs,t[v].ch[1],mid+1,R,lim);
		if(~tmp)return tmp;
		return QueryL2(ls,t[v].ch[0],L,mid,lim);	
	}
	int QueryR1(int u,int L,int R,int lim){
		if(!u||!t[u].siz)return n+1;
		if(L==R)return L;
		int mid=(L+R)>>1;
		if(lim>mid)return QueryR1(rs,mid+1,R,lim);
		int tmp=QueryR1(ls,L,mid,lim);
		if(tmp<=n)return tmp;
		return QueryR1(rs,mid+1,R,lim);
	}
	int QueryR2(int u,int v,int L,int R,int lim){
		if(!(s[R]-s[max(0,L-1)]-t[u].siz-t[v].siz))return n+1;
		if(L==R)return L;
		int mid=(L+R)>>1;
		if(lim>mid)return QueryR2(rs,t[v].ch[1],mid+1,R,lim);
		int tmp=QueryR2(ls,t[v].ch[0],L,mid,lim);
		if(tmp<=n)return tmp;
		return QueryR2(rs,t[v].ch[1],mid+1,R,lim);
	}
}T;
void dfs2(int u){
	T.Insert(T.rt[0],0,n,siz[u],1);
	int lim=mx[u].first-mn[u].first;
	for(auto v:G[u]){
		dfs2(v);
		if(mx[u].second==v){
			int tl=T.QueryL1(T.rt[v],0,n,lim/2);
			int tr=T.QueryR1(T.rt[v],0,n,(lim+1)/2);
			ans[u]=max(min(mn[u].first+tr,mx[u].first-max(0,tl)),se[u].first);
		}
		T.Merge(T.rt[u],T.rt[v],0,n);
	}
	T.Insert(T.rt[u],0,n,siz[u],1);
	T.Insert(T.rt[0],0,n,siz[u],-1);
	if(mx[u].second==f[u]){
		int jbl=T.QueryL2(T.rt[u],T.rt[0],0,n,lim/2);
		int jbr=T.QueryR2(T.rt[u],T.rt[0],0,n,(lim+1)/2);
		int tl=T.QueryL1(T.rt[0],0,n,lim/2+siz[u])-siz[u];
		int tr=T.QueryR1(T.rt[0],0,n,(lim+1)/2+siz[u])-siz[u];
		ans[u]=max(min(mn[u].first+min(tr,jbr),mx[u].first-max(0,max(tl,jbl))),se[u].first);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		int u,v;
		cin>>u>>v;
		f[v]=u;
		if(!u)rt=v;
		if(u)G[u].push_back(v);
	}
	dfs1(rt);
	for(int i=1;i<=n;++i){
		if(i==rt)continue;
		Ins(i,make_pair(n-siz[i],f[i]));
	}
	for(int i=1;i<=n;++i){
		++s[siz[i]];
	}
	for(int i=1;i<=n;++i)s[i]+=s[i-1];
	dfs2(rt);
	for(int i=1;i<=n;++i){
		cout<<ans[i]<<'\n';
	}
	return 0;
}