#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+10,maxm=5e5,inf=0x3f3f3f3f;
int hea[maxn],nxt[maxm],to[maxm],w[maxm],cur[maxn],d[maxn],q[maxn],S,T,tot,n,m;
void ins(int a,int b,int c) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
	w[tot]=c;
}
void add(int a,int b,int c) {
	ins(a,b,c);
	ins(b,a,0);
}
int dfs(int x,int f) {
	if(x==T)return f;
	int sum=0;
	for(int &i=cur[x];i&&f;i=nxt[i])
		if(d[to[i]]==d[x]+1&&w[i]) {
			int t=dfs(to[i],min(f,w[i]));
			w[i]-=t,w[i^1]+=t;
			sum+=t,f-=t;
		}
	return sum;
}
int bfs() {
	int H=1,E=1;
	memset(d,0,sizeof(d));
	d[q[H=E=1]=S]=1;
	while(H<=E) {
		int x=q[H++];
		for(int i=hea[x];i;i=nxt[i])
			if(w[i]&&!d[to[i]])
				d[q[++E]=to[i]]=d[x]+1;
	}
	return d[T];
}
int a[maxm],b[maxm],c[maxm];
int check(int mid) {
	S=n<<1|1,T=S+1;
	tot=1;
	memset(hea,0,sizeof(hea));
	for(int i=1;i<=n;i++)
		add(S,i,1),add(i+n,T,1);
	for(int i=1;i<=m;i++)
		if(c[i]<=mid)add(a[i],b[i]+n,1);
	int sum=0;
	while(bfs()) {
		memcpy(cur,hea,sizeof(cur));
		sum+=dfs(S,inf);
	}
	return sum==n;
}
int main() {
	int L=1e9,R=0,fl=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",a+i,b+i,c+i);
		L=min(L,c[i]);
		R=max(R,c[i]);
	}
	while(L<=R) {
		int mid=(L+R)>>1;
		if(check(mid))R=mid-1,fl=1;
		else L=mid+1;
	}
	if(fl)printf("%d\n",R+1);
	else puts("-1");
	return 0;
}