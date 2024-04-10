#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define N 200050
int n,m,fa[N],flg[N];
struct E {int x,y,z;bool operator<(const E &u)const {return z>u.z;}}e[N];
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
int main() {
	int i,ans=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) fa[i]=i;
	for(i=1;i<=m;i++) scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
	sort(e+1,e+m+1);
	for(i=1;i<=m;i++) {
		int dx=find(e[i].x),dy=find(e[i].y);
		if(flg[dx]&&flg[dy]) continue;
		ans+=e[i].z;
		fa[dy]=dx;
		if(dx==dy||flg[dy]) flg[dx]=1;
	}
	printf("%d\n",ans);
}