#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <set>
#define MAXN 200100
#define TREAP_SIZE 7000010
#define LL long long
using namespace std;

int n,m,sizew;
int v[MAXN],nxt[MAXN];

int read(){
	char c;
	while((c=getchar())<'0' || c>'9');
	int res=c-'0';
	while((c=getchar())>='0' && c<='9') res=res*10+c-'0';
	return res;
}

namespace Treap{
	struct node{
		int ch[2];
		LL s;
		int v1,v2,key;
	}a[TREAP_SIZE];

	int size=0;

	int newnode(int v1,int v2){
		int x=++size;
		assert(x<TREAP_SIZE);
		a[x].key=rand();
		a[x].v1=v1;
		a[x].s=a[x].v2=v2;
		a[x].ch[0]=a[x].ch[1]=0;
		return x;
	}

	void pushup(int x){
		a[x].s=a[x].v2+a[a[x].ch[0]].s+a[a[x].ch[1]].s;
	}

	void rotate(int &x,int d){
		int t=a[x].ch[d^1];
		a[x].ch[d^1]=a[t].ch[d];
		a[t].ch[d]=x;
		pushup(x); pushup(t);
		x=t;
	}

	void insert(int &x,int v1,int v2){
		if(!x){
			x=newnode(v1,v2);
			return;
		}
		if(v1<a[x].v1){
			insert(a[x].ch[0],v1,v2);
			if(a[a[x].ch[0]].key<a[x].key) rotate(x,1);
			else pushup(x);
		}else{
			insert(a[x].ch[1],v1,v2);
			if(a[a[x].ch[1]].key<a[x].key) rotate(x,0);
			else pushup(x);
		}
	}

	LL query(int x,int v1){
		if(!x) return 0;
		if(v1<a[x].v1) return query(a[x].ch[0],v1);
		else return a[a[x].ch[0]].s+a[x].v2+query(a[x].ch[1],v1);
	}

	void modify(int x,int v1,int v2){
		if(v1==a[x].v1) a[x].v2-=v2;
		else if(v1<a[x].v1) modify(a[x].ch[0],v1,v2);
		else modify(a[x].ch[1],v1,v2);
		pushup(x);
	}
}

namespace Seg{
	int root[MAXN<<2];
	int v0[MAXN];

	void init(int x,int cl,int cr){
		for(int i=cl;i<=cr && i<=n;i++)
			Treap::insert(root[x],nxt[i],nxt[i]-i);
		if(cl<cr){
			int mid=(cl+cr)>>1;
			init(x<<1,cl,mid);
			init(x<<1|1,mid+1,cr);
		}else v0[cl]=nxt[cl];
	}

	void modify(int x,int cl,int cr,int pos,int val){
		Treap::modify(root[x],v0[pos],v0[pos]-pos);
		Treap::insert(root[x],val,val-pos);
		if(cl<cr){
			int mid=(cl+cr)>>1;
			if(pos<=mid) modify(x<<1,cl,mid,pos,val);
			else modify(x<<1|1,mid+1,cr,pos,val);
		}
	}

	LL sum(int x,int cl,int cr,int l,int r,int lim){
		if(l<=cl && cr<=r) return Treap::query(root[x],lim);
		int mid=(cl+cr)>>1;
		LL res=0;
		if(l<=mid) res+=sum(x<<1,cl,mid,l,r,lim);
		if(r>mid) res+=sum(x<<1|1,mid+1,cr,l,r,lim);
		return res;
	}

	LL debug(){
		LL res=0;
		for(int i=1;i<=5;i++)
			if(v0[i]<=5) res+=v0[i]-i;
		return res;
	}

	void modify(int x,int y){
		modify(1,1,sizew,x,y);
		v0[x]=y;
		//if(debug()!=sum(1,1,sizew,1,5,5)){
			//int sdf=12;
		//}
	}
}

namespace Set{
	set<int> S[MAXN];

	void init(){
		for(int i=n;i>=1;i--){
			if(S[v[i]].empty()) nxt[i]=n+1;
			else nxt[i]=*(S[v[i]].begin());
			S[v[i]].insert(i);
		}
	}

	void modify(int x,int y){
		if(v[x]==y) return;
		set<int>::iterator it=S[v[x]].find(x);
		if(it!=S[v[x]].begin()){
			--it;
			nxt[*it]=nxt[x];
			Seg::modify(*it,nxt[x]);
			++it;
		}
		S[v[x]].erase(it);
		v[x]=y;
		S[v[x]].insert(x);
		it=S[v[x]].find(x);
		if(it==S[v[x]].begin()){
			it++;
			if(it==S[v[x]].end()) nxt[x]=n+1;
			else nxt[x]=*it;
		}else{
			it--;
			nxt[x]=nxt[*it];
			nxt[*it]=x;
			Seg::modify(*it,x);
		}
		Seg::modify(x,nxt[x]);
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("C.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(sizew=1;sizew<=n;sizew<<=1);
	for(int i=1;i<=n;i++) v[i]=read();
	Set::init();
	Seg::init(1,1,sizew);
	while(m--){
		int t=read(),x=read(),y=read();
		if(t==1) Set::modify(x,y);
		else{
#ifndef ONLINE_JUDGE
			printf("%lld\n",Seg::sum(1,1,sizew,x,y,y));
#else
			printf("%I64d\n",Seg::sum(1,1,sizew,x,y,y));
#endif
		}
	}
	return 0;
}