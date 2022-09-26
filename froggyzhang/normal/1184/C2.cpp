#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 600010
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
struct rec{
	int x,l,r;
	int type;
}a[N];
struct node{
	int i,l,r,mx,add;
	void Add(int d){
		mx+=d;
		add+=d;
	}
}tree[N<<2];
int b[N],c;
int n,m,ans;

bool cmp(rec a,rec b){
	return a.x<b.x||a.x==b.x&&a.type<b.type;
}
void update(int i){
	tree[i].mx=max(tree[i*2].mx,tree[i*2+1].mx);
}
void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	tree[i].mx=tree[i].add=0;
	if(l==r){
		return;
	}
	int mid=(l+r)>>1;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
}

void pushdown(int i){
	if(tree[i].add){
		tree[i*2].Add(tree[i].add);
		tree[i*2+1].Add(tree[i].add);
		tree[i].add=0;
	}
}

void change(int i,int l,int r,int d){
	if(l<=tree[i].l&&r>=tree[i].r){
		tree[i].Add(d);
		return;
	}
	pushdown(i);
	int mid=(tree[i].l+tree[i].r)>>1;
	if(l<=mid){
		change(i*2,l,r,d);
	}
	if(r>mid){
		change(i*2+1,l,r,d);
	}
	update(i);
}
int main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	n=read(),c=read();
	c<<=1;
	for(int i=1;i<=n;i++){
		int u=read(),v=read();
		int x=u+v,y=u-v;
		a[i].l=a[n+i].l=y;
		a[i].r=a[n+i].r=y+c;
		a[i].x=x;
		a[n+i].x=x+c+1;
		a[i].type=1;
		a[n+i].type=-1;
		b[++m]=y;
		b[++m]=y+c;
	}
	sort(b+1,b+m+1);
	m=unique(b+1,b+m+1)-b-1;
	n<<=1;
	for(int i=1;i<=n;i++){
		a[i].l=lower_bound(b+1,b+m+1,a[i].l)-b;
		a[i].r=lower_bound(b+1,b+m+1,a[i].r)-b;
	}
	sort(a+1,a+n+1,cmp);
	build(1,1,m);
	for(int i=1;i<=n;i++){
		change(1,a[i].l,a[i].r,a[i].type);
		ans=max(ans,tree[1].mx);
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 1 
1 1 
1 -1 
-1 1 
-1 -1 
2 0
*/