#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
int n,Q,c[N];
char s[N];
class Segment_Tree{
	struct node{
		int AB,BA,A,B,ABA,add;
		inline void Add(int d){
			add+=d;
			A+=d,B-=2*d,AB-=d,BA-=d;
		}
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void update(int u){
		t[u].AB=max(max(t[ls].AB,t[rs].AB),t[ls].A+t[rs].B);
		t[u].BA=max(max(t[ls].BA,t[rs].BA),t[ls].B+t[rs].A);
		t[u].ABA=max(max(t[ls].ABA,t[rs].ABA),max(t[ls].AB+t[rs].A,t[ls].A+t[rs].BA));
		t[u].A=max(t[ls].A,t[rs].A);
		t[u].B=max(t[ls].B,t[rs].B);	
	}
	inline void pushdown(int u){
		if(t[u].add){
			t[ls].Add(t[u].add);
			t[rs].Add(t[u].add);
			t[u].add=0;
		}	
	}
public:
	void build(int u,int L,int R){
		if(L==R){
			t[u].ABA=0;
			t[u].AB=t[u].BA=-c[L];
			t[u].A=c[L],t[u].B=-2*c[L];
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		update(u);
	}
	void Change(int u,int L,int R,int l,int r,int d){
		if(L>=l&&R<=r){
			t[u].Add(d);
			return;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid)Change(ls,L,mid,l,r,d);
		if(r>mid)Change(rs,mid+1,R,l,r,d);
		update(u);	
	}
	inline int get_ans(){
		return t[1].ABA;	
	}
}T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	cin>>(s+1);
	for(int i=1;i<=(n-1)<<1;++i){
		c[i]=c[i-1]+(s[i]=='('?1:-1);	
	}
	T.build(1,1,(n-1)<<1);
	cout<<T.get_ans()<<'\n';
	while(Q--){
		int x,y;
		cin>>x>>y;
		if(s[x]==s[y])continue;
		if(x>y)swap(x,y);
		T.Change(1,1,(n-1)<<1,x,y-1,s[x]=='('?-2:2);
		cout<<T.get_ans()<<'\n';
		swap(s[x],s[y]);
	}
	return 0;
}