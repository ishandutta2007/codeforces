#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x=0;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+(ch^48);
	return x;
}
const int maxn=210,maxm=25000,inf=0x3f3f3f3f;
int hea[maxn],cur[maxn],nxt[maxm],to[maxm],w[maxm],a[maxn],d[maxn],q[maxn],tot,f[20010],S,T;
int bfs() {
	int h=1,e=1;
	memset(d,0,sizeof(d));
	q[1]=S,d[S]=1;
	while(h<=e) {
		int x=q[h++];
		for(int i=hea[x];i;i=nxt[i])
			if(w[i]&&!d[to[i]])
				d[q[++e]=to[i]]=d[x]+1;
	}
	return d[T];
}
int dfs(int x,int f) {
	if(x==T)return f;
	int sum=0;
	for(int &i=cur[x];i&&f;i=nxt[i])
		if(w[i]&&d[to[i]]==d[x]+1) {
			int t=dfs(to[i],min(w[i],f));
			w[i]-=t;
			w[i^1]+=t;
			sum+=t;
			f-=t;
		}
	return sum;
}
inline void ins(int a,int b,int c) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
	w[tot]=c;
}
inline void add(int a,int b,int c) {
	ins(a,b,c);
	ins(b,a,0);
}
int H[maxn],N[maxn<<1],To[maxn<<1],cnt;
inline void ins(int a,int b) {
	N[++cnt]=H[a];
	H[a]=cnt;
	To[cnt]=b;
}
inline void add(int a,int b) {
	ins(a,b);
	ins(b,a);
}
vector<int>A[70];
int Sum;
void dfs(int x) {
	A[Sum].push_back(x);
	f[x]=1;
	for(int i=H[x];i;i=N[i])
		if(!f[To[i]])dfs(To[i]);
}
int main() {
	for(int i=2;i*i<=20000;i++)
		if(!f[i])
			for(int j=i;j*i<=20000;j++)
				f[i*j]=1;
	tot=1;
	int n=read();
	S=n+1,T=S+1;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
		if(a[i]&1) {
			add(S,i,2);
			for(int j=1;j<=n;j++)
				if(!f[a[i]+a[j]])add(i,j,1);
		}
		else add(i,T,2);
	int ans=0;
	while(bfs()) {
		memcpy(cur,hea,sizeof(cur));
		ans+=dfs(S,inf);
	}
	if(ans==n) {
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
			if(a[i]&1)
				for(int j=hea[i];j;j=nxt[j])
					if(to[j]<=n&&!w[j])add(i,to[j]);
		//UKE
		for(int i=1;i<=n;i++)
			if(!f[i])
				Sum++,dfs(i);
		printf("%d\n",Sum);
		for(int i=1;i<=Sum;i++) {
			cout<<A[i].size()<<' ';
			for(int j=0;j<int(A[i].size()-1);j++)
				printf("%d ",A[i][j]);
			printf("%d\n",*A[i].rbegin());
		}
	} else puts("Impossible");
	return 0;
}