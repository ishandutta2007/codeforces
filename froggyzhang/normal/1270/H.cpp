#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
const int C=1000000;
int n,Q,a[N];
struct Data{
	int mn,cnt;
	Data(){mn=0;cnt=0;}
	friend Data operator + (const Data &a,const Data &b){
		Data c;
		c.mn=min(a.mn,b.mn);
		c.cnt=(a.mn==c.mn)*a.cnt+(b.mn==c.mn)*b.cnt;
		return c;	
	}	
};
class Segment_Tree{
	struct node{
		Data p;
		int add;
		inline void Add(int d){
			add+=d;
			p.mn+=d;
		}
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void update(int u){
		t[u].p=t[ls].p+t[rs].p;
	}
	inline void pushdown(int u){
		if(t[u].add){
			t[ls].Add(t[u].add);
			t[rs].Add(t[u].add);
			t[u].add=0;
		}
	}
public:
	void Plus(int u,int L,int R,int l,int r,int d){
		if(L>=l&&R<=r){
			t[u].Add(d);
			return;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid)Plus(ls,L,mid,l,r,d);
		if(r>mid)Plus(rs,mid+1,R,l,r,d);
		update(u);
	}
	void Change(int u,int L,int R,int x,int d){
		if(L==R){
			t[u].p.cnt+=d;
			return;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		x<=mid?Change(ls,L,mid,x,d):Change(rs,mid+1,R,x,d);
		update(u);
	}
	int get_ans(){
		return t[1].p.cnt;
	}
}T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	a[0]=C+1,a[n+1]=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n+1;++i){
		if(a[i]<a[i-1]){
			T.Plus(1,0,C,a[i],a[i-1]-1,1);
		}	
	}
	for(int i=1;i<=n;++i){
		T.Change(1,0,C,a[i],1);
	}
	while(Q--){
		int i;
		cin>>i;
		T.Change(1,0,C,a[i],-1);
		if(a[i]<a[i-1])T.Plus(1,0,C,a[i],a[i-1]-1,-1);
		if(a[i]>a[i+1])T.Plus(1,0,C,a[i+1],a[i]-1,-1);
		cin>>a[i];
		T.Change(1,0,C,a[i],1);	
		if(a[i]<a[i-1])T.Plus(1,0,C,a[i],a[i-1]-1,1);
		if(a[i]>a[i+1])T.Plus(1,0,C,a[i+1],a[i]-1,1);
		cout<<T.get_ans()<<'\n';
	}
	return 0;
}