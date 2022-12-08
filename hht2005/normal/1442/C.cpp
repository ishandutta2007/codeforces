#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+10,mod=998244353;
int hea[maxn],nxt[maxn<<3],to[maxn<<3],w[maxn<<3],dis[maxn],dis2[maxn],dis3[maxn][25],f2[maxn][25],f[maxn],q[maxn],h,e,tot;
int A[maxn],B[maxn];
struct node {
	int x,k,v;
	node(int xx,int kk,int vv) {
		x=xx,k=kk,v=vv;
	}
	int operator <(const node &a)const {
		return v>a.v;
	}
};
priority_queue<node>q2;
void add(int a,int b,int c) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
	w[tot]=c;
}
void push_b(int x) {
	q[e++]=x;
	if(e==maxn)e=0;
}
void push_f(int x) {
	if(h==0)h=maxn;
	q[--h]=x;
}
void pop() {
	h++;
	if(h==maxn)h=0;
}
int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		scanf("%d%d",A+i,B+i);
		add(A[i],B[i],0);
		add(A[i]+n,B[i],1);
		add(B[i]+n,A[i]+n,0);
		add(B[i],A[i]+n,1);
	}
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	push_f(1);
	while(h!=e) {
		int x=q[h];
		pop();
		if(f[x])continue;
		f[x]=1;
		for(int i=hea[x];i;i=nxt[i])
			if(dis[to[i]]>dis[x]+w[i]) {
				dis[to[i]]=dis[x]+w[i];
				if(w[i]==1)push_b(to[i]);
				if(w[i]==0)push_f(to[i]);
			}
	}
	h=e=0;
	memset(dis2,-1,sizeof(dis2));
	dis2[1]=0;
	push_b(1);
	while(h!=e) {
		int x=q[h];
		pop();
		for(int i=hea[x];i;i=nxt[i])
			if(dis[to[i]]==dis[x]+w[i]&&dis2[to[i]]==-1) {
				dis2[to[i]]=dis2[x]+1;
				push_b(to[i]);
			}
	}
	int ans=1e9;
//	if(n==200000&&m==200000)cout<<ans<<endl;
	memset(hea,tot=0,sizeof(hea));
	for(int i=1;i<=m;i++) {
		add(A[i],B[i],0);
		add(B[i],A[i],1);
	}
	memset(dis3,0x3f,sizeof(dis3));
	dis3[1][0]=0;
	q2.push(node(1,0,0));
	while(!q2.empty()) {
		node t=q2.top();
		q2.pop();
		int x=t.x,k=t.k;
		if(f2[x][k])continue;
		f2[x][k]=1;
		for(int i=hea[x];i;i=nxt[i]) {
			int ww=w[i]^(k&1);
			if(ww==1&&k>=20)continue;
			if(dis3[to[i]][k+ww]>dis3[x][k]+1+(ww<<k)) {
				dis3[to[i]][k+ww]=dis3[x][k]+1+(ww<<k);
				q2.push(node(to[i],k+ww,dis3[to[i]][k+ww]));
			}
		}
	}
	for(int i=0;i<=20;i++)ans=min(ans,dis3[n][i]);
	int K=1e9,V=1e9;
	if(dis[n]!=-1)K=dis[n],V=dis2[n];
	if(dis[2*n]!=-1&&K>=dis[2*n]) {
		if(K==dis[2*n])V=min(V,dis2[2*n]);
		else V=dis2[2*n];
		K=dis[2*n];
	}
	if(ans>mod)ans=(qpow(2,K)+V-1)%mod;
	printf("%d\n",ans);
	return 0;
}