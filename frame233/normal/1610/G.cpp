#include<bits/stdc++.h>
const int N=300005,mod=1000350647,base=2333;typedef long long ll;
char s[N];int f[N][20],g[N][20],st[N],top,nxt[N],pw[N];
void link(int x,int y,int c){
	f[x][0]=y,g[x][0]=c;
	for(int i=1;i<20;++i)f[x][i]=f[f[x][i-1]][i-1];
	for(int i=1;i<20;++i)g[x][i]=(1LL*g[f[x][i-1]][i-1]*pw[1<<(i-1)]+g[x][i-1])%mod;
}
bool cmp(int x,int y){
	for(int i=19;i>=0;--i)if(f[x][i]&&f[y][i]&&g[x][i]==g[y][i])x=f[x][i],y=f[y][i];
	return g[x][0]<g[y][0];
}
int main(){
	pw[0]=1;for(int i=1;i<N;++i)pw[i]=1LL*pw[i-1]*base%mod;
	scanf("%s",s+1);int n=strlen(s+1);
	for(int i=n;i>=1;--i){
		if(s[i]=='('){if(top)nxt[i]=st[top--]+1;}
		else st[++top]=i;
	}
	f[n+1][0]=n+2,g[n+1][0]=1;
	for(int i=n;i>=1;--i){
		link(i,i+1,s[i]);
		if(nxt[i]&&cmp(nxt[i],i))link(i,f[nxt[i]][0],g[nxt[i]][0]);
	}
	for(int u=1;u<=n;u=f[u][0])if(g[u][0]>1)printf("%c",g[u][0]);
	printf("\n");
	return 0;
}