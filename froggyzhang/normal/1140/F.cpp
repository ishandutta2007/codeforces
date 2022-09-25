#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
const int n=3e5;
int Q;
map<pair<int,int>,int> mp;
vector<pair<int,int> > vec[N<<2];
ll ans;
class Union_Set{
	int f[N<<1],sz1[N<<1],sz2[N<<1];
public:
	vector<pair<int,int> > bin;
	void init(int n){
		for(int i=1;i<=(n<<1);++i){
			f[i]=i;(i<=n?sz1[i]:sz2[i])=1;
		}
	}
	inline int getf(int x){
		return f[x]==x?x:getf(f[x]);
	}
	inline void Merge(int x,int y){
		int fx=getf(x),fy=getf(y);
		if(fx==fy)return;
		if(sz1[fx]+sz2[fx]<sz1[fy]+sz2[fy])swap(fx,fy);
		bin.emplace_back(fx,fy);
		ans-=1LL*sz1[fx]*sz2[fx]+1LL*sz1[fy]*sz2[fy];
		f[fy]=fx;
		sz1[fx]+=sz1[fy];
		sz2[fx]+=sz2[fy];
		ans+=1LL*sz1[fx]*sz2[fx];
	}
	void Revoke(){
		auto [x,y]=bin.back();
		bin.pop_back();
		f[y]=y;
		ans-=1LL*sz1[x]*sz2[x];
		sz1[x]-=sz1[y];	
		sz2[x]-=sz2[y];
		ans+=1LL*sz1[x]*sz2[x]+1LL*sz1[y]*sz2[y];
	}
}S;
#define ls u<<1
#define rs u<<1|1
void Change(int u,int L,int R,int l,int r,auto t){
	if(L>=l&&R<=r){
		vec[u].emplace_back(t);
		return;
	}	
	int mid=(L+R)>>1;
	if(l<=mid)Change(ls,L,mid,l,r,t);
	if(r>mid)Change(rs,mid+1,R,l,r,t);
}
void dfs(int u,int L,int R){
	int jb=S.bin.size();
	for(auto [x,y]:vec[u]){
		S.Merge(x,y+n);	
	}
	if(L==R){
		cout<<ans<<' ';	
	}
	else{
		int mid=(L+R)>>1;
		dfs(ls,L,mid),dfs(rs,mid+1,R);	
	}
	while(S.bin.size()>jb){
		S.Revoke();
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>Q;
	S.init(n);
	for(int i=1;i<=Q;++i){
		int x,y;
		cin>>x>>y;
		auto t=make_pair(x,y);
		if(mp.count(t)){
			Change(1,1,Q,mp[t],i-1,t);
			mp.erase(t);
		}
		else{
			mp[t]=i;
		}
	}
	for(auto [t,z]:mp){
		Change(1,1,Q,z,Q,t);
	}
	dfs(1,1,Q);
	return 0;
}