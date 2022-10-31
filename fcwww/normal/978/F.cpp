#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double f2;
#define N 200050
int head[N],to[N<<1],nxt[N<<1],cnt,n,m,pos[N],ans[N];
inline void add(int u,int v) {
	to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt;
}
struct A {
	int v,id;
}a[N];
bool cmp(const A &x,const A &y) {
	return x.v<y.v;
}
int main() {
	scanf("%d%d",&n,&m);
	int i,x,y,j;
	for(i=1;i<=n;i++) {
		scanf("%d",&a[i].v),a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++) {
		pos[a[i].id]=i;
	}
	for(i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	int now=0;
	a[0].v=-1;
	for(i=1;i<=n;i++) {
		int re=now;
		x=a[i].id;
		if(a[i].v!=a[now+1].v) {
			re=i-1; now=i-1;
		}
		for(j=head[x];j;j=nxt[j]) {
			int tmp=pos[to[j]];
			if(a[tmp].v<a[i].v) re--;
		}
		ans[a[i].id]=re;
	}
	for(i=1;i<=n;i++) printf("%d ",ans[i]);
}