#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,m,tot,a[N],b[N];pair<int,int>p[N];
bool ok(int mid){
	rep(i,1,n)b[i]=0;
	int ls=tot,k=0,nw=0;
	rep(i,1,m){
		if(p[i].fr>mid)break;
		b[p[i].sc]=i;
	}
	rep(i,1,m){
		if(p[i].fr>mid)break;
		if(b[p[i].sc]!=i)continue;
		k+=p[i].fr-nw;nw=p[i].fr;
		int py=min(a[p[i].sc],k);
		ls-=py;k-=py;
	}
	return nw+max(ls*2-k,0)<=mid;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%d",&a[i]);tot+=a[i];
	}
	rep(i,1,m)scanf("%d%d",&p[i].fr,&p[i].sc);
	sort(p+1,p+m+1);int l=0,r=tot*2,mid=(l+r)>>1;
	for(;l<r;mid=(l+r)>>1)if(ok(mid))r=mid;else l=mid+1;
	printf("%d\n",mid);
}