#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<int,int> pa;
int n,m;
#define Maxn 100010
int a[Maxn];
pa seq[Maxn];int len;
struct Data{
	int ans,lans,rans;
	int lpos,rpos,pos1,pos2,sum;
	void init(int x){
		ans=lans=rans=sum=a[x];
		lpos=rpos=pos1=pos2=x;
	}
};
Data merge(Data a,Data b){
	Data res;
	res.sum=a.sum+b.sum;
	if(a.sum+b.lans>a.lans){
		res.lans=a.sum+b.lans;
		res.lpos=b.lpos;
	}else{
		res.lans=a.lans;
		res.lpos=a.lpos;
	}
	if(a.rans+b.sum>b.rans){
		res.rans=a.rans+b.sum;
		res.rpos=a.rpos;
	}else{
		res.rans=b.rans;
		res.rpos=b.rpos;
	}
	if(a.ans>b.ans){
		res.ans=a.ans;
		res.pos1=a.pos1;
		res.pos2=a.pos2;
	}else{
		res.ans=b.ans;
		res.pos1=b.pos1;
		res.pos2=b.pos2;
	}
	if(a.rans+b.lans>res.ans){
		res.ans=a.rans+b.lans;
		res.pos1=a.rpos;
		res.pos2=b.lpos;
	}
	return res;
}

bool tag[Maxn<<2];
struct Node{
	Data ans,revans;
}tree[Maxn<<2];
inline void push_up(int k){
	tree[k].ans=merge(tree[k<<1].ans,tree[k<<1|1].ans);
	tree[k].revans=merge(tree[k<<1].revans,tree[k<<1|1].revans);
}
inline void Maketag(int k){
	swap(tree[k].ans,tree[k].revans);
	tag[k]^=1;
}
inline void push_down(int k){
	if(tag[k]){
		Maketag(k<<1);
		Maketag(k<<1|1);
		tag[k]=false; 
	}
}
inline void Rev(int k,int l,int r,int L,int R){
	if(l==L&&r==R){
		Maketag(k);
		return;
	}
	push_down(k);
	int mid=(l+r)>>1;
	if(R<=mid)Rev(k<<1,l,mid,L,R);
	else if(mid<L)Rev(k<<1|1,mid+1,r,L,R);
	else{
		Rev(k<<1,l,mid,L,mid);
		Rev(k<<1|1,mid+1,r,mid+1,R);
	}
	push_up(k);
}
void Build_Tree(int k,int l,int r){
	if(l==r){
		tree[k].ans.init(l);
		a[l]=-a[l];
		tree[k].revans.init(l);
		a[l]=-a[l];
		return;
	}
	int mid=(l+r)>>1;
	Build_Tree(k<<1,l,mid);
	Build_Tree(k<<1|1,mid+1,r);
	push_up(k);
}
void Modify(int k,int l,int r,int pos){
	if(l==r){
		tree[k].ans.init(pos);
		a[pos]=-a[pos];
		tree[k].revans.init(pos);
		a[pos]=-a[pos];
		return;
	}
	push_down(k);
	int mid=(l+r)>>1;
	if(pos<=mid)Modify(k<<1,l,mid,pos);
	else Modify(k<<1|1,mid+1,r,pos); 
	push_up(k);
}
Data Query(int k,int l,int r,int L,int R){
	if(l==L&&r==R)return tree[k].ans;
	push_down(k);
	int mid=(l+r)>>1;
	if(R<=mid)return Query(k<<1,l,mid,L,R);
	else if(mid<L)return Query(k<<1|1,mid+1,r,L,R);
	else return merge(Query(k<<1,l,mid,L,mid),Query(k<<1|1,mid+1,r,mid+1,R));
}

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	rd(n);
	for(register int i=1;i<=n;++i)rd(a[i]);
	Build_Tree(1,1,n);
	rd(m);
	int l,r,k,x,val,op;
	while(m--){
		rd(op);
		if(op==0){
			rd(x);rd(val);
			a[x]=val;
			Modify(1,1,n,x);
		}else{
			rd(l);rd(r);rd(k);
			int Ans=0;
			len=0;
			while(k--){
				Data res=Query(1,1,n,l,r);
				if(res.ans<=0)break;
				Ans+=res.ans;
				Rev(1,1,n,res.pos1,res.pos2);
				seq[++len]=make_pair(res.pos1,res.pos2);
				if(!k)break;
			}
			printf("%d\n",Ans);
			for(register int i=1;i<=len;++i)Rev(1,1,n,seq[i].first,seq[i].second);
		}
	}
	return 0;
}