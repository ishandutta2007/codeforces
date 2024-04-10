#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
const ll inf=1e18;
int n,m;
struct Point{
	int x,y;
	Point(int _x=0,int _y=0):x(_x),y(_y){}
}p[N][2];
inline int Dis(Point a,Point b){
	return abs(a.x-b.x)+abs(a.y-b.y);
}
struct Data{
	int l,r;
	ll g[2][2];
	friend Data operator + (const Data &a,const Data &b){
		Data c;
		c.l=a.l,c.r=b.r;
		for(int i=0;i<2;++i){
			for(int j=0;j<2;++j){
				c.g[i][j]=inf;
				for(int x=0;x<2;++x){
					for(int y=0;y<2;++y){
						c.g[i][j]=min(c.g[i][j],a.g[i][x]+b.g[y][j]+Dis(p[a.r][x],p[b.l][y])+2*(x!=y&&p[b.l][y].x!=p[b.l][y].y));
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
	void build(int u,int L,int R){
		if(L==R){
			t[u].d.l=L,t[u].d.r=R;
			t[u].d.g[0][1]=t[u].d.g[1][0]=inf;
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
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
	Data Query(int l,int r){
		return _query(1,1,Len,l,r);
	}
}T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<n;++i){
		cin>>p[i][0].x>>p[i][0].y>>p[i][1].x>>p[i][1].y;
	}
	T.init(n-1);
	cin>>m;
	for(int i=1;i<=m;++i){
		Point A,B;
		cin>>A.x>>A.y>>B.x>>B.y;
		if(max(A.x,A.y)>max(B.x,B.y))swap(A,B);
		int l=max(A.x,A.y),r=max(B.x,B.y);
		if(l==r){
			cout<<Dis(A,B)<<'\n';
		}
		else{
			Data tmp=T.Query(l,r-1);
			ll ans=inf;
			for(int i=0;i<2;++i){
				for(int j=0;j<2;++j){
					ans=min(ans,tmp.g[i][j]+Dis(p[l][i],A)+Dis(Point(p[r-1][j].x+(j==0),p[r-1][j].y+(j==1)),B)+1);
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}