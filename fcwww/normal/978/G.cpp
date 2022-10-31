#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double f2;
#define N 250
#define M 100050
#define S (n+m+1)
#define T (n+m+2)
#define inf 100000000
int head[N],to[M],nxt[M],cnt=1,flow[M],dep[N],Q[N],l,r,is[N],s[N],d[N],c[N],n,m,sum;
inline void add(int u,int v,int f) {
    to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt; flow[cnt]=f;
    to[++cnt]=u; nxt[cnt]=head[v]; head[v]=cnt; flow[cnt]=0;
}
bool bfs() {
    memset(dep,0,sizeof(dep));
    int i; l=r=0; Q[r++]=S; dep[S]=1;
    while(l<r) {
        int x=Q[l++];
        for(i=head[x];i;i=nxt[i]) {
            if(!dep[to[i]]&&flow[i]) {
                dep[to[i]]=dep[x]+1;
                if(to[i]==T) return 1;
                Q[r++]=to[i];
            }
        }
    }
    return 0;
}
int dfs(int x,int mf) {
    // puts("fgvfiugv");
    if(x==T) return mf;
    int i,nf=0;
    for(i=head[x];i;i=nxt[i]) {
        if(dep[to[i]]==dep[x]+1&&flow[i]) {
            int tmp=dfs(to[i],min(mf-nf,flow[i]));
            //if(!tmp) dep[to[i]]=0;
            nf+=tmp;
            flow[i]-=tmp;
            flow[i^1]+=tmp;
            if(nf==mf) break;
        }
    }
    return nf;
}
void dinic() {
	int f,ans=0;
	while(bfs()) {
		while(f=dfs(S,inf)) ans+=f;
	}
	if(ans!=sum) puts("-1");
	else {
		int i,j;
		for(i=1;i<=n;i++) {
			if(is[i]) {
				printf("%d ",m+1);
			}else {
				int flg=n;
				for(j=head[i];j;j=nxt[j]) {
					if(to[j]!=S) {
						if(flow[j]==0) {
							flg=to[j]; break;
						}
					}
				}
				printf("%d ",flg-n);
			}
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=m;i++) {
		scanf("%d%d%d",&s[i],&d[i],&c[i]);
		is[d[i]]=1;
		add(i+n,T,c[i]);
		sum+=c[i];
	}
	for(i=1;i<=n;i++) {
		if(is[i]) continue;
		add(S,i,1);
		for(j=1;j<=m;j++) {
			if(s[j]<=i&&d[j]>i) {
				add(i,j+n,1);
			}
		}
	}
	dinic();
}