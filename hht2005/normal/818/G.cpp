#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=100010,inf=0x3f3f3f3f;
int hea[N],nxt[M],to[M],dis[N],pre[N],f[N],q[N*200],h,e,S,T,tot;
long long sumw,sumc,w[M],c[M];
inline void ins(int a,int b,int ww,int cc) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
	w[tot]=ww;
	c[tot]=cc;
}
inline void add(int a,int b,int ww,int cc) {
	ins(a,b,ww,cc);
	ins(b,a,0,-cc);
}
void EK() {
	while(1) {
		memset(dis,inf,sizeof(dis));
		dis[S]=0;
		q[h=e=1]=S;
		while(h<=e) {
			int x=q[h++];
			f[x]=0;
			for(int i=hea[x]; i; i=nxt[i]) {
				if(w[i]&&dis[to[i]]>dis[x]+c[i]) {
					dis[to[i]]=dis[x]+c[i];
					pre[to[i]]=i;
					if(!f[to[i]]) {
						f[to[i]]=1;
						q[++e]=to[i];
					}
				}
			}
		}
		if(dis[T]>=inf)break;
		long long mi=inf;
		for(int i=T;i!=S;i=to[pre[i]^1])mi=min(w[pre[i]],mi);
		for(int i=T;i!=S;i=to[pre[i]^1])w[pre[i]]-=mi,w[pre[i]^1]+=mi,sumc+=mi*c[pre[i]];
		sumw+=mi;
	}
}
int las[N],t[7];
int main() {
	tot=1;
	int n,a=0;
	scanf("%d",&n);
	S=n*4+2;
	T=S+1;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a);
		if(las[a])add(las[a]+2*n,i+2*n,inf,0);
		if(t[a%7])add(t[a%7]+3*n,i+3*n,inf,0);
		add(4*n+1,i,1,0);
		add(i+n,T,1,0);
		add(i,i+n,1,-1);
		add(i+n,i+2*n,1,0);
		add(i+n,i+3*n,1,0);
		if(t[a%7])add(t[a%7]+3*n,i,1,0);
		if(las[a-1])add(las[a-1]+2*n,i,1,0);
		if(las[a+1])add(las[a+1]+2*n,i,1,0);
		las[a]=i;
		t[a%7]=i;
	}
	add(S,S-1,4,0);
	EK();
	printf("%lld\n",-sumc);
	return 0;
}