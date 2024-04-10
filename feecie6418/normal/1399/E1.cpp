#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct E {
	int to,w,c;
};
struct P {
	ll w,id;
	bool operator <(const P p) const {
		return w<p.w;
	}
};
int n,w[100005],c[100005],size[100005],ans=1e9;
ll s,ans1[2000005],ans2[2000005],sum=0,c1=0,c2=0;
vector<E> g[100005];
priority_queue<P> q[3];
void dfs(int x,int fa,ll dis) {
	if(g[x].size()==1&&x!=1)size[x]=1,sum+=dis;
	for(E i:g[x]) {
		int y=i.to;
		if(y==fa)continue;
		w[y]=i.w,c[y]=i.c,dfs(y,x,dis+i.w),size[x]+=size[y];
		q[c[y]].push({1ll*(w[y]-w[y]/2)*size[y],y});
	}
}
void Solve() {
	scanf("%d%lld",&n,&s);
	for(int i=1,x,y,z,w; i<n; i++) {
		scanf("%d%d%d",&x,&y,&z),w=1;
		g[x].push_back({y,z,w}),g[y].push_back({x,z,w});
	}
	dfs(1,0,0);
	while(1) {
		if(!q[1].size())break;
		P a=q[1].top();
		if(!a.w)break;
		q[1].pop(),ans1[c1+1]=ans1[c1]+a.w,c1++;
		int x=a.id;
		w[x]/=2,q[1].push({1ll*(w[x]-w[x]/2)*size[x],x});
	}
	while(1) {
		if(!q[2].size())break;
		P a=q[2].top();
		if(!a.w)break;
		q[2].pop(),ans2[c2+1]=ans2[c2]+a.w,c2++;
		int x=a.id;
		w[x]/=2,q[2].push({1ll*(w[x]-w[x]/2)*size[x],x});
	}
	for(int i=0,j=c2; i<=c1; i++) {
		while(j>0&&ans1[i]+ans2[j-1]>=sum-s)j--;
		if(ans1[i]+ans2[j]>=sum-s)ans=min(ans,i+j*2);
	}
	cout<<ans<<'\n';
}
void Clear() {
	sum=c1=c2=0,ans=1e9;
	while(q[1].size())q[1].pop();
	while(q[2].size())q[2].pop();
	for(int i=1; i<=n; i++)g[i].clear(),size[i]=0;
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--)Solve(),Clear();
	return 0;
}