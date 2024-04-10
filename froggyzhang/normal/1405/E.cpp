#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 300030
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
int n,Q,a[N],d[N];
namespace FHQ{
	int cnt,root;
	struct node{
		int val,key,ch[2],siz;
	}t[N]; 
	#define ls t[k].ch[0]
	#define rs t[k].ch[1]
	inline int NewNode(int data){
		int k=++cnt;
		t[k].key=rand();
		t[k].val=data;
		t[k].siz=1;
		ls=rs=0;
		return k;
	}
	inline void update(int k){
		t[k].siz=t[ls].siz+t[rs].siz+1;
	}
	inline void Split(int k,int data,int &l,int &r){
		if(!k){
			l=r=0;
			return;
		}
		if(t[k].val<=data){
			l=k;
			Split(rs,data,rs,r);
		}
		else{
			r=k;
			Split(ls,data,l,ls);
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
	inline void Insert(int x){
		int l,r;
		Split(root,x,l,r);
		root=Merge(Merge(l,NewNode(x)),r);
	}
	inline int kth(int k,int x){
		while(true){
			if(t[rs].siz+1==x)return t[k].val;
			else if(t[rs].siz+1>x){
				k=rs;
			}
			else{
				x-=t[rs].siz+1;
				k=ls;
			}
		}
	}
	#undef ls
	#undef rs
}
namespace Chair{
	int root[N],cnt;
	struct node{
		int siz,ch[2];
	}tree[N<<5];
	#define ls tree[k].ch[0]
	#define rs tree[k].ch[1]
	void Insert(int &k,int pre,int L,int R,int pos){
		k=++cnt;
		tree[k]=tree[pre];
		++tree[k].siz;
		if(L==R)return;
		int mid=(L+R)>>1;
		if(pos<=mid)Insert(ls,tree[pre].ch[0],L,mid,pos);
		else Insert(rs,tree[pre].ch[1],mid+1,R,pos);
	}
	int Query(int k,int L,int R,int l,int r){
		if(L>=l&&R<=r)return tree[k].siz;
		int tot=0;
		int mid=(L+R)>>1;
		if(l<=mid){
			tot+=Query(ls,L,mid,l,r);
		}
		if(r>mid){
			tot+=Query(rs,mid+1,R,l,r);
		}
		return tot;
	}
}
int main(){
	n=read(),Q=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		int tmp=i-a[i];
		if(i-a[i]<0){
			d[i]=-1;
			continue;
		}
		if(tmp==0){
			d[i]=i-1;
		}
		else{
			if(tmp>FHQ::t[FHQ::root].siz){
				d[i]=-1;
				continue;
			}
			else d[i]=FHQ::kth(FHQ::root,tmp);
		}
		FHQ::Insert(d[i]);
	}
	for(int i=1;i<=n;++i){
		Chair::root[i]=Chair::root[i-1];
		if(~d[i]){
			Chair::Insert(Chair::root[i],Chair::root[i],0,n-1,d[i]);
		}
	}
	while(Q--){
		int x=read(),y=read();
		printf("%d\n",Chair::Query(Chair::root[n-y],0,n-1,x,n-1));
	}
	return 0;
}