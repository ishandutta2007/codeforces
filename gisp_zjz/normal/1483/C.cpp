#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef double db;
const int M=998244353;
const int maxn=1e6+10;
int a[maxn],d[maxn],p[maxn],L[maxn],R[maxn],n,mn[maxn][20];
ll v[maxn],dpl[maxn],dpr[maxn],dp[maxn],dplr[maxn];
int qry(int l,int r){
	int x=d[r-l+1];
	return min(mn[l][x],mn[r-(1<<x)+1][x]);
}
int build(int l,int r){
	if (l>r) return 0;
    int v=p[qry(l,r)];
    L[v]=build(l,v-1);
    R[v]=build(v+1,r);
    return v;
}
void work(int u){
	if (L[u]) work(L[u]);
	if (R[u]) work(R[u]);
    dpr[u]=dpr[R[u]]+max(0ll,v[u]+dplr[L[u]]);
    dpl[u]=dpl[L[u]]+max(0ll,v[u]+dplr[R[u]]);
    dplr[u]=max(max(dplr[L[u]],dplr[R[u]]),v[u]+dplr[L[u]]+dplr[R[u]]);
    dp[u]=v[u]+dpl[L[u]]+dpr[R[u]];
}
int main(){
	scanf("%d",&n);
	for (int i=2;i<=n;i++) d[i]=d[i/2]+1;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		p[a[i]]=i; mn[i][0]=a[i];
	}
	for (int i=1;i<=n;i++) scanf("%lld",&v[i]);
    for (int i=1;i<20;i++)
		for (int j=1;j+(1<<i)-1<=n;j++)
			mn[j][i]=min(mn[j][i-1],mn[j+(1<<(i-1))][i-1]);
    int rt=build(1,n);
    work(rt);
	printf("%lld\n",dp[rt]);
	return 0;
}