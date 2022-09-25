#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int inf=0x3f3f3f3f;
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
int n,Q,pw[10],a[N];
struct node{
	array<int,10> c;
	int mn;
	node(){c.fill(inf),mn=2*inf;}
}tree[N<<2];
#define ls i<<1
#define rs i<<1|1
inline void update(node &u,const node &l,const node &r){
	u.mn=min(l.mn,r.mn);
	for(int i=0;i<10;++i){
		if(l.c[i]<inf&&r.c[i]<inf)u.mn=min(u.mn,l.c[i]+r.c[i]);
		u.c[i]=min(l.c[i],r.c[i]);
	}
}
void build(int i,int L,int R){
	if(L==R){
		for(int j=0;j<10;++j){
			if((a[L]/pw[j])%10)tree[i].c[j]=a[L];
		}
		return;
	}
	int mid=(L+R)>>1;
	build(ls,L,mid);
	build(rs,mid+1,R);
	update(tree[i],tree[ls],tree[rs]);
}
void Change(int i,int L,int R,int p){
	if(L==R){
		for(int j=0;j<10;++j){
			if((a[L]/pw[j])%10)tree[i].c[j]=a[L];
			else tree[i].c[j]=inf;
		}
		return;
	}
	int mid=(L+R)>>1;
	p<=mid?Change(ls,L,mid,p):Change(rs,mid+1,R,p);
	update(tree[i],tree[ls],tree[rs]);
}
node Query(int i,int L,int R,int l,int r){
	if(L>=l&&R<=r)return tree[i];
	int mid=(L+R)>>1;
	node ans;
	if(l<=mid&&r>mid)update(ans,Query(ls,L,mid,l,r),Query(rs,mid+1,R,l,r));
	else if(l<=mid)ans=Query(ls,L,mid,l,r);
	else ans=Query(rs,mid+1,R,l,r);
	return ans;
}
int main(){
	n=read(),Q=read();
	pw[0]=1;
	for(int i=1;i<=9;++i)pw[i]=pw[i-1]*10;
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	build(1,1,n);
	while(Q--){
		int opt=read();
		if(opt==1){
			int x=read();
			a[x]=read();
			Change(1,1,n,x);	
		}
		else{
			int l=read(),r=read();
			int ans=Query(1,1,n,l,r).mn;
			printf("%d\n",ans==(inf<<1)?-1:ans);
		}
	}
	return 0;
}