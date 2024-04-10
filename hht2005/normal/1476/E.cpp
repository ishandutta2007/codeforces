#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
char s[6],t[6];
int tr[maxn*4][27],mt[maxn],en[maxn*4],q[maxn],h,e,deg[maxn],tot,n,m,k;
int hea[maxn],nxt[maxn*60],to[maxn*60],tot1;
void ins(int x) {
	int p=1;
	for(int i=1;i<=k;i++) {
		int t=s[i]=='_'?26:s[i]-'a';
		if(!tr[p][t])tr[p][t]=++tot;
		p=tr[p][t];
	}
	en[p]=x;
}
int qry() {
	int p=1;
	for(int i=1;i<=k;i++) {
		int t=s[i]=='_'?26:s[i]-'a';
		p=tr[p][t];
	}
	if(!p)return 0;
	return en[p];
}
void add(int a,int b) {
	deg[b]++;
	nxt[++tot1]=hea[a];
	hea[a]=tot1;
	to[tot1]=b;
}
int main() {
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) {
		scanf("%s",s+1);
		ins(i);
	}
	for(int i=1;i<=m;i++) {
		scanf("%s%d",t+1,mt+i);
		int FL=0;
		for(int j=0;j<1<<k;j++) {
			memcpy(s,t,sizeof(s));
			for(int l=0;l<k;l++)
				if(j>>l&1)s[l+1]='_';
			int t=qry();
			if(!t)continue;
			if(t==mt[i])FL=1;
			else add(mt[i],t);
		}
		if(!FL)return puts("NO"),0;
	}
	h=1,e=0;
	for(int i=1;i<=n;i++)
		if(!deg[i])q[++e]=i;
	while(h<=e) {
		int x=q[h++];
		for(int i=hea[x];i;i=nxt[i])
			if(!--deg[to[i]])
				q[++e]=to[i];
	}
	if(e<n)return puts("NO"),0;
	puts("YES");
	for(int i=1;i<=n;i++)
		printf("%d ",q[i]);
	puts("");
	return 0;
}