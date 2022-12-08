#include<bits/stdc++.h>
using namespace std;
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
char s[1010][1010];
int f[1000010],c[1010][1010],q[1000010],h,e,d[1000010],cnt;
int hea[1000010],nxt[6000010],to[6000010],tot;
void ins(int a,int b) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
}
void add(int a,int b) {
	ins(a,b);
	ins(b,a);
}
void dfs(int x,int y) {
	c[x][y]=cnt;
	f[cnt]++;
	for(int i=0;i<4;i++) {
		int xx=x+dx[i],yy=y+dy[i];
		if(!c[xx][yy]&&s[xx][yy]==s[x][y])dfs(xx,yy);
	}
}
signed main() {
	int n,m,t,a,b;
	long long p;
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!c[i][j])cnt++,dfs(i,j);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) {
			if(i>1&&c[i-1][j]!=c[i][j])add(c[i-1][j],c[i][j]);
			if(j>1&&c[i][j-1]!=c[i][j])add(c[i][j-1],c[i][j]);
		}
	memset(d,-1,sizeof(d));
	h=1;
	for(int i=1;i<=cnt;i++)
		if(f[i]>1)d[q[++e]=i]=0;
	while(h<=e) {
		int x=q[h++];
		for(int i=hea[x];i;i=nxt[i])
			if(!~d[to[i]])d[q[++e]=to[i]]=d[x]+1;
	}
	while(t--) {
		scanf("%d%d%lld",&a,&b,&p);
		if(!~d[c[a][b]]||p<d[c[a][b]])printf("%c\n",s[a][b]);
		else printf("%c\n",char(s[a][b]^((p-d[c[a][b]])%2)));
	}
	return 0;
}