#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N 200050
typedef long long ll;
int n,m,tp,f[20][N];
struct A {
	int l,r;
	bool operator < (const A &u) const {
		return l==u.l ? r>u.r : l<u.l;
	}
}a[N],S[N];
int v[N];
int main() {
	scanf("%d%d",&n,&m);
	int i;
	for(i=1;i<=n;i++) scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++) {
		if(a[i].r>S[tp].r) S[++tp]=a[i];
	}
	n=tp;
	for(i=1;i<=n;i++) a[i]=S[i],v[i]=a[i].l;
	int j=1;
	for(i=1;i<=n;i++) {
		for(;j<n && a[j+1].l<=a[i].r;j++);
		if(i!=j && a[j].l<=a[i].r) f[0][i]=j;
	}
	for(i=1;(1<<i)<=n;i++) for(j=1;j<=n;j++) f[i][j]=f[i-1][f[i-1][j]];
	while(m--) {
		int x,y;
		scanf("%d%d",&x,&y);
		int k=upper_bound(v+1,v+n+1,x)-v-1,ans=1;
		if(!k) {puts("-1"); continue;}

		x=k;
		for(i=19;i>=0;i--) {
			if(f[i][x] && a[f[i][x]].r<y) x=f[i][x],ans+=(1<<i);
		}
		if(a[x].r < y) {
			x=f[0][x];
			if(x && a[x].r>=y) ans++;
			else {
				puts("-1"); continue;
			}
		}
		printf("%d\n",ans);
	}
}