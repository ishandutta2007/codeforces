#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring> 
using namespace std;
struct Edge{
	int to,next;
}e[200005];
int cnt,h[100005],n,m,val[100005],to[100005],ccnt[100005],fk[100005],st[100005],ed[100005];
int vp[100005],sign,ans[100005],L[100005],R[100005],bel[100005],cntt[100005],ALL;
struct Query{
	int l,r,k,id;
	bool operator <(const Query yy) const {
		return bel[l]==bel[yy.l]?r<yy.r:bel[l]>bel[yy.l];
	}
}q[100005];
void Add_Edge(int x,int y) {
	e[++cnt].next=h[x];
	e[cnt].to=y;
	h[x]=cnt;
}
void DFS(int now,int fa){
	L[now]=++sign,vp[sign]=val[now];
	for(int i=h[now];i;i=e[i].next){
		int y=e[i].to;
		if(y^fa)DFS(y,now);
	}
	R[now]=sign;
}
void Add(int x){
	ccnt[cntt[vp[x]]]--;
	fk[bel[cntt[vp[x]]]]--;
	cntt[vp[x]]++;
	ccnt[cntt[vp[x]]]++;
	fk[bel[cntt[vp[x]]]]++;
}
void Del(int x){
	ccnt[cntt[vp[x]]]--;
	fk[bel[cntt[vp[x]]]]--;
	cntt[vp[x]]--;
	ccnt[cntt[vp[x]]]++;
	fk[bel[cntt[vp[x]]]]++;
}
int Query(int k){
	int ret=0;
	for(int i=k;i<=ed[bel[k]];i++)ret+=ccnt[i];
	for(int i=bel[k]+1;i<=ALL;i++)ret+=fk[i];
	return ret;
}
int main() {
	scanf("%d%d",&n,&m);
	int blk=sqrt(n);
	ALL=n/blk;
	for(int i=1;i<=ALL;i++){
		st[i]=(i-1)*blk+(i!=1),ed[i]=(i==ALL?n:i*blk);
		for(int j=st[i];j<=ed[i];j++)bel[j]=i;
	}
	for(int i=1,tot=0;i<=n;i++){
		scanf("%d",&val[i]);
		if(to[val[i]])val[i]=to[val[i]];
		else to[val[i]]=++tot,val[i]=to[val[i]];
	}
	
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y),Add_Edge(x,y),Add_Edge(y,x);
	}
	DFS(1,0);
	for(int i=1,x;i<=m;i++)scanf("%d%d",&x,&q[i].k),q[i].l=L[x],q[i].r=R[x],q[i].id=i;
	sort(q+1,q+m+1);
	int l=1,r=0;
	ccnt[0]=n;
	for(int i=1;i<=m;i++){
		while(l<q[i].l)Del(l++);
		while(r>q[i].r)Del(r--);
		while(l>q[i].l)Add(--l);
		while(r<q[i].r)Add(++r);
		ans[q[i].id]=Query(q[i].k);
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}