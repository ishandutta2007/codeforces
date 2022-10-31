#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
#define N 3050
vector<int>V[N];
int n,m,p[N],c[N],a[N],la;
ll ans=1ll<<60;
void check(int x) {
	la=0;
	int i,cnt=V[1].size(),j; ll re=0;
	for(i=2;i<=m;i++) {
		int lim=V[i].size();
		int l=0;
		if(lim>x) {
			l=lim-x;
		}
		for(j=0;j<l;j++) re+=V[i][j],cnt++;
		for(j=l;j<lim;j++) a[++la]=V[i][j];
	}
	sort(a+1,a+la+1);
	int lft=x+1-cnt;
	if(lft>la) return ;
	for(i=1;i<=lft;i++) re+=a[i];
	ans=min(ans,re);
}
int main() {
	scanf("%d%d",&n,&m);
	int i,mx=0;
	for(i=1;i<=n;i++) scanf("%d%d",&p[i],&c[i]),V[p[i]].push_back(c[i]);
	for(i=1;i<=m;i++) sort(V[i].begin(),V[i].end()),mx=max(mx,int(V[i].size()));
	for(i=0;i<=mx;i++) {
		check(i);
	}
	printf("%lld\n",ans);
}