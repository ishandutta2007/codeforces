#include<bits/stdc++.h>
using namespace std;
#define N 150055
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
inline ll read(){
	ll x=0,f=1;
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
int n,p[N],a[N];
class Segment_Tree{
public:
	struct node{
		int mx,se,add1,add2,siz,cmx;
		ll sum;
		node(){mx=se=-inf;siz=add1=add2=cmx=sum=0;}
		inline void Add1(int d){
			sum+=1LL*cmx*d,add1+=d,mx+=d;
		}
		inline void Add2(int d){
			sum+=1LL*siz*d,add2+=d,mx+=d,se+=d;
		}			
	}tree[N<<2];
	#define ls i<<1
	#define rs i<<1|1
	inline void update(int i){
		tree[i].sum=tree[ls].sum+tree[rs].sum;
		tree[i].siz=tree[ls].siz+tree[rs].siz;
		tree[i].mx=max(tree[ls].mx,tree[rs].mx);
		tree[i].se=(tree[ls].mx==tree[rs].mx?max(tree[ls].se,tree[rs].se):(tree[ls].mx<tree[rs].mx?max(tree[ls].mx,tree[rs].se):max(tree[rs].mx,tree[ls].se)));
		tree[i].cmx=(tree[i].mx==tree[ls].mx?tree[ls].cmx:0)+(tree[i].mx==tree[rs].mx?tree[rs].cmx:0);
	}
	inline void pushdown(int i){
		if(tree[i].add1){
			int mx=max(tree[ls].mx,tree[rs].mx);
			if(mx==tree[ls].mx)tree[ls].Add1(tree[i].add1);
			if(mx==tree[rs].mx)tree[rs].Add1(tree[i].add1);
			tree[i].add1=0;
		}
		if(tree[i].add2){
			tree[ls].Add2(tree[i].add2);
			tree[rs].Add2(tree[i].add2);
			tree[i].add2=0;
		}
	}
	void Min(int i,int L,int R,int l,int r,int d){
		if(tree[i].mx<=d)return;
		if(L>=l&&R<=r&&tree[i].se<=d){
			tree[i].Add1(d-tree[i].mx);
			return;
		}
		pushdown(i);
		int mid=(L+R)>>1;
		if(l<=mid)Min(ls,L,mid,l,r,d);
		if(r>mid)Min(rs,mid+1,R,l,r,d);
		update(i);
	}
	void Plus(int i,int L,int R,int l,int r,int d){
		if(L>=l&&R<=r){
			tree[i].Add2(d);
			return;
		}
		pushdown(i);
		int mid=(L+R)>>1;
		if(l<=mid)Plus(ls,L,mid,l,r,d);
		if(r>mid)Plus(rs,mid+1,R,l,r,d);
		update(i);
	}
	void Change(int i,int L,int R,int x,int d){
		if(L==R){
			tree[i].siz=tree[i].cmx=1;
			tree[i].sum=tree[i].mx=d;
			return;
		}
		pushdown(i);
		int mid=(L+R)>>1;
		x<=mid?Change(ls,L,mid,x,d):Change(rs,mid+1,R,x,d);
		update(i);
	}
};
class BIT{
private:
	int b[N];
	inline int lowbit(int x){return x&(-x);}
public:
	BIT(){memset(b,0,sizeof(b));}
	inline void Add(int x,int d){
		while(x<=n)b[x]+=d,x+=lowbit(x);
	}
	inline int Ask(int x){
		int ans=0;
		while(x)ans+=b[x],x-=lowbit(x);
		return ans;
	}	
};
ll ans[N];
void Solve(int opt){
	Segment_Tree *T=new Segment_Tree;
	BIT *B=new BIT;
	for(int i=1;i<=n;++i){
		p[a[i]]=i;
	}
	for(int i=1;i<=n;++i){
		int u=p[i];
		int rk=B->Ask(u)+1;
		B->Add(u,1);
		T->Change(1,1,n,u,i+1);
		if(u<n)T->Plus(1,1,n,u+1,n,1);
		if(u>1)T->Min(1,1,n,1,u-1,rk);
		ans[i]+=(opt==1?T->tree[1].sum:-(1LL*i*(i+1)-T->tree[1].sum));
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();	
	}
	Solve(1);
	reverse(a+1,a+n+1);
	Solve(-1);
	for(int i=1;i<=n;++i){
		printf("%lld\n",ans[i]-i);	
	}
	return 0;
}