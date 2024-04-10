#include<bits/stdc++.h>
using namespace std;
#define N 300020
typedef long long ll;
int n,Q,a[N],w[N];
ll ans[N];
int l[N],r[N];
vector<pair<int,int> > q[N];
vector<int> c[N];
inline ll calc(int x,int y){
	return 1LL*(a[y]-a[x])*(w[x]+w[y]);
}
ll mn[N<<2];
#define ls u<<1
#define rs u<<1|1
void Change(int u,int L,int R,int p,ll d){
	if(L==R){
		mn[u]=min(mn[u],d);
		return;
	}
	int mid=(L+R)>>1;
	p<=mid?Change(ls,L,mid,p,d):Change(rs,mid+1,R,p,d);
	mn[u]=min(mn[ls],mn[rs]);
}
ll Query(int u,int L,int R,int l,int r){
	if(L>=l&&R<=r)return mn[u];
	ll ans=3e18;
	int mid=(L+R)>>1;
	if(l<=mid)ans=min(ans,Query(ls,L,mid,l,r));
	if(r>mid)ans=min(ans,Query(rs,mid+1,R,l,r));
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>w[i];
	}
	for(int i=1;i<=n;++i){
		static int st[N],top;
		while(top&&w[i]<w[st[top]])--top;
		l[i]=st[top];
		st[++top]=i;
	}
	for(int i=n;i>=1;--i){
		static int st[N],top;
		while(top&&w[i]<w[st[top]])--top;
		r[i]=st[top];
		st[++top]=i;
	}
	for(int i=1;i<=n;++i){
		if(l[i])c[i].push_back(l[i]);
		if(r[i])c[r[i]].push_back(i);
	}
	for(int i=1;i<=Q;++i){
		int l,r;
		cin>>l>>r;
		q[r].emplace_back(l,i);
	}
	memset(mn,0x3f,sizeof(mn));
	for(int i=1;i<=n;++i){
		for(auto j:c[i]){
			Change(1,1,n,j,calc(j,i));
		}
		for(auto [j,id]:q[i]){
			ans[id]=Query(1,1,n,j,i);
		}
	}
	for(int i=1;i<=Q;++i){
		cout<<ans[i]<<'\n';
	}
	return 0;
}