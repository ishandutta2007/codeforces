#include<bits/stdc++.h>
using namespace std;
#define N 200010
const int B=200000;
typedef long long ll;
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
int n,Q,a[N];
set<int> s[N];
struct Segment_Tree{
	struct node{
		int lmx,rmx,sum,mnc,mxw,add;
		inline void Cov(int d){
			mnc+=d,add+=d;
		}
	}tree[N<<2];
	#define ls i<<1
	#define rs i<<1|1
	inline void update(int i){
		tree[i].mnc=min(tree[ls].mnc,tree[rs].mnc);
		tree[i].mxw=max(tree[ls].mxw,tree[rs].mxw);
		if(tree[ls].mnc<tree[rs].mnc){
			tree[i].lmx=tree[ls].lmx;
			tree[i].rmx=max(tree[ls].rmx,tree[rs].mxw);
			tree[i].sum=tree[ls].sum;
		}
		else if(tree[rs].mnc<tree[ls].mnc){
			tree[i].rmx=tree[rs].rmx;
			tree[i].lmx=max(tree[rs].lmx,tree[ls].mxw);
			tree[i].sum=tree[rs].sum;
		}
		else{
			tree[i].lmx=tree[ls].lmx;
			tree[i].rmx=tree[rs].rmx;
			tree[i].sum=tree[ls].sum+tree[rs].sum+max(tree[ls].rmx,tree[rs].lmx);
		}
	}
	inline void pushdown(int i){
		if(tree[i].add){
			tree[ls].Cov(tree[i].add);
			tree[rs].Cov(tree[i].add);
			tree[i].add=0;
		}
	}
	void Change(int i,int L,int R,int p,int x){
		if(L==R){
			tree[i].mxw=tree[i].lmx=x;
			return;
		}
		pushdown(i);
		int mid=(L+R)>>1;
		p<=mid?Change(ls,L,mid,p,x):Change(rs,mid+1,R,p,x);
		update(i);
	}
	void Cover(int i,int L,int R,int l,int r,int x){
		if(L>=l&&R<=r){
			tree[i].Cov(x);
			return;
		}
		pushdown(i);
		int mid=(L+R)>>1;
		if(l<=mid)Cover(ls,L,mid,l,r,x);
		if(r>mid)Cover(rs,mid+1,R,l,r,x);
		update(i);
	}
	inline int get_ans(){
		return tree[1].sum+tree[1].lmx+tree[1].rmx;
	}
}T;
void Change(int c,int t){
	int w=s[c].size();
	if(!w)return;
	T.Change(1,1,n,*s[c].begin(),t>0?w:0);
	if(w>1)T.Cover(1,1,n,*s[c].begin(),(*s[c].rbegin())-1,t);
}
int main(){
	n=read(),Q=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		s[a[i]].insert(i);
	}
	for(int i=1;i<=B;++i){
		Change(i,1);
	}
	printf("%d\n",n-T.get_ans());
	while(Q--){
		int x=read();
		Change(a[x],-1);
		s[a[x]].erase(x);
		Change(a[x],1);
		a[x]=read();
		Change(a[x],-1);
		s[a[x]].insert(x);
		Change(a[x],1);	
		printf("%d\n",n-T.get_ans());
	}
	return 0;
}