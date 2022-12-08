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
const int maxn=1e5+10;
int hea[maxn],nxt[maxn<<2],to[maxn<<2],f[maxn][2],go[maxn][2],c[maxn],in[maxn][2],flag,tot;
void add(int a,int b) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
}
int dfs(int x,int t) {
	if(!c[x])return t;
	if(~f[x][t])return f[x][t];
	in[x][t]=1;
	for(int i=hea[x];i;i=nxt[i])
		if(in[to[i]][t^1])flag=1;
		else if(dfs(to[i],t^1)) {
			f[x][t]=1;
			go[x][t]=to[i];
		}
	in[x][t]=0;
	return f[x][t]=(f[x][t]==1);
}
int main() {
	memset(f,-1,sizeof(f));
	int n=read();read();
	for(int i=1;i<=n;i++) {
		c[i]=read();
		for(int j=1;j<=c[i];j++)
			add(i,read());
	}
	int s=read();
	dfs(s,0);
	if(f[s][0]==1) {
		puts("Win");
		for(int t=0;c[s];s=go[s][t],t^=1)printf("%d ",s);
		printf("%d\n",s);
	} else if(flag)puts("Draw");
	else puts("Lose");
	return 0;
}