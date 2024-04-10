#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <vector>
using namespace std;
typedef long long ll;
#define N 105000
int n,m,du[N],head[N],to[N<<1],nxt[N<<1],cnt,val[N<<1],xx[N],yy[N],zz[N];
int a1[N],a2[N],a3[N],t;
inline void add(int u,int v,int w) {
	to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt; val[cnt]=w;
}
void dfs(int x,int y,int &pp) {
	int i;
	if(du[x]==1 && !pp) {
		pp=x;
	}
	for(i=head[x];i;i=nxt[i]) if(to[i]!=y) {
		dfs(to[i],x,pp);
	}
}
int main() {
	scanf("%d",&n);
	int i,x,y,z;
	for(i=1;i<n;i++) scanf("%d%d%d",&x,&y,&z),xx[i]=x,yy[i]=y,zz[i]=z,du[x]++,du[y]++,add(x,y,z),add(y,x,z);
	for(i=1;i<=n;i++) if(du[i]==2) return puts("NO"),0;
	puts("YES");
	for(i=1;i<n;i++) {
		x=xx[i],y=yy[i],z=zz[i];
		int p1=0,p2=0,p3=0,p4=0;
		if(du[x]==1) {
			p1=x;
			p2=x;
		}else {
			int j;
			for(j=head[x];j;j=nxt[j]) {
				if(to[j]!=y) {
					if(!p1) {
						dfs(to[j],x,p1);
					}else if(!p2) {
						dfs(to[j],x,p2);
					}
				}
			}
		}
		if(du[y]==1) {
			p3=p4=y;
		}else {
			int j;
			for(j=head[y];j;j=nxt[j]) {
				if(to[j]!=x) {
					if(!p3) {
						dfs(to[j],y,p3);
					}else if(!p4){
						dfs(to[j],y,p4);
					}
				}
			}
		}
		a1[++t]=p1;
		a2[t]=p3;
		a3[t]=z>>1;
		a1[++t]=p2;
		a2[t]=p4;
		a3[t]=z>>1;
		if(p1!=p2) {
			a1[++t]=p1;
			a2[t]=p2;
			a3[t]=-(z>>1);
		}
		if(p3!=p4) {
			a1[++t]=p3;
			a2[t]=p4;
			a3[t]=-(z>>1);
		}
	}
	printf("%d\n",t);
	for(i=1;i<=t;i++) printf("%d %d %d\n",a1[i],a2[i],a3[i]);
}