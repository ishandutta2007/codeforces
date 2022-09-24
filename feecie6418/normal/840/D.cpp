#include<bits/stdc++.h>
using namespace std;
int cnt,s[6000005],ls[6000005],rs[6000005],a[300005],b[300005],n,m,root[300005];
int Insert(int l,int r,int x,int v){
	int y=++cnt;
	s[y]=s[x]+1;
	if(l==r)return y;
	ls[y]=ls[x],rs[y]=rs[x];
	int mid=(l+r)/2;
	if(v<=mid)ls[y]=Insert(l,mid,ls[x],v);
	else rs[y]=Insert(mid+1,r,rs[x],v);
	return y;
}
int Query(int l,int r,int x,int y,int k){
	if(s[y]-s[x]<=k)return -1;
	if(l==r)return l;
	int mid=(l+r)/2,t;
	if((t=Query(l,mid,ls[x],ls[y],k))!=-1)return t;
	if((t=Query(mid+1,r,rs[x],rs[y],k))!=-1)return t;
	else return -1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),root[i]=Insert(1,n,root[i-1],a[i]);
	for(int i=1,x,y,k;i<=m;i++)scanf("%d%d%d",&x,&y,&k),printf("%d\n",Query(1,n,root[x-1],root[y],(y-x+1)/k));
}