#include<bits/stdc++.h>
using namespace std;
#define fl fwrite(o_str,1,top,stdout),top=0
const int MAXL=1<<22;
char i_str[MAXL],*i_s,*i_t;
inline char gc() {
	if(i_s==i_t) {
		i_s=i_str;
		i_t=i_s+fread(i_str,1,MAXL,stdin);
		return i_s==i_t?EOF:*i_s++;
	} else return *i_s++;
}
inline int read() {
	int x=0,f=0;
	char ch=gc();
	for(;ch<'0'||ch>'9';ch=gc())
		if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=gc())
		x=(x<<1)+(x<<3)+(ch^48);
	return f?-x:x;
}
const int maxn=2e5+10;
int hea[maxn],nxt[maxn<<1],to[maxn<<1],q[maxn],dis[maxn][3],h,e,tot;
long long p[maxn];
void add(int a,int b) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
}
void bfs(int S,int t) {
	dis[S][t]=0;
	q[h=e=1]=S;
	while(h<=e) {
		int x=q[h++];
		for(int i=hea[x];i;i=nxt[i])
			if(!~dis[to[i]][t])
				dis[q[++e]=to[i]][t]=dis[x][t]+1;
	}
}
int main() {
	int T=read();
	while(T--) {
		int n=read(),m=read(),a=read(),b=read(),c=read();
		long long ans=1e16;
		for(int i=1;i<=n;i++) {
			dis[i][0]=dis[i][1]=dis[i][2]=-1;
			hea[i]=0;
		}
		tot=0;
		for(int i=1;i<=m;i++)
			p[i]=read();
		sort(p+1,p+m+1);
		for(int i=1;i<=m;i++)
			p[i]=p[i-1]+p[i];
		for(int i=1;i<=m;i++) {
			int a=read(),b=read();
			add(a,b);
			add(b,a);
		}
		bfs(a,0);
		bfs(b,1);
		bfs(c,2);
		for(int i=1;i<=n;i++) {
			int A=dis[i][0],B=dis[i][1],C=dis[i][2];
			if(A+B+C>m)continue;
			ans=min(ans,p[B]+p[A+B+C]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}