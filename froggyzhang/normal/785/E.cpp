#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#pragma GCC optimize(3)
typedef long long ll;
#define N 200020
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,Q,a[N];
ll ans;
namespace FHQ_Treap{
	int cnt;
	int bin[N],bin_size;
	struct node{
		int siz,ch[2],val,key;
	}t[N<<5];
	#define ls t[k].ch[0]
	#define rs t[k].ch[1]
	inline void update(int k){
		t[k].siz=t[ls].siz+t[rs].siz+1;
	}
	inline int NewNode(int data){
		int k=(bin_size?bin[bin_size--]:++cnt);
		t[k].key=rand();
		t[k].siz=1;
		t[k].val=data;
		ls=rs=0;
		return k;
	}
	inline void Split(int k,int data,int &l,int &r){
		if(!k)return (void)(l=r=0);
		if(t[k].val<=data){
			l=k,Split(rs,data,rs,r);
		}
		else{
			r=k,Split(ls,data,l,ls);
		}
		update(k);
	}
	inline int Merge(int l,int r){
		if(!l||!r)return l|r;
		if(t[l].key<t[r].key){
			t[l].ch[1]=Merge(t[l].ch[1],r);
			update(l);
			return l;
		}
		else{
			t[r].ch[0]=Merge(l,t[r].ch[0]);
			update(r);
			return r;
		}
	}
	int Query(int &root,int x,int y){
		static int l,p,r;
		Split(root,y,l,r);
		Split(l,x-1,l,p);
		int ans=t[p].siz;
		root=Merge(Merge(l,p),r);
		return ans;
	}
	void Insert(int &root,int data){
		static int l,r;
		Split(root,data,l,r);
		root=Merge(Merge(l,NewNode(data)),r);
	}
	void Del(int &root,int data){
		static int l,p,r;
		Split(root,data,l,r);
		Split(l,data-1,l,p);
		bin[++bin_size]=p;
		root=Merge(l,r);
	}
	#undef ls
	#undef rs
}
namespace sgt{
	struct node{
		int root;
	}tree[N<<2];
	#define ls i<<1
	#define rs i<<1|1
	void Insert(int i,int L,int R,int pos,int x){
		FHQ_Treap::Insert(tree[i].root,x);
		if(L==R)return;
		int mid=(L+R)>>1;
		if(pos<=mid)Insert(ls,L,mid,pos,x);
		else Insert(rs,mid+1,R,pos,x);
	}
	void Del(int i,int L,int R,int pos,int x){
		FHQ_Treap::Del(tree[i].root,x);
		if(L==R)return;
		int mid=(L+R)>>1;
		if(pos<=mid)Del(ls,L,mid,pos,x);
		else Del(rs,mid+1,R,pos,x);
	}
	int Query(int i,int L,int R,int l,int r,int x,int y){
		if(l>r||x>y)return 0;
		if(L>=l&&R<=r)return FHQ_Treap::Query(tree[i].root,x,y);
		int mid=(L+R)>>1,ans=0;
		if(l<=mid)ans+=Query(ls,L,mid,l,r,x,y);
		if(r>mid)ans+=Query(rs,mid+1,R,l,r,x,y);
		return ans;
	}
	#undef ls 
	#undef rs
}
int main(){
	n=read(),Q=read();
	for(int i=1;i<=n;++i){
		sgt::Insert(1,1,n,i,i);
		a[i]=i;
	}
	while(Q--){
		int x=read(),y=read();
		if(x==y)goto MYH;
		if(x>y)swap(x,y);
		ans+=sgt::Query(1,1,n,x+1,y-1,a[x]+1,n)-sgt::Query(1,1,n,x+1,y-1,1,a[x]-1);
		ans-=sgt::Query(1,1,n,x+1,y-1,a[y]+1,n)-sgt::Query(1,1,n,x+1,y-1,1,a[y]-1);
		ans+=(a[x]>a[y]?-1:1);
		sgt::Del(1,1,n,x,a[x]);
		sgt::Del(1,1,n,y,a[y]);
		swap(a[x],a[y]);
		sgt::Insert(1,1,n,x,a[x]);
		sgt::Insert(1,1,n,y,a[y]);
		MYH:
		printf("%I64d\n",ans);
	}
	return 0;
}