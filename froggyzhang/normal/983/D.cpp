#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
typedef pair<int,int> pii;
int ans,n;
int bx[N],lenx,by[N],leny;
vector<pii> q[N];
bool vis[N];
struct Rec{
	int x1,y1,x2,y2;
}a[N];
class Segment_Tree{
	struct node{
		int mx,mn;
		set<int> s;
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void update(int u,int leaf){
		if(leaf)t[u].mx=t[u].mn=0;
		else t[u].mx=max(t[ls].mx,t[rs].mx),t[u].mn=min(t[ls].mn,t[rs].mn);
		if(!t[u].s.empty()){
			int jb=*t[u].s.rbegin();
			if(vis[jb]){
				t[u].mn=max(t[u].mn,jb);
			}
			else{
				t[u].mx=max(t[u].mx,jb);
			}
		}
		if(t[u].mx<t[u].mn){
			t[u].mx=0;
		}
	}
public:
	void Change(int u,int L,int R,int l,int r,int id,int w){
		if(L>=l&&R<=r){
			if(w){
				if(w>0)t[u].s.insert(id);
				else t[u].s.erase(id);
			}
			update(u,L==R);
			return;
		}
		int mid=(L+R)>>1;
		if(l<=mid)Change(ls,L,mid,l,r,id,w);
		if(r>mid)Change(rs,mid+1,R,l,r,id,w);
		update(u,0);
	}
	int get_max(){
		return t[1].mx;
	}
}T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
		bx[++lenx]=a[i].x1;
		bx[++lenx]=a[i].x2;
		by[++leny]=a[i].y1;
		by[++leny]=a[i].y2;
	}
	sort(bx+1,bx+lenx+1);
	sort(by+1,by+leny+1);
	lenx=unique(bx+1,bx+lenx+1)-bx-1;
	leny=unique(by+1,by+leny+1)-by-1;
	for(int i=1;i<=n;++i){
		a[i].x1=lower_bound(bx+1,bx+lenx+1,a[i].x1)-bx;
		a[i].x2=lower_bound(bx+1,bx+lenx+1,a[i].x2)-bx;
		a[i].y1=lower_bound(by+1,by+leny+1,a[i].y1)-by;
		a[i].y2=lower_bound(by+1,by+leny+1,a[i].y2)-by;
		q[a[i].x1].emplace_back(i,1);
		q[a[i].x2].emplace_back(i,-1);
	}
	for(int i=1;i<=lenx;++i){
		for(auto [u,op]:q[i]){
			T.Change(1,1,leny,a[u].y1,a[u].y2-1,u,op);
		}
		int mx;
		while(mx=T.get_max()){
			vis[mx]=1;++ans;
			T.Change(1,1,leny,a[mx].y1,a[mx].y2-1,mx,0);
		}
	}
	cout<<ans+1<<'\n';
	return 0;
}