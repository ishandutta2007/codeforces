#include<bits/stdc++.h>
using namespace std;
#define N 300030
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
int n,rt;
mt19937 rnd(time(0));
struct node{
	int ch[2],val,add,siz,key;
	inline void Add(int d){
		val+=d,add+=d;
	}
}t[N<<1];
#define ls t[k].ch[0]
#define rs t[k].ch[1]
int cnt;
inline int NewNode(int data){
	int k=++cnt;
	t[k].val=data;
	t[k].siz=1;
	t[k].key=rnd();
	ls=rs=t[k].add=0;
	return k;
}
inline void pushdown(int k){	
	if(t[k].add){
		t[ls].Add(t[k].add);
		t[rs].Add(t[k].add);
		t[k].add=0;
	}
}
inline void update(int k){
	t[k].siz=t[ls].siz+t[rs].siz+1;
}
int Merge(int l,int r){
	if(!l||!r)return l|r;
	pushdown(l),pushdown(r);
	if(t[l].key>t[r].key){
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
void Split(int k,int data,int &l,int &r){
	if(!k){
		l=r=0;
		return;
	}
	pushdown(k);
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
void Insert(int x){
	int l,r,p;
	Split(rt,x,l,r);
	Split(l,x-1,l,p);
	if(p){
		rt=Merge(Merge(l,p),r);
		return;
	}
	rt=Merge(Merge(l,NewNode(x)),r);
}
void Del(int x){
	int l,r,q;
	Split(rt,x,l,r);
	int p=r;
	while(t[p].ch[0]){
		pushdown(p),p=t[p].ch[0];
	}
	Split(r,t[p].val,q,r);
	rt=Merge(l,r);
}
void Plus(int x,int y){
	if(x>y)return;
	int l,r,p;
	Split(rt,y,l,r);
	Split(l,x-1,l,p);
	t[p].Add(1);
	rt=Merge(Merge(l,p),r);
}
void Solve(int l,int r){
	Del(r-1);
	Plus(l,r-1);
	Insert(l);
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		int l=read(),r=read();
		Solve(l,r);	
	}
	printf("%d\n",t[rt].siz);
	return 0;
}