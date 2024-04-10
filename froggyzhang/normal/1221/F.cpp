#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 1000200
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
int n,b[N],len,posl,posr;
ll sum,ans;
struct Point{
	int x,y;
	ll w;
	bool operator <(const Point b)const{
		return max(x,y)<max(b.x,b.y);
	}
}a[N];
struct node{
	int l,r,p;
	ll mn,add;
	void Add(ll d){
		mn+=d,add+=d;
	}
}tree[N<<2];
#define ls (i<<1)
#define rs (i<<1|1)
inline void update(int i){
	tree[i].mn=min(tree[ls].mn,tree[rs].mn);
	tree[i].p=(tree[i].mn==tree[ls].mn?tree[ls].p:tree[rs].p);
}
void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	if(l==r){
		tree[i].mn=0;
		tree[i].p=l;
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
}
inline void pushdown(int i){
	if(tree[i].add){
		tree[ls].Add(tree[i].add);
		tree[rs].Add(tree[i].add);
		tree[i].add=0;
	}
}
void Change(int i,int l,int r,ll d){
	if(tree[i].l>=l&&tree[i].r<=r){
		tree[i].Add(d);
		return;
	}
	pushdown(i);
	int mid=(tree[i].l+tree[i].r)>>1;
	if(l<=mid){
		Change(ls,l,r,d);
	}
	if(r>mid){
		Change(rs,l,r,d);
	}
	update(i);
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i].x=read(),a[i].y=read(),a[i].w=read();
		b[++len]=a[i].x,b[++len]=a[i].y;
	}
	b[++len]=-1;
	sort(b+1,b+len+1);
	len=unique(b+1,b+len+1)-b-1;
	for(int i=1;i<=n;++i){
		a[i].x=lower_bound(b+1,b+len+1,a[i].x)-b;
		a[i].y=lower_bound(b+1,b+len+1,a[i].y)-b;
	}
	sort(a+1,a+n+1);
	int pos=1;
	build(1,1,len);
	posl=posr=2e9;
	for(int i=1;i<=len;++i){
		while(pos<=n&&max(a[pos].x,a[pos].y)<=i){
			sum+=a[pos].w;
			Change(1,min(a[pos].x,a[pos].y),len,a[pos].w);
			++pos;
		}
		if(i>2)Change(1,1,i-2,b[i]-b[i-1]);
		if(sum-tree[1].mn>ans){
			posr=b[i],posl=b[tree[1].p+1],ans=sum-tree[1].mn;
		}
	}
	printf("%I64d\n",ans);
	printf("%d %d %d %d\n",posl,posl,posr,posr);
	return 0;
}