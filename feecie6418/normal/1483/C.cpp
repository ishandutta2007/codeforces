#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[300005],b[300005],top,st[300005];
ll f[300005],tag[1200005];
struct P{
	ll mxf,mxs;
}t[1200005];
P operator +(P a,P b){
	return {max(a.mxf,b.mxf),max(a.mxs,b.mxs)};
}
void Build(int p,int l,int r){
	tag[p]=-2e9;
	if(l==r)return t[p]={(ll)-1e18,(ll)-1e18},void();
	int mid=(l+r)/2;
	Build(p*2,l,mid),Build(p*2+1,mid+1,r);
}
void Tag(int p,ll x){
	tag[p]=x,t[p].mxs=t[p].mxf+x;
}
void Pushdown(int p){
	if(tag[p]!=-2e9)Tag(p*2,tag[p]),Tag(p*2+1,tag[p]),tag[p]=-2e9;
}
void Make(int p,int l,int r,int x,int y,ll z){
	if(x<=l&&r<=y)return Tag(p,z),void();
	Pushdown(p);
	int mid=(l+r)/2;
	if(x<=mid)Make(p*2,l,mid,x,y,z);
	if(mid<y)Make(p*2+1,mid+1,r,x,y,z);
	t[p]=t[p*2]+t[p*2+1];
}
void Set(int p,int l,int r,int x,ll y){
	if(l==r)return t[p]={y,y},void();
	Pushdown(p);
	int mid=(l+r)/2;
	if(x<=mid)Set(p*2,l,mid,x,y);
	else Set(p*2+1,mid+1,r,x,y);
	t[p]=t[p*2]+t[p*2+1];
}
P Query(int p,int l,int r,int x,int y){
	if(x<=l&&r<=y)return t[p];
	Pushdown(p);
	int mid=(l+r)/2;
	if(x>mid)return Query(p*2+1,mid+1,r,x,y);
	if(y<=mid)return Query(p*2,l,mid,x,y);
	return Query(p*2,l,mid,x,y)+Query(p*2+1,mid+1,r,x,y);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	Build(1,1,n),Set(1,1,n,1,0);
	for(int i=1;i<=n;i++){
		while(top&&a[st[top]]>a[i])top--;
		Make(1,1,n,st[top]+1,i,b[i]);
		f[i]=Query(1,1,n,1,i).mxs;
		if(i<n)Set(1,1,n,i+1,f[i]);
		st[++top]=i;
	}
	cout<<f[n];
}