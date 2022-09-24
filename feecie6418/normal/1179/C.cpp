#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m,q,mn[4000005],tag[4000005],a[300005],b[300005];
void Tag(int x,int z){
	tag[x]+=z,mn[x]+=z;
}
void Pushdown(int p){
	if(tag[p])Tag(p*2,tag[p]),Tag(p*2+1,tag[p]),tag[p]=0;
}
void Add(int p,int l,int r,int x,int y,int z){
	if(x<=l&&r<=y)return Tag(p,z),void();
	Pushdown(p);
	int mid=(l+r)>>1;
	if(x<=mid)Add(p*2,l,mid,x,y,z);
	if(mid<y)Add(p*2+1,mid+1,r,x,y,z);
	mn[p]=min(mn[p*2],mn[p*2+1]);
}
int Find(int p,int l,int r){
	if(l==r)return l;
	Pushdown(p);
	int mid=(l+r)/2;
	if(mn[p*2+1]<0)return Find(p*2+1,mid+1,r);
	return Find(p*2,l,mid);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),Add(1,1,N,1,a[i],-1);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]),Add(1,1,N,1,b[i],1);
	scanf("%d",&q);
	while(q--){
		int opt,x,y;
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==1)Add(1,1,N,1,a[x],1),a[x]=y,Add(1,1,N,1,a[x],-1);
		else Add(1,1,N,1,b[x],-1),b[x]=y,Add(1,1,N,1,b[x],1);
		if(mn[1]<0)printf("%d\n",Find(1,1,N));
		else puts("-1");
	}
	return 0;
}