#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N 100050
int n,a[N],root[N],t[N*20],ls[N*20],rs[N*20],lst[N],pre[N],cnt;
void insert(int l,int r,int v,int &y,int x) {
	y=++cnt; t[y]=t[x]+1;
	if(l==r) return ;
	int mid=(l+r)>>1;
	if(v<=mid) rs[y]=rs[x],insert(l,mid,v,ls[y],ls[x]);
	else ls[y]=ls[x],insert(mid+1,r,v,rs[y],rs[x]);
}
int query(int l,int r,int v,int x,int y) {
	if(l==r) return l<=v?t[x]-t[y]:0;
	int mid=(l+r)>>1;
	if(v<=mid) return query(l,mid,v,ls[x],ls[y]);
	else return query(mid+1,r,v,rs[x],rs[y])+t[ls[x]]-t[ls[y]];
}
bool judge(int l,int r,int K) {
	return query(0,n,l-1,root[r],root[l-1])<=K;
}
int solve(int K) {
	int i,re=0;
	for(i=1;i<=n;) {
		int j=min(i+K-1,n),p;
		for(p=1;j+p<=n&&judge(i,j+p,K);p<<=1) ;
		for(p>>=1;p;p>>=1) if(j+p<=n&&judge(i,j+p,K)) j+=p;
		i=j+1; re++;
	}
	return re;
}
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) {
		scanf("%d",&a[i]); if(lst[a[i]]) pre[i]=lst[a[i]]; lst[a[i]]=i;
		root[i]=root[i-1]; insert(0,n,pre[i],root[i],root[i]);
	}
	for(i=1;i<=n;i++) {
		printf("%d ",solve(i));
	}
	// while(1) {
	// 	int x,y;
	// 	scanf("%d%d",&x,&y);
	// 	printf("%d\n",query(0,n,x-1,root[y],root[x-1]));
	// }
}