#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
typedef pair<long long,long long> pii;
vector<pii>S[N];
int cnt,id[N][2];
long long dis[N];
priority_queue<pii,vector<pii>,greater<pii> >q;
void add(int a,int b,int w) {
	S[a].push_back(make_pair(b,w));
}
void build(int p,int l,int r,int f) {
	if(l==r) {
		id[p][f]=++cnt;
		if(f==0)add(cnt,l,0);
		else add(l,cnt,0);
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid,f);
	build(p<<1|1,mid+1,r,f);
	id[p][f]=++cnt;
	if(f==0) {
		add(cnt,id[p<<1][f],0);
		add(cnt,id[p<<1|1][f],0);
	} else {
		add(id[p<<1][f],cnt,0);
		add(id[p<<1|1][f],cnt,0);
	}
}
void add(int p,int l,int r,int x,int y,int u,int w,int f) {
	if(x<=l&&r<=y) {
		if(f==0)add(u,id[p][f],w);
		else add(id[p][f],u,w);
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(p<<1,l,mid,x,y,u,w,f);
	if(y>mid)add(p<<1|1,mid+1,r,x,y,u,w,f);
}
int main() {
	memset(dis,0x3f,sizeof(dis));
	int n,m,s,op,x,l,r,w;
	scanf("%d%d%d",&n,&m,&s);
	cnt=n;
	dis[s]=0;
	build(1,1,n,0);
	build(1,1,n,1);
	while(m--) {
		scanf("%d%d%d",&op,&x,&l);
		if(op!=1)scanf("%d",&r);
		scanf("%d",&w);
		if(op==1)add(x,l,w);
		else add(1,1,n,l,r,x,w,op-2);
	}
	q.push(make_pair(0,s));
	while(!q.empty()) {
		pii t=q.top();
		q.pop();
		int x=t.second;
		if(dis[x]>t.first)continue;
		for(pii y:S[x])
			if(dis[y.first]>dis[x]+y.second)
				q.push(make_pair(dis[y.first]=dis[x]+y.second,y.first));
	}
	for(int i=1;i<=n;i++)
		printf("%lld ",dis[i]>1e18?-1:dis[i]);
	puts("");
	return 0;
}