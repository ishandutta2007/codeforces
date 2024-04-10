#include<bits/stdc++.h>
using namespace std;
#define N 500020
typedef long long ll;
int n,Q;
char a[N];
struct Data{
	int _l,_r,len,mx,tl,tr;
	Data(){_l=_r=mx=len=tl=tr=0;}
	friend Data operator + (const Data &a,const Data &b){
		Data c;
		c._l=a._l+(a._l==a.len?b._l:0);
		c._r=b._r+(b._r==b.len?a._r:0);	
		c.mx=max(max(a.mx,b.mx),max(a.tr+b._l,a._r+b.tl));
		c.tl=a._r==a.len?a.len+b.tl:(a.mx==a.len?a.mx+b._l:a.tl);
		c.tr=b._l==b.len?b.len+a.tr:(b.mx==b.len?b.mx+a._r:b.tr);
		c.len=a.len+b.len;
		return c;
	}
};
class Segment_Tree{
	struct node{
		Data a,b;
		int rev;
		void Rev(){
			swap(a,b);
			rev^=1;
		}
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void pushdown(int u){
		if(t[u].rev){
			t[ls].Rev();
			t[rs].Rev();
			t[u].rev=0;
		}
	}
public:
	inline void update(int u){
		t[u].a=t[ls].a+t[rs].a;
		t[u].b=t[ls].b+t[rs].b;
	}
	void build(int u,int L,int R){
		if(L==R){
			t[u].a.len=t[u].b.len=t[u].a.tl=t[u].a.tr=t[u].b.tl=t[u].b.tr=t[u].a.mx=t[u].b.mx=1;
			t[u].a._l=t[u].b._r=a[L]=='<';
			t[u].a._r=t[u].b._l=a[L]=='>';
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		update(u);
	}
	Data Query(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r){
			t[u].Rev();
			return t[u].a;
		}
		int mid=(L+R)>>1;
		pushdown(u);
		Data ans;
		if(l<=mid)ans=ans+Query(ls,L,mid,l,r);
		if(r>mid)ans=ans+Query(rs,mid+1,R,l,r);
		update(u);
		return ans;
	}
}T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	cin>>(a+1);
	T.build(1,1,n);
	while(Q--){
		int l,r;
		cin>>l>>r;
		cout<<T.Query(1,1,n,l,r).mx<<'\n';
	}
	return 0;
}