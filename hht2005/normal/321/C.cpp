#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int hea[N],nxt[N<<1],to[N<<1],siz[N],f[N],size,rt,minn,tot;
char s[N];
void fason(int a,int b) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
}
void getroot(int x,int fa) {
	siz[x]=1;
	int mx=0;
	for(int i=hea[x],y;(y=to[i]);i=nxt[i]) {
		if(y==fa||f[y])continue;
		getroot(y,x);
		siz[x]+=siz[y];
		mx=max(mx,siz[y]);
	}
	mx=max(mx,size-siz[x]);
	if(minn>mx) {
		minn=mx;
		rt=x;
	}
}
void dfs(int x,char ch) {
	s[x]=ch;
	f[x]=1;
	int tsiz=size;
	for(int i=hea[x],y;(y=to[i]);i=nxt[i]) {
		if(f[y])continue;
		size=siz[x]>siz[y]?siz[y]:tsiz-siz[x];
		minn=1e9;
		getroot(y,0);
		dfs(rt,ch+1);
	}
}
int main() {
	int a,b,n;
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		scanf("%d%d",&a,&b);
		fason(a,b);
		fason(b,a);
	}
	minn=1e9;
	size=n;
	getroot(1,0);
	dfs(rt,'A');
	for(int i=1;i<=n;i++)
		printf("%c ",s[i]);
	puts("");
	return 0;
}