#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
typedef pair<int,int> pii;
#define mp make_pair
#define v first
#define x second
int hea[maxn],nxt[maxn*100],to[maxn*100],w[maxn*100],dis[maxn*100],f[maxn],tot;
void add(int a,int b,int c) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
	w[tot]=c;
}
priority_queue<pii,vector<pii>,greater<pii> >q;
int main() {
	memset(dis,0x3f,sizeof(dis));
	int n,m,x,s;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)add(i,i+1,1),add(i+1,i,0);
	for(int i=1; i<=n; i++) {
		scanf("%d%d",&x,&s);
		for(int i=0;i<=s&&x-i>=1;i++)add(x-i,min(x+s,m)+1,0);
		for(int i=s+1;x-i>=1&&x+i<=m;i++)add(x-i,x+i+1,i-s);
	}
	q.push(mp(0,1));
	while(!q.empty()) {
		pii t=q.top();
		q.pop();
		int x=t.x,v=t.v;
		if(f[x])continue;
		f[x]=1;
		for(int i=hea[x]; i; i=nxt[i])
			if(dis[to[i]]>v+w[i]) {
				dis[to[i]]=v+w[i];
				q.push(mp(dis[to[i]],to[i]));
			}
	}
	printf("%d\n",dis[m+1]);
	return 0;
}