#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=N*20;
using ll=long long;
int hea[N],cur[N],nxt[M],to[M],d[N],q[N],S,T,tot=1;
ll w[M];
void ins(int a,int b,ll c) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
	w[tot]=c;
}
void add(int a,int b,ll c) {
	ins(a,b,c);
	ins(b,a,0);
}
int bfs() {
	memset(d,0,sizeof(d));
	int h=1,e=1;
	d[q[1]=S]=1;
	while(h<=e) {
		int x=q[h++];
		for(int i=hea[x];i;i=nxt[i])
			if(w[i]&&!d[to[i]])
				d[q[++e]=to[i]]=d[x]+1;
	}
	return d[T];
}
ll dfs(int x,ll f) {
	if(x==T)return f;
	ll sum=0;
	for(int &i=cur[x];i&&f;i=nxt[i])
		if(w[i]&&d[x]+1==d[to[i]]) {
			ll t=dfs(to[i],min(f,w[i]));
			w[i]-=t,w[i^1]+=t;
			sum+=t,f-=t;
		}
	return sum;
}
int a[N],t[N];
int main() {
	int T_T,n;
	scanf("%d",&T_T);
	while(T_T--) {
		scanf("%d",&n);
		int m=0;
		S=4*n+1,T=S+1;
		hea[S]=hea[T]=0;
		tot=1;
		for(int i=1;i<=n;i++) {
			scanf("%d",a+i);
			t[a[i]]=i;
			m=max(m,a[i]);
		}
		for(int i=1;i<=n;i++) {
			hea[i]=hea[i+n]=hea[i+2*n]=hea[i+3*n]=0;
			add(S,i,1);
			add(S,i+n,1);
			add(i+2*n,T,1);
			add(i+3*n,T,1);
		}
		for(int i=1;i<=n;i++) {
			add(i,i+3*n,1);
			for(int j=2*a[i];j<=m;j+=a[i]) {
				if(!t[j])continue;
				add(i,t[j]+2*n,1);
				add(i,t[j]+3*n,1);
				add(i+n,t[j]+3*n,1);
			}
		}
		int ans=2*n;
		while(bfs()) {
			memcpy(cur,hea,sizeof(hea));
			ans-=dfs(S,1e9);
		}
		printf("%d\n",n-ans);
		for(int i=1;i<=n;i++)
			t[a[i]]=0;
	}
	return 0;
}