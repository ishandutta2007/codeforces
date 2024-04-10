#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 300020
typedef long long ll;
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
int n,Q,a[N],cnt,root;
struct node{
	int ch[2],tag,d;
	ll sum;
	inline void XOR(int x){
		if((x>>d)&1)swap(ch[0],ch[1]);
		tag^=x;
	}
}t[N<<1];
#define ls t[u].ch[0]
#define rs t[u].ch[1]
inline void update(int u){
	t[u].sum=t[ls].sum+t[rs].sum;
}
inline void pushdown(int u){
	if(t[u].tag){
		t[ls].XOR(t[u].tag);
		t[rs].XOR(t[u].tag);
		t[u].tag=0;
	}
}
int build(int l,int r,int dep){
	int u=++cnt;
	t[u].d=dep;
	if(l==r){
		t[u].sum=a[l];
		return u;
	}
	int mid=(l+r)>>1;
	ls=build(l,mid,dep-1);
	rs=build(mid+1,r,dep-1);
	update(u);
	return u;
}
void Change(int u,int L,int R,int pos,int val){
	if(L==R){
		t[u].sum=val;
		return;
	}
	pushdown(u);
	int mid=(L+R)>>1;
	if(pos<=mid){
		Change(ls,L,mid,pos,val);
	}
	else{
		Change(rs,mid+1,R,pos,val);
	}
	update(u);
}
ll Query(int u,int L,int R,int l,int r){
	if(L>=l&&R<=r){
		return t[u].sum;
	}
	pushdown(u);
	ll ans=0;
	int mid=(L+R)>>1;
	if(l<=mid){
		ans+=Query(ls,L,mid,l,r);
	}
	if(r>mid){
		ans+=Query(rs,mid+1,R,l,r);
	}
	return ans;
}
int main(){
	n=read(),Q=read();
	for(int i=1;i<=(1<<n);++i){
		a[i]=read();
	}
	root=build(1,1<<n,n);
	while(Q--){
		int opt=read();
		if(opt==1){
			int x=read(),k=read();
			Change(root,1,1<<n,x,k);
		}
		else if(opt==2){
			int x=read();
			t[root].XOR((1<<(x+1))-1);
			
		}
		else if(opt==3){
			int x=read()+1;
			t[root].XOR(1<<x);
		}
		else{
			int l=read(),r=read();
			printf("%I64d\n",Query(root,1,1<<n,l,r));
		}
	}
	return 0;
}