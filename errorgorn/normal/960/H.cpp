// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

struct dat{
	int a=0,b=0,c=0;
};

dat merge(dat i,dat j){
	return {
		i.a+j.a,
		i.a*j.c+i.b+j.b,
		i.c+j.c
	};
}

struct node{
	int s,e,m;
	int val1=0,val2=0;
	int len=0;
	dat lazy;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void propo(){
		if (lazy.a==0 && lazy.b==0 && lazy.c==0) return;
		
		val1=val1+val2*lazy.a+len*lazy.b;
		val2=val2+len*lazy.c;
		
		if (s!=e){
			l->lazy=merge(l->lazy,lazy);
			r->lazy=merge(r->lazy,lazy);
		}
		
		lazy={0,0,0};
	}
	
	void update_len(int i,int k){
		len+=k;
		if (s==e) return;
		if (i<=m) l->update_len(i,k);
		else r->update_len(i,k);
	}
	
	void update(int i,int j,dat k){
		propo();
		if (s==i && e==j) lazy=k;
		else{
			if (j<=m) l->update(i,j,k);
			else if (m<i) r->update(i,j,k);
			else l->update(i,m,k),r->update(m+1,j,k);
			
			l->propo(),r->propo();
			val1=l->val1+r->val1;
			val2=l->val2+r->val2;
		}
	}
	
	ii query(int i,int j){
	    propo();
	    
		if (s==i && e==j) return {val1,val2};
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else{
			auto r1=l->query(i,m),r2=r->query(m+1,j);
			return {r1.fi+r2.fi,r1.se+r2.se};
		}
	}
} *root=new node(0,200005);

int n,m,q,C;
int typ[50005];
vector<int> al[50005];
int cost[50005];

int in[50005];
int out[50005];
vector<int> pos[50005];
int d[50005];
int tkd[50005][17];
int _TIME=0;

void dfs(int i){
	in[i]=++_TIME;
	for (auto it:al[i]){
		d[it]=d[i]+1;
		int curr=tkd[it][0]=i;
		rep(x,0,16){
			if (curr==-1) break;
			curr=tkd[it][x+1]=tkd[curr][x];
		}
		dfs(it);
	}
	out[i]=_TIME;
}

int mov(int i,int j){
	rep(x,0,17) if (j&(1<<x)) i=tkd[i][x];
	return i;
}

int lca(int i,int j){
	if (d[i]<d[j]) swap(i,j);
	i=mov(i,d[i]-d[j]);
	if (i==j) return i;
	
	rep(x,17,0) if (tkd[i][x]!=tkd[j][x]){
		i=tkd[i][x],j=tkd[j][x];
	}
	return tkd[i][0];
}

vector<int> al2[50005];
map<int,int> in2[50005];
int ss[50005];

int pp[200005];
int hp[200005];

void dfs_sz(int i){
	ss[i]=1;
	for (auto &it:al2[i]){
		dfs_sz(it);
		ss[i]+=ss[it];
		if (ss[al2[i][0]]<ss[it]) swap(al2[i][0],it);
	}
}

void dfs_hld(int i,int depth,int r){
	in2[r][i]=_TIME++;
	//cout<<"len: "<<r<<" "<<i<<" "<<d[i]-depth<<endl;
	root->update_len(in2[r][i],d[i]-depth);
	
	for (auto it:al2[i]){
		pp[_TIME]=in2[r][i];
		if (it==al2[i][0]) hp[_TIME]=hp[in2[r][i]];
		else hp[_TIME]=_TIME;
		
		dfs_hld(it,d[i],r);
	}
}

void add(int i,int k){
	i=in2[typ[i]][i];
	
	while (i!=-1){
		if (k==1) root->update(hp[i],i,{2,1,1});
		else root->update(hp[i],i,{-2,1,-1});
		i=pp[hp[i]];
	}
}

struct Q{
	int typ;
	int a,b;
};

Q qu[50005];

ii range[50005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m>>q>>C;
	rep(x,1,n+1){
		cin>>typ[x];
		pos[typ[x]].pub(x);
	}
	
	int a;
	rep(x,2,n+1){
		cin>>a;
		al[a].pub(x);
	}
	
	rep(x,1,m+1) cin>>cost[x];
	
	rep(x,0,q){
		cin>>qu[x].typ;
		if (qu[x].typ==1){
			cin>>qu[x].a>>qu[x].b;
			pos[qu[x].b].pub(qu[x].a);
		}
		else{
			cin>>qu[x].a;
		}
	}
	
	memset(tkd,-1,sizeof(tkd));
	dfs(1);
	
	// rep(x,1,n+1) cout<<in[x]<<" "; cout<<endl;
	// rep(x,1,n+1) cout<<out[x]<<" "; cout<<endl;
	
	_TIME=0;
	
	memset(range,-1,sizeof(range));
	
	rep(x,1,m+1) if (!pos[x].empty()){
		sort(all(pos[x]),[](int i,int j){
			return in[i]<in[j];
		});
		
		int sz=sz(pos[x]);
		rep(y,0,sz-1) pos[x].pub(lca(pos[x][y],pos[x][y+1]));
		
		sort(all(pos[x]),[](int i,int j){
			return in[i]<in[j];
		});
		pos[x].erase(unique(all(pos[x])),pos[x].end());
		
		vector<int> stk;
		for (auto it:pos[x]){
			al2[it].clear();
			
			if (!stk.empty()){
				while (out[stk.back()]<in[it]) stk.pob();
				al2[stk.back()].pub(it);
			}
			stk.pub(it);
		}
		
		range[x].fi=_TIME;
		pp[_TIME]=-1;
		hp[_TIME]=_TIME;
		dfs_sz(pos[x][0]);
		dfs_hld(pos[x][0],-1,x);
		
		// for (auto it:pos[x]) cout<<it<<" "; cout<<endl;
		// for (auto it:pos[x]) cout<<in2[x][it]<<" "; cout<<endl;
		// for (auto it:pos[x]) cout<<pp[in2[x][it]]<<" "; cout<<endl;
		// for (auto it:pos[x]) cout<<hp[in2[x][it]]<<" "; cout<<endl;
		// cout<<endl;
		
		range[x].se=_TIME-1;
	}
	
	rep(x,1,n+1) add(x,1);
	
	rep(x,0,q){
		if (qu[x].typ==2){
			int val1=0,val2=0;
			
			if (range[qu[x].a]!=ii(-1,-1)){
				tie(val1,val2)=root->query(range[qu[x].a].fi,range[qu[x].a].se);
			}
			
			int cc=cost[qu[x].a];
			double ans=(double)n*C*C-(double)2*C*cc*val2+(double)cc*cc*val1;
			cout<<fixed<<setprecision(12)<<(double)ans/n<<endl;
		}
		else{
			add(qu[x].a,-1);
			typ[qu[x].a]=qu[x].b;
			add(qu[x].a,1);
		}
	}
}