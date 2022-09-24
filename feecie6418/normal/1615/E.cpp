#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,h[200005],cnt,son[200005],top[200005],p[200005];
ll a[200005],len[200005],s[200005];
struct Edge {
	int to,next;
} e[400005];
void Add_Edge(int x,int y) {
	e[++cnt].to=y;
	e[cnt].next=h[x];
	h[x]=cnt;
}
void DFS1(int now,int fa) {
	for(int i=h[now]; i; i=e[i].next) {
		int y=e[i].to;
		if(y==fa)continue;
		DFS1(y,now);
		if(len[y]>len[now])len[now]=len[y],son[now]=y;
	}
	len[now]+=p[now];
}
void DFS2(int now,int fa,ll sum) {
	sum+=p[now];
	if(son[now])DFS2(son[now],now,sum);
	else a[++a[0]]=sum;
	for(int i=h[now]; i; i=e[i].next) {
		int y=e[i].to;
		if(y==fa||y==son[now])continue;
		DFS2(y,now,0);
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)p[i]=1;
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),Add_Edge(x,y),Add_Edge(y,x);
	DFS1(1,0);
	DFS2(1,0,0);
	sort(a+1,a+a[0]+1);
	for(int i=a[0];i>=1;i--)s[i]=a[i]+s[i+1];
	ll ans=-1e18;
	for(int i=1;i<=m;i++){
		ll rr=i,b=n-s[max(1ll,a[0]-i+1)];
		ll l=0,r=b;
		while(r-l>50){
			ll m1=(l+l+r)/3,m2=(l+r+r)/3;
			if((rr-m1)*(n-rr-m1)<(rr-m2)*(n-rr-m2))r=m2;
			else l=m1;
		}
		ll mn=1e18;
		for(ll j=l;j<=r;j++)mn=min(mn,(rr-j)*(n-rr-j));
		ans=max(ans,mn);
	}
	cout<<ans;
}