#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const double inf=1e9;
int n,Q,X,Y,a[N];
struct Data{
	double g[3][3];  // 0, 1/(X+Y), 1/X
	Data(){
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				g[i][j]=-inf;
	}
	friend Data operator + (const Data &a,const Data &b){
		Data c;
		for(int i=0;i<3;++i){
			for(int j=0;j<3;++j){
				for(int k=0;k<3;++k){
					for(int l=0;k+l<3;++l){
						c.g[i][j]=max(c.g[i][j],a.g[i][k]+b.g[l][j]);
					}
				}
			}
		}
		return c;
	}
};
class Segment_Tree{
	int Len;
	struct node{
		Data d;
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
public:
	void build(int u,int L,int R){
		if(L==R){
			t[u].d.g[0][0]=0;
			t[u].d.g[1][1]=1.0*a[L]/(X+Y);
			t[u].d.g[2][2]=1.0*a[L]/X;
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		t[u].d=t[ls].d+t[rs].d;
	}
	void _ch(int u,int L,int R,int p){
		if(L==R){
			t[u].d.g[0][0]=0;
			t[u].d.g[1][1]=1.0*a[p]/(X+Y);
			t[u].d.g[2][2]=1.0*a[p]/X;
			return;
		}
		int mid=(L+R)>>1;
		p<=mid?_ch(ls,L,mid,p):_ch(rs,mid+1,R,p);
		t[u].d=t[ls].d+t[rs].d;
	}
	Data _query(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r){
			return t[u].d;
		}
		int mid=(L+R)>>1;
		if(l<=mid&&r>mid)return _query(ls,L,mid,l,r)+_query(rs,mid+1,R,l,r);
		if(l<=mid)return _query(ls,L,mid,l,r);
		return _query(rs,mid+1,R,l,r);
	}
public:
	void init(int _n){
		Len=_n;
		build(1,1,Len);
	}
	void Change(int p){
		_ch(1,1,Len,p);
	}
	Data Query(int l,int r){
		return _query(1,1,Len,l,r);
	}
}T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(10);
	cin>>n>>Q>>X>>Y;
	if(X<Y)swap(X,Y);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	T.init(n);
	while(Q--){
		int opt,x,y;
		cin>>opt>>x>>y;
		if(opt==1){
			a[x]=y;
			T.Change(x);
		}
		else{
			auto ans=T.Query(x,y);
			double mx=0;
			for(int i=0;i<3;++i)
				for(int j=0;j<3;++j)
					mx=max(mx,ans.g[i][j]);
			cout<<mx<<'\n';
		}
	}
	return 0;
}