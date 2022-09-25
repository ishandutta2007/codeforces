//
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>
#define fi first
#define se second
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

int n,q;
int arr[200005];
vector<ii> al[200005];
int d[200005];
ii tkd[200005][20];

void dfs(int i,int p){
	for (auto &it:al[i]){
		if (it.fi==p) continue;
		
		ii curr=tkd[it.fi][0]=ii(i,it.se);
		rep(x,0,20){
			if (curr.fi==-1) continue;
			curr=tkd[it.fi][x+1]=ii(tkd[curr.fi][x].fi,max(curr.se,tkd[curr.fi][x].se));
		}
		
		d[it.fi]=d[i]+1;
		dfs(it.fi,i);
	}
}

ii mov(int i,int j){
	ii res=ii(i,0);
	rep(x,0,20) if (j&(1<<x)){
		res.se=max(res.se,tkd[res.fi][x].se);
		res.fi=tkd[res.fi][x].fi;
	}
	
	return res;
}

int dist(int i,int j){
	if (d[i]<d[j]) swap(i,j);
	
	auto temp=mov(i,d[i]-d[j]);
	i=temp.fi;
	
	ll res=temp.se;
	
	if (i==j) return res;
	
	rep(x,20,0) if (tkd[i][x].fi!=tkd[j][x].fi){
		res=max({res,tkd[i][x].se,tkd[j][x].se});
		i=tkd[i][x].fi,j=tkd[j][x].fi;
	}
	
	return max({res,tkd[i][0].se,tkd[j][0].se});
}

struct UFDS{
	int p[200005];
	int s[200005];
	int w[200005];
	int mx[200005];
	
	UFDS(){
		rep(x,0,200005) p[x]=mx[x]=x;
		rep(x,0,200005) s[x]=1;
	}
	
	int parent(int i){
		if (i==p[i]) return i;
		else return p[i]=parent(p[i]);
	}
	
	void unions(int i,int j){
		i=parent(i),j=parent(j);
		
		p[i]=j;
		s[j]+=s[i];
		if (arr[mx[i]]>arr[mx[j]]){
			mx[j]=mx[i];
			w[j]=w[i];
		}
		if (arr[mx[i]]==arr[mx[j]]){
			w[j]=max({w[j],w[i],dist(mx[i],mx[j])});
		}
	}
} ufds;

vector<iii> edges;

struct Q{
	int c;
	int pos;
	int idx;
};
vector<Q> qu;
ii ans[200005];


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>q;
	rep(x,1,n+1) cin>>arr[x];
	
	int a,b,c,d;
	rep(x,1,n){
		cin>>a>>b>>c>>d;
		
		edges.pub(iii(c,ii(a,b)));
		al[a].pub(ii(b,d));
		al[b].pub(ii(a,d));
	}
	
	memset(tkd,-1,sizeof(tkd));
	dfs(1,-1);
	
	rep(x,0,q){
		cin>>a>>b;
		
		qu.pub(Q({a,b,x}));
	}
	
	edges.pub(iii(-1,ii(1,1)));
	
	sort(all(edges));
	reverse(all(edges));
	sort(all(qu),[](Q i,Q j){
		return i.c<j.c;
	});
	
	for (auto &it:edges){
		while (!qu.empty() && qu.back().c>it.fi){
			int temp=ufds.parent(qu.back().pos);
			ans[qu.back().idx]=ii(arr[ufds.mx[temp]],max(dist(qu.back().pos,ufds.mx[temp]),ufds.w[temp]));
			qu.pob();
		}
		
		ufds.unions(it.se.fi,it.se.se);
	}
	
	rep(x,0,q){
		cout<<ans[x].fi<<" "<<ans[x].se<<endl;
	}
}