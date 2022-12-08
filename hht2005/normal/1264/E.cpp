#include<bits/stdc++.h>
using namespace std;
const int maxn=10110,maxm=100010,inf=0x3f3f3f3f;
int hea[maxn],nxt[maxm],to[maxm],w[maxm];
int dis[maxn],pre[maxn],f[maxn],q[maxn*200],sumw,h,e,S,T,tot;
long long sumc,c[maxm];
inline int read() {
	int x=0,f=0;
	char ch=getchar();
	for(; ch<'0'||ch>'9'; ch=getchar())
		if(ch=='-')f=1;
	for(; ch>='0'&&ch<='9'; ch=getchar())
		x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
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
		memset(dis,0x3f,sizeof(dis));
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
		int mi=inf;
		for(int i=T;i!=S;i=to[pre[i]^1])mi=min(w[pre[i]],mi);
		for(int i=T;i!=S;i=to[pre[i]^1])w[pre[i]]-=mi,w[pre[i]^1]+=mi,sumc+=mi*c[pre[i]];
		sumw+=mi;
	}
}
int mp[110][110];
int main() {
	tot=1;
	int n=read(),m=read(),cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			mp[i][j]=2;
	for(int i=1;i<=m;i++) {
		int a=read(),b=read();
		mp[a][b]=1;
		mp[b][a]=0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			if(mp[i][j]==2)cnt++;
	S=n+cnt+1,T=S+1;
	cnt=n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++) {
			if(mp[i][j]==0)add(S,j,1,0);
			if(mp[i][j]==1)add(S,i,1,0);
			if(mp[i][j]==2) {
				add(S,++cnt,1,0);
				add(cnt,i,1,0);
				add(cnt,j,1,0);
			}
		}
	for(int i=1;i<=n;i++)
		for(int j=0;j<n-1;j++)
			add(i,T,1,j);
	EK();
	cnt=n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++) {
			if(mp[i][j]!=2)continue;
			int f=0;
			for(int k=hea[++cnt];k;k=nxt[k])
				if(to[k]==i&&!w[k])f=1;
			mp[i][j]=f;
			mp[j][i]=f^=1;
		}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<n;j++)
			printf("%d",mp[i][j]);
		printf("%d\n",mp[i][n]);
	}
	return 0;
}