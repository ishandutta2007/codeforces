#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200020
const int C=1e9;
class Segment_Tree{
	int rt,cnt;
	struct node{
		int mn,mx,add,ch[2];	
		inline void Add(int d){
			mn+=d,mx+=d,add+=d;
		}
	}t[N<<6];
	#define ls t[u].ch[0]
	#define rs t[u].ch[1]
	inline void update(int u){
		t[u].mn=min(t[ls].mn,t[rs].mn);
		t[u].mx=max(t[ls].mx,t[rs].mx);	
	}
	inline void pushdown(int u,int L,int R){
		int mid=(L+R)>>1;
		if(!ls){
			ls=++cnt;
			t[ls].mn=L,t[ls].mx=mid;
		}
		if(!rs){
			rs=++cnt;
			t[rs].mn=mid+1,t[rs].mx=R;
		}
		if(t[u].add){
			t[ls].Add(t[u].add);
			t[rs].Add(t[u].add);
			t[u].add=0;
		}
	}
	void _plus(int &u,int L,int R,int l,int r,int d){
		if(!u)u=++cnt,t[u].mx=R,t[u].mn=L;
		if(L>=l&&R<=r){
			t[u].Add(d);
			return;
		}
		pushdown(u,L,R);
		int mid=(L+R)>>1;
		if(l<=mid)_plus(ls,L,mid,l,r,d);
		if(r>mid)_plus(rs,mid+1,R,l,r,d);
		update(u);
	}
	int _query(int &u,int L,int R,int p){
		if(!u)u=++cnt,t[u].mx=R,t[u].mn=L;
		if(L==R)return t[u].mn;
		pushdown(u,L,R);
		int mid=(L+R)>>1;
		return p<=mid?_query(ls,L,mid,p):_query(rs,mid+1,R,p);	
	}
	int _findl(int &u,int L,int R,int lim){
		if(!u)u=++cnt,t[u].mx=R,t[u].mn=L;
		if(L==R)return t[u].mn<lim?L:L-1;
		pushdown(u,L,R);
		int mid=(L+R)>>1;
		return t[rs].mn<lim?_findl(rs,mid+1,R,lim):_findl(ls,L,mid,lim);
	}
	int _findr(int &u,int L,int R,int lim){
		if(!u)u=++cnt,t[u].mx=R,t[u].mn=L;
		if(L==R)return t[u].mn>lim?R:R+1;
		pushdown(u,L,R);
		int mid=(L+R)>>1;
		return t[ls].mx>lim?_findr(ls,L,mid,lim):_findr(rs,mid+1,R,lim);	
	}
public:
	void Plus(int l,int r,int d){
		if(l>r)return;
		_plus(rt,0,C,l,r,d);	
	}
	int Query(int p){
		return _query(rt,0,C,p);
	}
	int Findl(int x){
		return _findl(rt,0,C,x);	
	}
	int Findr(int x){
		return _findr(rt,0,C,x);	
	}
}T;
const int MOD=1e9+1;
int n;
void Solve(int t){
	int pl=T.Findl(t),pr=T.Findr(t);
	T.Plus(0,pl,1),T.Plus(pr,C,-1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int lastans=0;
	for(int i=1;i<=n;++i){
		int t,k;
		cin>>t>>k;
		Solve(t);
		while(k--){
			int x;
			cin>>x;
			x=(x+lastans)%MOD;
			cout<<(lastans=T.Query(x))<<'\n';	
		}
	}
	return 0;
}