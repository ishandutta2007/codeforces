#include<bits/stdc++.h>
using namespace std;
#define N 200020
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
int n,Q,rt,cnt;
const int C=(1<<20)-1;
inline int G(int x){
	return x?1:0;
}
struct Trie{
	int ch[2],sum;
	int tag,h0,h1;
	inline void Rev(int x,int d){
		tag^=x;
		int t0=h0&x,t1=h1&x;
		h0=t1|(h0&(C^x));
		h1=t0|(h1&(C^x));
		if(d>=0&&x>>d&1){
			swap(ch[0],ch[1]);
		}
	}
}trie[N<<5];
#define ls trie[u].ch[0]
#define rs trie[u].ch[1]
inline void update(int u,int d){
	trie[u].sum=trie[ls].sum+trie[rs].sum;
	trie[u].h0=(trie[ls].h0|trie[rs].h0|(G(ls)<<d));
	trie[u].h1=(trie[ls].h1|trie[rs].h1|(G(rs)<<d));
}
inline void pushdown(int u,int d){
	if(trie[u].tag){
		trie[ls].Rev(trie[u].tag,d-1);
		trie[rs].Rev(trie[u].tag,d-1);
		trie[u].tag=0;
	}		
}
void Insert(int &u,int x,int d){
	if(!u){
		u=++cnt;
		if(d<0)trie[u].sum=1;
	}
	if(d<0)return;
	int c=(x>>d&1);
	Insert(trie[u].ch[c],x,d-1);
	update(u,d);
}
void Split(int &u,int &v,int L,int R,int l,int r,int d){
	if(R<l||L>r||!u){
		v=0;
		return;
	}
	if(L>=l&&R<=r){
		v=u,u=0;
		return;
	}
	int mid=(L+R)>>1;
	pushdown(u,d);
	v=++cnt;
	Split(ls,trie[v].ch[0],L,mid,l,r,d-1);
	Split(rs,trie[v].ch[1],mid+1,R,l,r,d-1);
	update(u,d),update(v,d);
}
void Merge(int &u,int &v,int d){
	if(!u||!v)return (void)(u|=v);
	if(d<0)return;
	pushdown(u,d),pushdown(v,d);
	Merge(ls,trie[v].ch[0],d-1);
	Merge(rs,trie[v].ch[1],d-1);
	update(u,d);
}
void Or(int u,int x,int d){
	if(!u||d<0)return;
	if(!(x&trie[u].h0&trie[u].h1))return trie[u].Rev(x&trie[u].h0,d);
	pushdown(u,d);
	if(x>>d&1){
		trie[ls].Rev(1<<d,d-1);
		Merge(rs,ls,d-1);
		ls=0;
	}
	Or(ls,x,d-1),Or(rs,x,d-1);
	update(u,d);
}
int main(){
	n=read(),Q=read();
	for(int i=1;i<=n;++i){
		int x=read();
		Insert(rt,x,19);
	}
	while(Q--){
		int opt=read();
		int l=read(),r=read();
		int p;
		Split(rt,p,0,C,l,r,19);
		if(opt==1){
			int x=read();
			trie[p].Rev(C,19);
			Or(p,x^C,19);
			trie[p].Rev(C,19);
		}
		else if(opt==2){
			int x=read();
			Or(p,x,19);
		}
		else if(opt==3){
			int x=read();
			trie[p].Rev(x,19);
		}
		else{
			printf("%d\n",trie[p].sum);
		}
		Merge(rt,p,19);
	}
	return 0;
}