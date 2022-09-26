#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
using namespace std;
#define N 200020
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
int n,k,m;
set<pair<int,int> > s;
multiset<int> R;
struct node{
	int l,r,add,mx;
	inline void Add(int d){
		add+=d;
		mx+=d;
	} 
}tree[N<<3];
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
	tree[i].add=0;
	if(l==r){
		tree[i].mx=-(n-l+1);
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(i);
}
void Change(int i,int l,int r,int d){
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
int Query(int i,int l,int r){
	if(tree[i].l>=l&&tree[i].r<=r){
		return tree[i].mx;
	}
	pushdown(i);
	int ans=0;
	int mid=(tree[i].l+tree[i].r)>>1;
	if(l<=mid){
		ans=max(ans,Query(ls,l,r));
	}
	if(r>mid){
		ans=max(ans,Query(rs,l,r));
	}
	return ans;
}
int main(){
	n=read(),k=read(),m=read();
	build(1,1,n<<1);
	for(int i=1;i<=m;++i){
		int x=read(),y=read();
		if(s.count(make_pair(x,y))){
			s.erase(make_pair(x,y));
			R.erase(R.find(y+abs(k-x)));
			Change(1,1,y+abs(k-x),-1);
		}
		else{
			s.insert(make_pair(x,y));
			R.insert(y+abs(k-x));
			Change(1,1,y+abs(k-x),1);
		}
		printf("%d\n",R.empty()?0:max(0,Query(1,1,*--R.end())));
	}
	return 0;
}