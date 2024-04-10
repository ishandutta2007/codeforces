#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+10;
int hea[maxn],nxt[maxn],to[maxn],c[maxn],sk[maxn],top,tot;
void add(int a,int b) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
}
int main() {
	int T,n,m,x,y;
	scanf("%d",&T);
	while(T--) {
		tot=top=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)c[i]=hea[i]=0;
		for(int i=1;i<=m;i++) {
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		for(int i=1;i<=n;i++) {
			for(int j=hea[i];j;j=nxt[j]) {
				if(c[i]==1)c[to[j]]=2;
				if(c[i]==0&&c[to[j]]!=2)c[to[j]]=1;
			}
		}
		for(int i=1;i<=n;i++)
			if(c[i]==2)sk[++top]=i;
		printf("%d\n",top);
		for(int i=1;i<=top;i++)
			printf("%d ",sk[i]);
		puts("");
	}
	return 0;
}