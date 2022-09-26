//qwqwq


//guaguagua
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1000100
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

int n,m,p,mx,suf[N],ans;
struct Weapon{
	int x,c;
}a[N];
struct Sheild{
	int x,c;
}b[N];
struct Mon{
	int x,y,c;
}s[N];
bool cmp1(Weapon a,Weapon b){
	return a.x<b.x;
}
bool cmp2(Mon a,Mon b){
	return a.x<b.x;
}

struct node{
	int l,r,mx,add;
	inline void Add(int d){
		mx+=d;
		add+=d;
	}
}tree[N<<2];
#define ls i<<1
#define rs i<<1|1
inline void update(int i){
	tree[i].mx=max(tree[ls].mx,tree[rs].mx);
}
inline void pushdown(int i){
	if(tree[i].add){
		tree[ls].Add(tree[i].add);
		tree[rs].Add(tree[i].add);
		tree[i].add=0;
	}
}
void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	if(l==r){
		tree[i].mx=-suf[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(i);
}
void _plus(int i,int l,int r,int d){
	if(tree[i].l>=l&&tree[i].r<=r){
		tree[i].Add(d);
		return;
	}
	pushdown(i);
	int mid=(tree[i].l+tree[i].r)>>1;
	if(l<=mid){
		_plus(ls,l,r,d);
	}
	if(r>mid){
		_plus(rs,l,r,d);
	}
	update(i);
}
int main(){
	for(int i=0;i<=1000002;++i)suf[i]=2e9; 
	n=read(),m=read(),p=read();
	ans=-2e9;
	for(int i=1;i<=n;i++){
		a[i].x=read(),a[i].c=read();
		mx=max(mx,a[i].x);
	}
	for(int i=1;i<=m;i++){
		b[i].x=read(),b[i].c=read();
		mx=max(mx,b[i].x);
		suf[b[i].x]=min(suf[b[i].x],b[i].c);
	}
	for(int i=1;i<=p;i++){
		s[i].x=read()+1,s[i].y=read()+1,s[i].c=read();
		mx=max(mx,max(s[i].x,s[i].y));
	}
	
	sort(a+1,a+n+1,cmp1);
	sort(s+1,s+p+1,cmp2);
	++mx;
	for(int i=mx-1;i>=1;i--){
		suf[i]=min(suf[i],suf[i+1]);
	}
	build(1,1,mx);
	int pos=0;
	for(int i=1;i<=n;i++){
		while(pos<p&&a[i].x>=s[pos+1].x){
			_plus(1,s[pos+1].y,mx,s[pos+1].c);
			++pos;
		}
		ans=max(ans,tree[1].mx-a[i].c);
	}
	cout<<ans<<endl;
	return 0;
}