#include<bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;const int N=2e5+7;
int n,m,p,i,j,a[N],ca[N],b[N],cb[N],d[N],tot,mx[N<<2],tag[N<<2],ida[N],x[N],y[N],z[N],id[N];long long ans=-3e9;
bool cmp(int x,int y){return a[x]<a[y];}
bool cmp1(int a,int b){return x[a]<x[b];}
void add(int rt,int val){tag[rt]+=val;mx[rt]+=val;}
void pushdown(int rt){if(tag[rt])add(lson,tag[rt]),add(rson,tag[rt]),tag[rt]=0;}
void add(int rt,int l,int r,int pos,int val){
	mx[rt]=max(mx[rt],val);if(l==r)return;int mid=l+r>>1;
	pos<=mid?add(lson,l,mid,pos,val):add(rson,mid+1,r,pos,val);
}
void modify(int rt,int l,int r,int a,int b,int val){
	if(a>b)return;
	if(a<=l&&r<=b)return add(rt,val);int mid=l+r>>1;pushdown(rt);
	if(a<=mid)modify(lson,l,mid,a,b,val);if(b>mid)modify(rson,mid+1,r,a,b,val);mx[rt]=max(mx[lson],mx[rson]);
}
int main(){
	for(i=0;i<N*4;++i)mx[i]=-2e9;
	for(scanf("%d%d%d",&n,&m,&p),i=1;i<=n;++i)scanf("%d%d",a+i,ca+i),ida[i]=i;sort(ida+1,ida+n+1,cmp);
	for(i=1;i<=m;++i)scanf("%d%d",b+i,cb+i),d[i]=b[i];sort(d+1,d+m+1);tot=unique(d+1,d+m+1)-d-1;
	for(i=1;i<=m;++i)add(1,1,tot,lower_bound(d+1,d+tot+1,b[i])-d,-cb[i]);
	for(i=1;i<=p;++i)scanf("%d%d%d",x+i,y+i,z+i),id[i]=i;sort(id+1,id+p+1,cmp1);
	for(j=i=1;i<=n;++i){
		while(x[id[j]]<a[ida[i]]&&j<=p)modify(1,1,tot,upper_bound(d+1,d+tot+1,y[id[j]])-d,tot,z[id[j]]),++j;
		ans=max(ans,1LL*mx[1]-ca[ida[i]]);
	}printf("%lld\n",ans);
}