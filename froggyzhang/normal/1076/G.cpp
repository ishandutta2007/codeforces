#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
typedef array<int,32> A32;
int n,Q,m;
bool a[N];
A32 operator + (const A32 &a,const A32 &b){
	A32 c;
	for(int i=0;i<(1<<m);++i)c[i]=a[b[i]];
	return c;
}
class Segment_Tree{
	struct node{
		A32 a[2];
		int rev;
		inline void Rev(){
			swap(a[0],a[1]);
			rev^=1;
		}
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void update(int u){
		t[u].a[0]=t[ls].a[0]+t[rs].a[0];
		t[u].a[1]=t[ls].a[1]+t[rs].a[1];
	}
	inline void pushdown(int u){
		if(t[u].rev){
			t[ls].Rev();
			t[rs].Rev();
			t[u].rev=0;
		}	
	}
public:
	void build(int u,int L,int R){
		if(L==R){
			for(int i=0;i<(1<<m);++i){
				for(int j=0;j<2;++j){
					t[u].a[j][i]=((i<<1)&((1<<m)-1))|((a[L]^j)&&!i);
				}
			}
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		update(u);
	}
	void Reverse(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r){
			t[u].Rev();
			return;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid)Reverse(ls,L,mid,l,r);
		if(r>mid)Reverse(rs,mid+1,R,l,r);
		update(u);
	}
	A32 Query(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r){
			return t[u].a[0];
		}
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid&&r>mid)return Query(ls,L,mid,l,r)+Query(rs,mid+1,R,l,r);
		if(l<=mid)return Query(ls,L,mid,l,r);
		return Query(rs,mid+1,R,l,r);
	}
}T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>Q;
	for(int i=1;i<=n;++i){
		ll x;
		cin>>x;
		a[i]=x&1;
	}
	T.build(1,1,n);
	while(Q--){
		int opt,l,r;
		cin>>opt>>l>>r;
		if(opt==1){
			ll d;
			cin>>d;
			if(d&1)T.Reverse(1,1,n,l,r);
		}
		else{
			cout<<(T.Query(1,1,n,l,r)[0]&1)+1<<'\n';	
		}
	}
	return 0;
}