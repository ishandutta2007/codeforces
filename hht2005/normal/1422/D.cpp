#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pii;
#define mp make_pair
const int maxn=1e5+10,maxm=4e6+10;
struct node {
	int x,y,id;
}p[maxn];
int cmp1(const node &a,const node &b) {
	return a.x<b.x;
}
int cmp2(const node &a,const node &b) {
	return a.y<b.y;
}
int cmp3(const node &a,const node &b) {
	return a.id<b.id;
}
int hea[maxn],nxt[maxm],to[maxm],w[maxm],dis[maxn],f[maxn],tot;
void ins(int a,int b,int c) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
	w[tot]=c;
}
void add(int a,int b,int c) {
	ins(a,b,c);
	ins(b,a,c);
}
priority_queue<pii,vector<pii>,greater<pii> >q;
signed main() {
	int n,m,sx,sy,tx,ty;
	scanf("%lld%lld",&n,&m);
	scanf("%lld%lld%lld%lld",&sx,&sy,&tx,&ty);
	for(int i=1;i<=m;i++) {
		scanf("%lld%lld",&p[i].x,&p[i].y);
		p[i].id=i;
	}
	sort(p+1,p+m+1,cmp1);
	for(int i=1;i<m;i++)add(p[i].id,p[i+1].id,min(abs(p[i].x-p[i+1].x),abs(p[i].y-p[i+1].y)));
	sort(p+1,p+m+1,cmp2);
	for(int i=1;i<m;i++)add(p[i].id,p[i+1].id,min(abs(p[i].x-p[i+1].x),abs(p[i].y-p[i+1].y)));
	sort(p+1,p+m+1,cmp3);
	for(int i=1;i<=m;i++) {
		dis[i]=min(abs(p[i].x-sx),abs(p[i].y-sy));
		q.push(mp(dis[i],i));
	}
	while(!q.empty()) {
		pii t=q.top();
		q.pop();
		if(f[t.second])continue;
		f[t.second]=1;
		for(int i=hea[t.second];i;i=nxt[i])
			if(dis[to[i]]>t.first+w[i]) {
				dis[to[i]]=t.first+w[i];
				q.push(mp(dis[to[i]],to[i])); 
			}
	}
	int ans=abs(tx-sx)+abs(ty-sy);
	for(int i=1;i<=m;i++)
		ans=min(ans,dis[i]+abs(tx-p[i].x)+abs(ty-p[i].y));
	printf("%lld\n",ans);
	return 0;
}