#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,m,k,jb[N<<2],tot;
vector<pair<int,int> > vec[N],H;
vector<int> p[N];
class Chairman_Tree{
	int cnt;
	struct node{
		int mx,ch[2];
	}tree[N<<6];
public:
	int rt[N<<2];
	#define ls tree[u].ch[0]
	#define rs tree[u].ch[1]
	inline void update(int u){
		tree[u].mx=max(tree[ls].mx,tree[rs].mx);
	}
	void build(int &u,int L,int R){
		u=++cnt;
		if(L==R){
			tree[u].mx=p[L].empty()?inf:p[L].back();
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		update(u);
	}
	void Change(int pre,int &u,int L,int R,int p,int d){
		u=++cnt;
		tree[u]=tree[pre];
		if(L==R){
			tree[u].mx=max(tree[u].mx,d);
			return;
		}
		int mid=(L+R)>>1;
		p<=mid?Change(tree[pre].ch[0],ls,L,mid,p,d):Change(tree[pre].ch[1],rs,mid+1,R,p,d);
		update(u);
	}
	int Query(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r)return tree[u].mx;
		int mx=0;
		int mid=(L+R)>>1;
		if(l<=mid)mx=max(mx,Query(ls,L,mid,l,r));
		if(r>mid)mx=max(mx,Query(rs,mid+1,R,l,r));
		return mx;
	}
}T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=k;++i){
		int l,r,w;
		cin>>l>>r>>w;
		vec[w].emplace_back(l,r);		
	}
	for(int i=1;i<=n;++i){
		sort(vec[i].begin(),vec[i].end(),greater<pair<int,int> >());
		p[i].resize(vec[i].size());
		if(!p[i].empty()){
			p[i][0]=vec[i][0].second;
			for(auto [l,r]:vec[i]){
				H.emplace_back(l+1,i);
			}
			for(int j=1;j<(int)vec[i].size();++j){
				p[i][j]=min(vec[i][j].second,p[i][j-1]);
			}
		}
	}
	sort(H.begin(),H.end());
	T.build(T.rt[0],1,n);
	jb[0]=1;
	for(auto [z,u]:H){
		jb[++tot]=z;
		p[u].pop_back();
		T.Change(T.rt[tot-1],T.rt[tot],1,n,u,p[u].empty()?inf:p[u].back());
	}	
	while(m--){
		int a,b,x,y;
		cin>>a>>b>>x>>y;
		int u=upper_bound(jb,jb+tot+1,x)-jb-1;
		cout<<(T.Query(T.rt[u],1,n,a,b)<=y?"yes":"no")<<endl;
	}
	return 0;
}