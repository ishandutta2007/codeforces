#include<bits/stdc++.h>
using namespace std;
const int maxn=5010,maxm=2e5+10;
int hea[maxn],nxt[maxm],to[maxm],f[maxn],A[maxn],B[maxn],C[maxn],col[maxn],pre[maxn][maxn],cnt,tot,n;
int read() {
	int x=0;
	char ch=getchar();
	for(;ch<'0'||ch>'1';ch=getchar());
	for(;ch>='0'&&ch<='1';ch=getchar())
		x=x*10+(ch^48);
	return x;
}
void add(int a,int b) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
}
void dfs(int x,int t) {
	f[x]=t;
	if(t)A[cnt]++;
	else B[cnt]++;
	for(int i=hea[x];i;i=nxt[i])
		if(!~f[to[i]])dfs(to[i],t^1);
		else if(f[to[i]]!=(t^1))puts("NO"),exit(0);
}
void dfs1(int x,int n) {
	if(!x)return;
	if(pre[x][n]!=n)C[x]^=1;
	dfs1(x-1,pre[x][n]);
}
void color(int x,int t) {
	col[x]=t;
	for(int i=hea[x];i;i=nxt[i])
		if(!~col[to[i]])color(to[i],t^1);
}
signed main() {
	int n,m,n1,n2,n3,a,b,c=0;
	scanf("%d%d",&n,&m);
	scanf("%d%d%d",&n1,&n2,&n3);
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	memset(f,-1,sizeof(f));
	memset(col,-1,sizeof(col));
	memset(pre,-1,sizeof(pre));
	pre[0][0]=0;
	for(int i=1;i<=n;i++)
		if(!~f[i])++cnt,dfs(i,0);
	for(int i=1;i<=cnt;i++) {
		if(A[i]<B[i])swap(A[i],B[i]),C[i]^=1;
		int a=A[i]-B[i];
		n2-=B[i];
		for(int j=n;j>=0;j--)
			if(~pre[i-1][j])pre[i][j]=j;
		for(int j=n;j>=a;j--)
			if(~pre[i-1][j-a])pre[i][j]=j-a;
	}
	if(n1<0||!~pre[cnt][n2])return puts("NO"),0;
	puts("YES");
	dfs1(cnt,n2);
	for(int i=1;i<=n;i++)
		if(!~col[i])color(i,C[++c]);
	for(int i=1;i<=n;i++) {
		if(col[i]==0)putchar('2');
		else if(n1>0)putchar('1'),n1--;
		else putchar('3');
	}
	puts("");
	return 0;
}