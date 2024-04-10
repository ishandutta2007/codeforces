#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,q,a[100005],b[100005],l,r;
struct node{
	long long sum,lMin,rMin,lMax,rMax,Min,Max;
}t[400005];
node merge(node a,node b){
	node c;c.sum=a.sum+b.sum;
	c.lMin=min(a.lMin,a.sum+b.lMin);
	c.lMax=max(a.lMax,a.sum+b.lMax);
	c.rMin=min(b.rMin,b.sum+a.rMin);
	c.rMax=max(b.rMax,b.sum+a.rMax);
	c.Min=min(min(a.Min,b.Min),a.rMin+b.lMin);
	c.Max=max(max(a.Max,b.Max),a.rMax+b.lMax);
	return c;
}
void build(int k,int l,int r){
	if(l==r){
		t[k].sum=b[l]-a[l];
		t[k].lMin=min(0ll,t[k].sum);
		t[k].rMin=min(0ll,t[k].sum);
		t[k].Min=min(0ll,t[k].sum);
		t[k].lMax=max(0ll,t[k].sum);
		t[k].rMax=max(0ll,t[k].sum);
		t[k].Max=max(0ll,t[k].sum);
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	t[k]=merge(t[k<<1],t[k<<1|1]);
}
node query(int k,int l,int r,int L,int R){
	if(L<=l&&r<=R)return t[k];
	int mid=l+r>>1;
	if(R<=mid)return query(k<<1,l,mid,L,R);
	if(L>mid)return query(k<<1|1,mid+1,r,L,R);
	return merge(query(k<<1,l,mid,L,R),query(k<<1|1,mid+1,r,L,R));
}
int main(){
	n=read();q=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)b[i]=read();
	build(1,1,n);
	for(int i=1;i<=q;++i){
		l=read();r=read();
		node now=query(1,1,n,l,r);
		if(now.sum==0&&now.lMin==0){
			cout<<max(abs(now.Max),abs(now.Min))<<"\n";
		}
		else puts("-1");
	}
	return 0;
}